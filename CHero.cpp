#include "framework.h"
#include "CHero.h"
#include "CParty.h"
#include "DungeonScene.h"

CHero::CHero() {

	m_layer = LAYER::Player;
	speedFront = 8;
	speedBack = 4;
}
CHero::~CHero() {}

//HRESULT CHero::Init(JOB job, int resist[], int HP, int SPD, int POS, int DMG, int ACRY, int CRI, int DEF, int DODGE)
//{
//	canTriggerDown = false;
//	
//	this->info->job = job;
//	info->m_HP = HP;
//	info->m_SPD = SPD;
//
//	//skill
//
//	info->m_DMG = DMG;
//	info->m_ACRY = ACRY;
//	info->m_CRI = CRI;
//	info->m_DEF = DEF;
//	info->m_DODGE = DODGE;
//
//	info->m_LVL = 1;
//	info->m_EXP = 0;
//	info->m_STRS = 0;
//	info->m_STRSLVL = 0;
//
//	limit = 0;
//
//	for (size_t i = 0; i < 5; i++)
//	{
//		this->info->resist[i] = resist[i];
//	}
//	for (size_t i = 0; i < 8; i++)
//	{
//		info->attribute[i] = false;
//	}
//
//	info->m_DIST = 0;
//	isActive = false;
//	m_transform->m_pivot = Vector2(0.5, 1);
//
//	isSelected = false; 
//	isBattle = false;
//	
//	SetMemberOverlay();
//	AddColliderBox(120, 300);
//
//	
//
//	return S_OK;
//}

HRESULT CHero::Init(Info_Hero* _info)
{
	canTriggerDown = false;

	
	info = new Info_Hero();
	info->unitType = _info->unitType;
	info->m_HP = _info->m_HP;
	info->m_SPD = _info->m_SPD;
	for (size_t i = 0; i < 5; i++)
	{
		this->info->resist[i] = _info->resist[i];
	}
	for (size_t i = 0; i < 8; i++)
	{
		info->attribute[i] = false;
	}
	
	AddAnimator(_info->imageIdle);
	m_animator->SetAnimeSpeed(5);
	m_animator->AddImageFrame(_info->imageWalk);
	m_animator->AddImageFrame(_info->imageCombat);
	for (size_t i = 0; i < _info->ownSkill.size(); i++)
	{
		info->ownSkill.push_back(_info->ownSkill[i]);
	}


	//hero
	info->job = _info->job;
	info->m_DMG = _info->m_DMG;
	info->m_ACRY = _info->m_ACRY;
	info->m_CRI = _info->m_CRI;
	info->m_DEF = _info->m_DEF;
	info->m_DODGE = _info->m_DODGE;
	info->ownSkill = _info->ownSkill;


	m_LVL = 1;
	m_EXP = 0;
	m_STRS = 0;
	m_STRSLVL = 0;
	SetMemberOverlay();
	AddColliderBox(120, 300);
	return S_OK;
}

void CHero::Update(float deltaTime, float worldTime)
{
	Unit::Update(deltaTime, worldTime);
}

void CHero::LateUpdate()
{
}

void CHero::BackRender(HDC _hdc)
{
	//m_animator->FrameRender(_hdc);
}

void CHero::Render(HDC _hdc)
{
	//m_image->frameRender(_hdc, m_transform);

	m_animator->FrameRender(_hdc);
}

void CHero::FrontRender(HDC _hdc)
{
	Unit::FrontRender(_hdc);

	showStrsBar(_hdc);

	////for test collision
	//ImageData temp;
	//temp.m_img = MG_IMAGE->findImage("memberRect");
	//temp.m_trans. m_pos = Vector2(
	//	m_transform->m_pos.x - m_animator->GetCurImage()->getFrameWidth() / 2 + 10,
	//	m_transform->m_pos.y - m_animator->GetCurImage()->getFrameHeight() / 2 + 70);
	//temp.m_img->render(_hdc, &temp.m_trans);
}

void CHero::Release()
{
	Unit::Release();
}

void CHero::Move()
{
	int ran;
	bool left = MG_INPUT->isStayKeyDown(VK_LEFT);
	bool right = MG_INPUT->isStayKeyDown(VK_RIGHT);
	if (left | right)
	{
		if (right)
		{
			if (m_transform->m_pos.x < MG_CAMERA->GetWorldSize().x - 200)
			{
				m_transform->m_pos.x += speedFront;
				m_DIST += speedFront;
			}
		}

		else if (left)
		{
			if (m_transform->m_pos.x > 0)
			{
				m_transform->m_pos.x -= speedBack;
				m_DIST += 2;
				m_DIST_retreat += speedBack;
				
				if (m_DIST_retreat > limit && m_DIST_retreat > 300)
				{
					if (MG_RND->getInt(4) > 2)
					{
						addStress(5);
					}
					limit += 300;
				}
			}
		}
		m_animator->SetIndex(1);
	}
	else 
	{
		m_animator->SetIndex(0);
	}
}

bool CHero::PreventGetOutBg(int startX, int endX)
{
	if (m_transform->m_pos.x < endX - 200 && 0 < m_transform->m_pos.x) 
		return true;
	else 
		return false;
}

void CHero::showStrsBar(HDC _hdc)
{
	for (int i = 0; i < 10; i++)
	{
		if (m_STRS >= (i + 1) * 10)
		{
			if (m_STRS == 0) continue;
			STRSbar[i].m_img = MG_IMAGE->findImage("STRS_full");
		}
		STRSbar[i].m_trans.m_pos = Vector2(
			m_transform->m_pos.x - 50 + 10 * i,
			m_transform->m_pos.y + 30);
		STRSbar[i].m_img->render(_hdc, &STRSbar[i].m_trans);
	}
}

#pragma region skill
void CHero::useSkill1()
{
}

void CHero::useSkill2()
{
}

void CHero::useSkill3()
{
}

void CHero::useSkill4()
{
}

void CHero::useMoveSkill()
{
}

void CHero::usePassTrun()
{
}
#pragma endregion

void CHero::setHpBar()
{
}

void CHero::setSTRSbar()
{
}

void CHero::setSelectedMem()
{
}

void CHero::setTargetedMem()
{
}

void CHero::SetMemberOverlay()
{
	Unit::SetMemberOverlay();
	selectedMem.m_img = MG_IMAGE->findImage("selected1");
	ImageData temp;
	temp.m_img = MG_IMAGE->findImage("STRS_empty");
	for (int i = 0; i < 10; i++)
	{
		STRSbar.push_back(temp);
	}
}

int CHero::getMoveDis() const
{
	return m_DIST;
}

int CHero::getMoveDis_reteat() const
{
	return m_DIST_retreat;
}

int CHero::getStress() const
{
	return m_STRS;
}

void CHero::setStress(int strs)
{
	m_STRS = strs;
}

void CHero::addStress(int strs)
{
	m_STRS += strs;
}

vector<SKILL> CHero::GetOwnSkill()
{
	return info->ownSkill;
}

void CHero::SetHeroID(int id)
{
	heroID = id;
}

int CHero::GetHeroID()
{
	return heroID;
}

void CHero::SetHeroJob(JOB job)
{
	info->job = job;
}

JOB CHero::GetJob()
{
	return info->job;
}

void CHero::SetOwnIndex(int _ownindex)
{
	ownIndex = _ownindex;
}

int CHero::GetOwnIndex()
{
	return ownIndex;
}

void CHero::SetAcry(int _acry)
{
	info->m_ACRY = _acry;
}

int CHero::GetAcry()
{
	return info->m_ACRY;
}

void CHero::SetCri(int _cri)
{
	info->m_CRI = _cri;
}

int CHero::GetCri()
{
	return info->m_CRI;
}

void CHero::SetDmg(int _dmg)
{
	info->m_DMG = _dmg;
}

int CHero::GetDmg()
{
	return info->m_DMG;
}

void CHero::SetDodge(int _dodge)
{	
	info->m_DODGE = _dodge;
}

int CHero::GetDodge()
{
	return info->m_DODGE;
}

void CHero::SetDef(int _def)
{
	info->m_DEF = _def;
}

int CHero::GetDef()
{
	return info->m_DEF;
}



UNITTYPE CHero::GetUnitType()
{
	return info->unitType;
}
int CHero::GetSpeed()
{
	return info->m_SPD;
}
void CHero::SetPartyIndex(int pos)
{
	m_partyIndex = pos;
}
int CHero::GetPartyIndex()
{
	return  m_partyIndex;
}
int CHero::getPartyPos()
{
	return  m_partyPos;
}
int CHero::getResist(int index)
{
	return  info->resist[index];
}
bool CHero::getAttribute(int index)
{
	return  info->attribute[index];
}
void CHero::setHP(int hp)
{
	info->m_HP = hp;
}
void CHero::setSPD(int spd)
{
	info->m_SPD = spd;
}
void CHero::setPartyPos(int pos)
{
	m_partyPos = pos;
}
void CHero::setResist(int index, bool val)
{
	info->resist[index] = val;
}
void CHero::setAttribute(int index, bool val)
{
	info->attribute[index] = val;
}
int CHero::getSPD()
{
	return  info->m_SPD;
}
int CHero::getHP()
{
	return  info->m_HP;
}