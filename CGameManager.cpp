#include "framework.h"
#include "CGameManager.h"
#include "CHero.h"
#include "CParty.h"
#include "CVestal.h"

CGameManager::CGameManager() {}
CGameManager::~CGameManager() {}

HRESULT CGameManager::Init()
{
	heroID = 0;
	RegisterHeroToOwnList(CreateHero("member1", JOB::Crusader));
	RegisterHeroToOwnList(CreateHero("member2", JOB::Vestal));
	RegisterHeroToOwnList(CreateHero("member3", JOB::Crusader));
	RegisterHeroToOwnList(CreateHero("member4", JOB::Vestal));
	RegisterHeroToOwnList(CreateHero("member5", JOB::Highwayman));
	RegisterHeroToOwnList(CreateHero("member6", JOB::PlagueDoctor));


	RegisterHeroToParty(0);
	RegisterHeroToParty(1);
	RegisterHeroToParty(2);
	RegisterHeroToParty(3);
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

bool CGameManager::RegisterHeroToParty(CHero* hero)
{
	if (m_partyOrigin.size() < 4)
	{
		m_partyOrigin.push_back(hero);
		return true;
	}return false;
}

bool CGameManager::RegisterHeroToParty(int ownIndex)
{
	return RegisterHeroToParty(m_ownHeroes[ownIndex]);
}

void CGameManager::RegisterHeroToOwnList(CHero* hero)
{
	m_ownHeroes.push_back(hero);
}

bool CGameManager::RemoveHeroFromParty(int id)
{
	if (id < m_partyOrigin.size())
	{
		m_partyOrigin.erase(m_partyOrigin.begin() + id);
		return true;
	}
	return false;
}

bool CGameManager::RemoveHeroFromOwnList(int heroId)
{
	for (size_t i = 0; i < m_ownHeroes.size(); i++)
	{
		if (heroId == m_ownHeroes[i]->heroID)
		{
			m_ownHeroes[i]->Unable();
			MG_GMOBJ->RemoveObj(m_ownHeroes[i]);
			m_ownHeroes.erase(m_ownHeroes.begin() + i);
			return true;
		}
	}
	return false;
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

vector<CHero*> CGameManager::GetHeroes()
{
	return m_partyOrigin;
}

CHero* CGameManager::GetHero(int index)
{
	return index < m_ownHeroes.size() ? m_ownHeroes[index] : nullptr;
}


CHero* CGameManager::CreateHero(string name, JOB job)
{
	CHero* hero = new CHero();

	int resist[5] = { 30, 30, 30, 30, 30 };
	//stun, blight, bleed, debuff, move
	hero->heroID = heroID++;
	switch (job)
	{
	case JOB::Crusader:
		resist[0] = 40;
		resist[4] = 40;
		hero->Init(JOB::Crusader, resist, 33, 1, 1, 9, 0, 3, 0, 5);
		hero->AddAnimator(IMAGE::Crusader_Idle);
		hero->m_animator->SetAnimeSpeed(5);
		hero->m_animator->AddImageFrame(IMAGE::Crusader_Walk);
		hero->m_animator->AddImageFrame(IMAGE::Crusader_Combat);
		hero->ownSkill.push_back(SKILL::Crusader_Combat_Smite);
		hero->ownSkill.push_back(SKILL::Crusader_Combat_ZealousAccusation);
		hero->ownSkill.push_back(SKILL::Crusader_Combat_StunningBlow);
		hero->ownSkill.push_back(SKILL::Crusader_Heal_BattleHeal);
		break;
	case JOB::Vestal:
		hero->Init(JOB::Vestal, resist, 24, 4, 1, 6, 0, 1, 0, 0);
		hero->AddAnimator(IMAGE::Vestal_Idle);
		hero->m_animator->SetAnimeSpeed(5);
		hero->m_animator->AddImageFrame(IMAGE::Vestal_Idle);
		hero->m_animator->AddImageFrame(IMAGE::Vestal_Idle);
		hero->ownSkill.push_back(SKILL::Vestal_Combat_MaceBash);
		hero->ownSkill.push_back(SKILL::Vestal_Combat_Judgement);
		hero->ownSkill.push_back(SKILL::Vestal_Combat_DazzlingLight);
		hero->ownSkill.push_back(SKILL::Vestal_Heal_DivineComfort);
		break;
	case JOB::PlagueDoctor:
		break;
	case JOB::Highwayman:
		break;
	default:
		break;
	}

	hero->Unable();
	MG_GMOBJ->RegisterObj(hero->GetName(), hero);
	return hero;
}