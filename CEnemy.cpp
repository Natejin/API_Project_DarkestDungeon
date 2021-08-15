#include "framework.h"
#include "CEnemy.h"

CEnemy::CEnemy() {
	m_layer = LAYER::Enemy;
}
CEnemy::~CEnemy() {}

HRESULT CEnemy::Init()
{
	info = new Info_Enemy();
	info->unitType = UNITTYPE::Enemy;
	m_transform->m_pivot = Vector2(0.5, 1);
	m_animator = new CAnimator();
	m_animator->SetTrans(m_transform);
	m_animator->SetAnimeSpeed(5);
	SetMemberOverlay();
	//mini_rc = RectMakeCenter(100 + m_rockman->getX() / 10 - m_camera / 10, 50 + m_rockman->getY() / 10, 10, 10);
	return S_OK;
}

//HRESULT CEnemy::Init(string img, int resist[], int HP, int SPD, int POS, int DEF, int DODGE)
//{
//	m_HP = HP;
//	m_SPD = SPD;
//	m_POS = POS;
//
//	m_DEF = DEF;
//	m_DODGE = DODGE;
//
//	for (size_t i = 0; i < 5; i++)
//	{
//		this->resist[i] = resist[i];
//	}
//	for (size_t i = 0; i < 8; i++)
//	{
//		attribute[i] = false;
//	}
//	m_animator = new CAnimator();
//	m_animator->SetTrans(m_transform);
//	m_animator->SetAnimeSpeed(5);
//	m_animator->AddImageFrame(img);
//
//
//
//	return S_OK;
//}

void CEnemy::Update(float deltaTime, float worldTime)
{
	Unit::Update(deltaTime, worldTime);
}

void CEnemy::LateUpdate()
{
}

void CEnemy::BackRender(HDC _hdc)
{
}

void CEnemy::Render(HDC _hdc)
{
	m_animator->FrameRender(_hdc);
}

void CEnemy::FrontRender(HDC _hdc)
{
	Unit::FrontRender(_hdc);
	if (isTargetSkill)
	{
		targetSkillMem.m_trans.m_pos = Vector2(
			m_transform->m_pos.x - 87,
			m_transform->m_pos.y - 78);

		targetSkillMem.Render(_hdc);
	}
}

void CEnemy::Release()
{
	Unit::Release();
}

void CEnemy::SetMemberOverlay()
{
	Unit::SetMemberOverlay();
	targetSkillMem.m_img = MG_IMAGE->findImage(IMAGE::Target_Monster1);
}
