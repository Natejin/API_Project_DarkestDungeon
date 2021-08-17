#include "framework.h"
#include "CHero.h"
#include "CParty.h"
#include "DungeonScene.h"

CHero::CHero() {

	m_unitType = UNITTYPE::Hero;
	m_layer = LAYER::Player;
	speedFront = 8; //8
	speedBack = 4; //4
	weaponLvl = 0;
	armorLvl = 0;
}
CHero::~CHero() {}

HRESULT CHero::Init(Info_Hero* _info)
{
	canTriggerDown = false;
	m_unitType = _info->unitType;
	info = _info;
	AddAnimator(_info->imageIdle);
	m_animator->SetAnimeSpeed(5);
	m_animator->AddImageFrame(_info->imageWalk);
	m_animator->AddImageFrame(_info->imageCombat);

	SetMemberOverlay();
	AddColliderBox(120, 300);
	return S_OK;
}

void CHero::Update(float deltaTime, float worldTime)
{
	Unit::Update(deltaTime, worldTime);
	testHpBar();
}

void CHero::LateUpdate()
{
}

void CHero::BackRender(HDC _hdc)
{
}

void CHero::Render(HDC _hdc)
{
	m_animator->FrameRender(_hdc);
}

void CHero::FrontRender(HDC _hdc)
{
	Unit::FrontRender(_hdc);

	if (isTargetHeal)
	{
		targeted_h_Mem.m_trans.m_pos = Vector2(
			m_transform->m_pos.x - 87,
			m_transform->m_pos.y - 78);

		targeted_h_Mem.Render(_hdc);
	}

	showStrsBar(_hdc);
}

void CHero::Release()
{
	Unit::Release();
	MG_INFO->RemoveInfo(info);
}

IMAGE CHero::GetArmor()
{
	return info->GetArmor(armorLvl);
}

IMAGE CHero::GetWeapon()
{
	return info->GetWeapon(weaponLvl);
}

Image* CHero::GetTrinketL()
{
	return nullptr;
}

Image* CHero::GetTrinketR()
{
	return nullptr;
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
		if (info->m_STRS >= (i + 1) * 10)
		{
			if (info->m_STRS == 0) continue;
			STRSbar[i].m_img = MG_IMAGE->findImage("STRS_full");
		}
		STRSbar[i].m_trans.m_pos = Vector2(
			m_transform->m_pos.x - 50 + 10 * i,
			m_transform->m_pos.y + 30);
		STRSbar[i].m_img->render(_hdc, &STRSbar[i].m_trans);
	}
}

void CHero::SetMemberOverlay()
{
	Unit::SetMemberOverlay();
	targeted_h_Mem.m_img = MG_IMAGE->findImage(IMAGE::Target_Heal1);

	ImageData temp;
	temp.m_img = MG_IMAGE->findImage("STRS_empty");
	for (int i = 0; i < 10; i++)
	{
		STRSbar.push_back(temp);
	}
}

Info_Hero* CHero::GetInfo()
{
	return info;
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
	return info->m_STRS;
}

void CHero::setStress(int strs)
{
	info->m_STRS = strs;
}

void CHero::addStress(int strs)
{
	info->m_STRS += strs;
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

bool CHero::GetAffliction()
{
	return info->isAffliction;
}

bool CHero::GetAlive()
{
	return info->isAlive;
}

void CHero::testHpBar()
{

	if (MG_INPUT->IsDownLMB())
	{
		reduceHP(1);
	}
}

UNITTYPE CHero::GetUnitType()
{
	return info->unitType;
}
int CHero::GetSpeed()
{
	return info->m_SPD;
}
//void CHero::SetPartyIndex(int pos)
//{
//	m_partyIndex = pos;
//}
//int CHero::GetPartyIndex()
//{
//	return  m_partyIndex;
//}
//
//void CHero::SetPartyPos(int pos)
//{
//	m_partyPos = pos;
//}
//
//int CHero::GetPartyPos()
//{
//	return  m_partyPos;
//}

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

bool CHero::reduceHP(int hp)
{
	if (info->m_HP - hp > 0)
	{
		info->m_HP -= hp;
		return true;
	}
	else {
		info->m_HP = 0;
		info->isAlive = false;
		return false;
	}
}

void CHero::increaseHP(int hp)
{
	info->m_HP += hp;
}

int CHero::getMaxHP()
{
	return  info->m_maxHP;
}