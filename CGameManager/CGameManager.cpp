#include "framework.h"
#include "CGameManager.h"
#include "CHero.h"
#include "CVestal.h"


CGameManager::CGameManager()
{
}

CGameManager::~CGameManager()
{

}

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



void CGameManager::Render(HDC _hdc)
{
}



void CGameManager::Release()
{

}

void CGameManager::RegisterHero(CHero* hero)
{
	if (m_partyOrigin.size() < 4)
	{
		m_partyOrigin.push_back(hero);
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
	//pos�� ���Ƿ� 1�� ��ġ, ���ݷ��� 4-9�� �߰�������.

	//member1->m_transform->m_pos = Vector2(210, 360);

	//���������� ��ǥ�� �����ϴ� ��ġ
	return vestal;
}

