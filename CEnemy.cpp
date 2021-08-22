#include "framework.h"
#include "CEnemy.h"

CEnemy::CEnemy() {
	m_layer = LAYER::Enemy;
	m_unitType = UNITTYPE::Enemy;
}
CEnemy::~CEnemy() {}

HRESULT CEnemy::Init(Info_Enemy* _info)
{
	Unit::Init();
	canTriggerDown = false;
	m_unitType = _info->unitType;
	info = _info;

	AddAnimator(_info->imageCombat);
	m_animator->SetAnimeSpeed(5);
	m_animator->AddImageFrame(_info->imageCorpse);

	SetMemberOverlay();
	AddColliderBox(120,300);
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
	if (isTargetSkill)
	{
		targetSkillMem.m_trans.m_pos = Vector2(
			m_transform->m_pos.x - 87,
			m_transform->m_pos.y - 163);
		targetSkillMem.Render(_hdc);
	}
	Unit::FrontRender(_hdc);
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

#pragma region get/set

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
	else 
	{
		info->m_HP = 0;
		info->isAlive = false;
		info->isCorpse = true;
		m_animator->SetIndex(1);
		m_animator->ResetAnimation();
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

int CEnemy::GetDodge() const
{
	return info->m_DODGE;
}

int CEnemy::GetProt() const
{
	return info->m_DEF;
}

bool CEnemy::GetAttribute(int index) const
{
	return info->attribute[index];
}

int CEnemy::getResist(int index)
{
	return info->resist[index];
}

#pragma endregion