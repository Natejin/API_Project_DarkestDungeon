#include "framework.h"
#include "CHero.h"
#include "CParty.h"
#include "DungeonScene.h"
#include "CAnimator.h"

CHero::CHero() {
	unitType = UNITTYPE::Hero;
}
CHero::~CHero() {}

HRESULT CHero::Init(JOB job, IMAGE img, int resist[], int HP, int SPD, int POS, int DMG, int ACRY, int CRI, int DEF, int DODGE)
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

	//m_image = MG_IMAGE->findImage(img);

	m_animator = new CAnimator();
	m_animator->SetTrans(m_transform);
	m_animator->AddImageFrame(img);
	m_animator->SetAnimeSpeed(5);

	
	//job�� ���� ��ų�� ���� ����, Ȥ�� �Լ��� �ʿ���
	//��ų�� enum class�� �������� �߰��� ��

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
	//��ǲ�� ���� �̵� �Լ�
	//�յ� �̵��� �ӵ��� ����
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
	}
}

bool CHero::PreventGetOutBg(int startX, int endX)
{
	if (m_transform->m_pos.x < endX - 200 && 0 < m_transform->m_pos.x) 
		return true;
	else 
		return false;
}
