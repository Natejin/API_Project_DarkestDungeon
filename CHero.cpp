#include "framework.h"
#include "CHero.h"
#include "CParty.h"
#include "DungeonScene.h"

CHero::CHero() {
	unitType = UNITTYPE::Hero;
	m_layer = LAYER::Player;
	speedFront = 8;
	speedBack = 4;
}
CHero::~CHero() {}

HRESULT CHero::Init(JOB job, int resist[], int HP, int SPD, int POS, int DMG, int ACRY, int CRI, int DEF, int DODGE)
{
	canTriggerDown = false;
	
	this->job = job;
	m_HP = HP;
	m_SPD = SPD;
	m_POS = POS;
	//skill

	m_DMG = DMG;
	m_ACRY = ACRY;
	m_CRI = CRI;
	m_DEF = DEF;
	m_DODGE = DODGE;

	m_LVL = 1;
	m_EXP = 0;
	m_STRS = 0;
	m_STRSLVL = 0;

	limit = 0;

	for (size_t i = 0; i < 5; i++)
	{
		this->resist[i] = resist[i];
	}
	for (size_t i = 0; i < 8; i++)
	{
		attribute[i] = false;
	}

	m_DIST = 0;
	isActive = false;
	m_transform->m_pivot = Vector2(0.5, 1);

	isSelected = false; 
	isBattle = false;
	
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


UNITTYPE CHero::GetUnitType()
{
	return info->unitType;
}
int CHero::GetSpeed()
{
	return m_SPD;
}
void CHero::SetPosition(int pos)
{
	m_POS = pos;
}
int CHero::GetPosition()
{
	return m_POS;
}
int CHero::getPartyPos()
{
	return m_POS;
}
int CHero::getResist(int index)
{
	return resist[index];
}
bool CHero::getAttribute(int index)
{
	return attribute[index];
}
void CHero::setHP(int hp)
{
	m_HP = hp;
}
void CHero::setSPD(int spd)
{
	m_SPD = spd;
}
void CHero::setPartyPos(int pos)
{
	m_POS = pos;
}
void CHero::setResist(int index, bool val)
{
	resist[index] = val;
}
void CHero::setAttribute(int index, bool val)
{
	attribute[index] = val;
}
int CHero::getSPD()
{
	return m_SPD;
}
int CHero::getHP()
{
	return m_HP;
}