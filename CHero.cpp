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

	
	//job에 따른 스킬을 넣을 변수, 혹은 함수가 필요함
	//스킬을 enum class에 직업별로 추가할 것

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
}

void CHero::Release()
{
	Unit::Release();
}

void CHero::Move()
{
	int ran;
	//인풋에 따른 이동 함수
	//앞뒤 이동시 속도의 차이
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

				//4분의 1 확률로 스트레스를 받음
				ran = MG_RND->getInt(3);
				if (ran == 1)
				{
					if ((m_DIST_retreat % 200 == 0) && !(m_DIST_retreat == 0))
					{
						setStress(5);
					}
				}
			}
		}

		m_animator->SetIndex(1);
	}
	else {
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
