#include "framework.h"
#include "CEnemy.h"

CEnemy::CEnemy() {
	m_layer = LAYER::Enemy;
	m_unitType = UNITTYPE::Enemy;
}
CEnemy::~CEnemy() {}

//HRESULT CEnemy::Init()
//{
//	info = new Info_Enemy();
//	m_transform->m_pivot = Vector2(0.5, 1);
//	m_animator = new CAnimator();
//	m_animator->SetTrans(m_transform);
//	m_animator->SetAnimeSpeed(5);
//	SetMemberOverlay();
//	//mini_rc = RectMakeCenter(100 + m_rockman->getX() / 10 - m_camera / 10, 50 + m_rockman->getY() / 10, 10, 10);
//	return S_OK;
//}

HRESULT CEnemy::Init(Info_Enemy* _info)
{
	canTriggerDown = false;
	m_unitType = _info->unitType;
	info = _info;

	AddAnimator(_info->imageCombat);
	m_animator->SetAnimeSpeed(5);
	m_animator->AddImageFrame(_info->imageCorpse);

	SetMemberOverlay();
	AddColliderBox();
	return S_OK;
}

void CEnemy::Update(float deltaTime, float worldTime)
{
	Unit::Update(deltaTime, worldTime);
	if (m_collider->CheckColliderBoxWithPoint(g_ptMouse))
	{

		if (canTriggerStay)
		{
			m_triggerWhenStay(m_partyIndex);
		}
	}


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
			m_transform->m_pos.y - 100);
		targetSkillMem.Render(_hdc);
	}
}

void CEnemy::Release()
{
	Unit::Release();
	MG_INFO->RemoveInfo(info);
}

void CEnemy::SetMemberOverlay()
{
	Unit::SetMemberOverlay();
	targetSkillMem.m_img = MG_IMAGE->findImage(IMAGE::Target_Monster1);
}

UNITTYPE CEnemy::GetUnitType()
{
		return info->unitType;
	
}

Info_Enemy* CEnemy::GetInfo()
{
	return info;
}

int CEnemy::getHP()
{
	return  info->m_HP;
}

bool CEnemy::reduceHP(int hp)
{
	if (info->m_HP - hp > 0)
	{
		info->m_HP -= hp;
		return true;
	}
	else {
		info->m_HP = 0;
		info->isAlive = false;
		info->isCorpse = true;
		m_animator->SetIndex(1);
		return false;
	}
}

void CEnemy::increaseHP(int hp)
{
	info->m_HP += hp;
}

void CEnemy::setHP(int hp)
{
	info->m_HP = hp;
}

int CEnemy::getMaxHP()
{
	return info->m_maxHP;
}

int CEnemy::getSPD()
{
	return  info->m_SPD;
}

void CEnemy::setSPD(int spd)
{
	info->m_SPD = spd;
}


bool CEnemy::GetAlive()
{
	return info->isAlive;
}

bool CEnemy::GetCorpse()
{
	return info->isCorpse;
}
bool CEnemy::SetCorpse(bool _corpse)
{
	return	info->isCorpse = _corpse;
}
//int CEnemy::GetAcry() const
//{
//	return info->m_ACRY;
//}
//
//int CEnemy::GetCri() const
//{
//	return info->m_CRI;
//}
//
//int CEnemy::GetDmg() const
//{
//	return info->m_DMG;
//}
//
//int CEnemy::GetDodge() const
//{
//	return info->m_DODGE;
//}
//
//int CEnemy::GetDef() const
//{
//	return info->m_DEF;
//}
