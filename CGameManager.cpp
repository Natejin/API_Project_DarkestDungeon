#include "framework.h"
#include "CGameManager.h"
#include "CHero.h"
#include "CVestal.h"

CGameManager::CGameManager() {}
CGameManager::~CGameManager() {}

HRESULT CGameManager::Init()
{

	
	RegisterHero(CreateVestal("member1"));
	RegisterHero(CreateVestal("member2"));
	RegisterHero(CreateVestal("member3"));
	RegisterHero(CreateVestal("member4"));
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
	if (m_partyOrigin.size() < 4)
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

Vestal* CGameManager::CreateVestal(string name)
{
	//member1 = new CHero();
	//int resist[5] = { 30, 30, 30, 30, 30 };
	//member1->Init(JOB::Vestal, resist, 24, 4, 1, 6, 0, 1, 0, 0);
	//member1->m_transform->m_pos = Vector2(210, 360);
	//MG_GMOBJ->RegisterObj(name, member1);
	//m_member.push_back(member1);

	//================================================

	Vestal* vestal = new Vestal();

	int resist[5] = { 30, 30, 30, 30, 30 };
	//stun, blight, bleed, debuff, move

	vestal->Init(JOB::Vestal, IMAGE::Vestal_Idle, resist, 24, 4, 1, 6, 0, 1, 0, 0);
	//pos는 임의로 1에 배치, 공격력은 4-9의 중간값으로.

	//member1->m_transform->m_pos = Vector2(210, 360);
	//실질적으로 좌표상 존재하는 위치

	return vestal;
}

void CGameManager::HireHero(CHero* _hero)
{	
	m_ownHeroes.push_back(_hero);
}
