#include "framework.h"
#include "CGameManager.h"
#include "CHero.h"
#include "CParty.h"
#include "CVestal.h"

CGameManager::CGameManager() {}
CGameManager::~CGameManager() {}

HRESULT CGameManager::Init()
{
	RegisterHero(CreateHero("member1", JOB::Crusader));
	RegisterHero(CreateHero("member2", JOB::Vestal));
	RegisterHero(CreateHero("member3", JOB::Crusader));
	RegisterHero(CreateHero("member4", JOB::Vestal));
	RegisterHero(CreateHero("member5", JOB::Highwayman));
	RegisterHero(CreateHero("member6", JOB::PlagueDoctor));

	return S_OK;
}

void CGameManager::Update(float deltaTime, float worldTime)
{
}

void CGameManager::LateUpdate()
{
}

void CGameManager::BackRender(HDC _hdc)
{
}

void CGameManager::Render(HDC _hdc)
{

}

void CGameManager::FrontRender(HDC _hdc)
{
}

void CGameManager::Release()
{
	for (size_t i = 0; i < m_partyOrigin.size(); i++)
	{
		m_partyOrigin[i] = nullptr;
	}
	m_partyOrigin.clear();

	for (size_t i = 0; i < m_ownHeroes.size(); i++)
	{
		SAFE_DELETE(m_ownHeroes[i]);
	}
	m_ownHeroes.clear();
}

void CGameManager::RegisterHero(CHero* hero)
{
	if (m_partyOrigin.size() < 6)
	{
		m_partyOrigin.push_back(hero);

		MG_GMOBJ->RegisterObj(hero->GetName(), hero);
	}
}

void CGameManager::RemoveHero(int id)
{
	m_partyOrigin.erase(m_partyOrigin.begin() + id);
}

vector<CHero*> CGameManager::GetHeroes()
{
	return m_partyOrigin;
}

CHero* CGameManager::GetHero(int index)
{
	return index < m_partyOrigin.size() ? m_partyOrigin[index] : nullptr;
}

void CGameManager::setParty()
{
	m_party = new CParty;
	m_party->Init(1, 1, 1);
}

CParty* CGameManager::GetParty()
{
	return m_party;
}




CHero* CGameManager::CreateHero(string name, JOB job)
{
	//member1 = new CHero();
	//int resist[5] = { 30, 30, 30, 30, 30 };
	//member1->Init(JOB::Vestal, resist, 24, 4, 1, 6, 0, 1, 0, 0);
	//member1->m_transform->m_pos = Vector2(210, 360);
	//MG_GMOBJ->RegisterObj(name, member1);
	//m_member.push_back(member1);

	//================================================

	CHero* vestal = new CHero();

	int resist[5] = { 30, 30, 30, 30, 30 };
	//stun, blight, bleed, debuff, move

	switch (job)
	{
	case JOB::Crusader:
		resist[0] = 40;
		resist[4] = 40;
		vestal->Init(JOB::Crusader, resist, 33, 1, 1, 9, 0, 3, 0, 5);
		vestal->AddAnimator(IMAGE::Crusader_Idle);
		vestal->m_animator->SetAnimeSpeed(5);
		vestal->m_animator->AddImageFrame(IMAGE::Crusader_Walk);
		vestal->m_animator->AddImageFrame(IMAGE::Crusader_Combat);
		break;
	case JOB::Vestal:
		vestal->Init(JOB::Vestal, resist, 24, 4, 1, 6, 0, 1, 0, 0);
		vestal->AddAnimator(IMAGE::Vestal_Idle);
		vestal->m_animator->SetAnimeSpeed(5);
		vestal->m_animator->AddImageFrame(IMAGE::Vestal_Idle);
		vestal->m_animator->AddImageFrame(IMAGE::Vestal_Idle);
		break;
	case JOB::PlagueDoctor:
		
		vestal->Init(JOB::PlagueDoctor, resist, 33, 1, 1, 9, 0, 3, 0, 5);
		break;
	case JOB::Highwayman:
		
		vestal->Init(JOB::Highwayman, resist, 33, 1, 1, 9, 0, 3, 0, 5);
		break;
	default:
		break;
	}

	//pos는 임의로 1에 배치, 공격력은 4-9의 중간값으로.

	//member1->m_transform->m_pos = Vector2(210, 360);
	//실질적으로 좌표상 존재하는 위치

	return vestal;
}