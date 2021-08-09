#include "framework.h"
#include "CHero.h"
#include "CParty.h"
#include "DungeonScene.h"

CHero::CHero() {
	unitType = UNITTYPE::Hero;
}
CHero::~CHero() {}

HRESULT CHero::Init(JOB job, int resist[], int HP, int SPD, int POS, int DMG, int ACRY, int CRI, int DEF, int DODGE)
{
	m_layer = LAYER::Player;
	
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
	//m_image = MG_IMAGE->findImage(img);

	isSelected = false; 
	isBattle = false;
	
	setMemberOverlay();

	return S_OK;
}

void CHero::Update(float deltaTime, float worldTime)
{
	
}

void CHero::LateUpdate()
{
}

void CHero::BackRender(HDC _hdc)
{
}

void CHero::Render(HDC _hdc)
{
	//m_image->frameRender(_hdc, m_transform);
	m_animator->FrameRender(_hdc);

}

void CHero::FrontRender(HDC _hdc)
{
	if (isSelected == true)
	{
		showSelMember(_hdc);
	}
	showHpStrsBar(_hdc);

	//for test collision
	ImageData temp;
	temp.m_img = MG_IMAGE->findImage("memberRect");
	temp.m_trans. m_pos = Vector2(
		m_transform->m_pos.x - m_animator->GetCurImage()->getFrameWidth() / 2 + 10,
		m_transform->m_pos.y - m_animator->GetCurImage()->getFrameHeight() / 2 + 70);
	temp.m_img->render(_hdc, &temp.m_trans);
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
				m_transform->m_pos.x += 4;
				m_DIST += 4;
			}
		}

		else if (left)
		{
			if (m_transform->m_pos.x > 0)
			{
				m_transform->m_pos.x -= 2;
				m_DIST += 2;
				m_DIST_retreat += 2;
				
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

void CHero::setMemberOverlay()
{
	selectedMem.m_img = MG_IMAGE->findImage("selected1");
	targeted_h_Mem.m_img = MG_IMAGE->findImage("target1");

	HPbar_back.m_img = MG_IMAGE->findImage("HP_empty");
	HPbar_front.m_img = MG_IMAGE->findImage("HP_full");

	ImageData temp;
	temp.m_img = MG_IMAGE->findImage("STRS_empty");
	for (int i = 0; i < 10; i++)
	{
		STRSbar.push_back(temp);
	}

}

void CHero::showSelMember(HDC _hdc)
{
	selectedMem.m_trans.m_pos = Vector2(
		m_transform->m_pos.x - m_animator->GetCurImage()->getFrameWidth() / 2 + 10,
		m_transform->m_pos.y - m_animator->GetCurImage()->getFrameHeight() /2 + 70 );

	targeted_h_Mem.m_trans.m_pos = Vector2(
		m_transform->m_pos.x - m_animator->GetCurImage()->getFrameWidth() / 2 + 20,
		m_transform->m_pos.y - m_animator->GetCurImage()->getFrameHeight()/ 2 - 300);

	selectedMem.m_img->render(_hdc, &selectedMem.m_trans);
	//targetedMem.m_img->render(_hdc, &targetedMem.m_trans);
}

void CHero::showHpStrsBar(HDC _hdc)
{
	//Hp, strs bar
	HPbar_back.m_trans.m_pos = Vector2(
		m_transform->m_pos.x - m_animator->GetCurImage()->getFrameWidth() / 2 + 46,
		m_transform->m_pos.y - m_animator->GetCurImage()->getFrameHeight() / 2 + 161);
	HPbar_front.m_trans.m_pos = Vector2(
		m_transform->m_pos.x - m_animator->GetCurImage()->getFrameWidth() / 2 + 46,
		m_transform->m_pos.y - m_animator->GetCurImage()->getFrameHeight() / 2 + 161);

	HPbar_back.m_img->render(_hdc, &HPbar_back.m_trans);
	HPbar_front.m_img->render(_hdc, &HPbar_front.m_trans);


	for (int i = 0; i < 10; i++)
	{
		if (m_STRS >= (i + 1) * 10)
		{
			if (m_STRS == 0) continue;
			STRSbar[i].m_img = MG_IMAGE->findImage("STRS_full");
		}
		STRSbar[i].m_trans.m_pos = Vector2(
			m_transform->m_pos.x - m_animator->GetCurImage()->getFrameWidth() / 2 + 47 + 10 * i,
			m_transform->m_pos.y - m_animator->GetCurImage()->getFrameHeight() / 2 + 173);
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