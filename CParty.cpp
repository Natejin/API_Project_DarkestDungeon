#include "framework.h"
#include "CParty.h"
#include "CHero.h"
#include "CVestal.h"

CParty::CParty() {
	maxPartyMember = 4;
}
CParty::~CParty() {}

HRESULT CParty::Init()
{
	return S_OK;
}

HRESULT CParty::Init(int food, int bandage, int torch)
{
	//createParty();

	m_layer = LAYER::Player;

	m_Item_food = food;
	m_Item_bandage = bandage;
	m_Item_Torch = torch;

	m_brightness = 100;

	limit = 0;
	limit2 = 0;

	m_vSound.push_back(SOUND::party_foot_dirt_01);
	m_vSound.push_back(SOUND::party_foot_dirt_02);
	m_vSound.push_back(SOUND::party_foot_dirt_03);
	m_vSound.push_back(SOUND::party_foot_dirt_04);
	m_vSound.push_back(SOUND::party_foot_dirt_05);
	m_vSound.push_back(SOUND::party_foot_dirt_06);
	
	curWalkTime = 0;
	curWalkCoolTime = 0.5;
	//torch와 brightness는 다름
	return S_OK;
}

void CParty::Update(float deltaTime, float worldTime)
{
	if (MG_INPUT->isStayKeyDown(VK_RIGHT) || MG_INPUT->isStayKeyDown(VK_LEFT))
	{
		if (curWalkTime < worldTime)
		{
			curWalkTime = worldTime + curWalkCoolTime;
			MG_SOUND->play(m_vSound[MG_RND->getInt(m_vSound.size())]);
		}
	}

	/*if (MG_INPUT->isStayKeyDown(VK_NUMPAD2))
	{
		for (size_t i = 0; i < m_member.size(); i++)
		{
			m_member[i]->m_transform->m_scale -= Vector2(0.01);
		}
	}
	if (MG_INPUT->isStayKeyDown(VK_NUMPAD8))
	{
		for (size_t i = 0; i < m_member->size(); i++)
		{
			m_member[i]->m_transform->m_scale += Vector2(0.01);
		}
	}

	if (MG_INPUT->isStayKeyDown(VK_NUMPAD6))
	{
		for (size_t i = 0; i < m_member.size(); i++)
		{
			m_member[i]->m_transform->angle += 0.1;
		}
	}

	if (MG_INPUT->isStayKeyDown(VK_NUMPAD4))
	{
		for (size_t i = 0; i < m_member.size(); i++)
		{
			m_member[i]->m_transform->angle -= 0.1;
		}
	}*/
}

void CParty::LateUpdate()
{
}

void CParty::BackRender(HDC _hdc)
{
}

void CParty::Render(HDC _hdc)
{
}

void CParty::FrontRender(HDC _hdc)
{
	showMemberInfo(_hdc);
	showItem(_hdc);
	showDis(_hdc);
}

void CParty::Release()
{
	////TODO 추후 영웅들 데이터 저장 추가 예정
	for (size_t i = 0; i < m_member.size(); i++)
	{
		MG_GAME->RegisterHeroToOwnList(m_member[i]);
		m_member[i]->Disable();
	}
	m_member.clear();
	GameObject::Release();
}

void CParty::SetHero(CHero* member)
{
	m_member.push_back(member);
}

void CParty::SetCamera() 
{
	if (m_member.size() > 0)
	{
		MG_CAMERA->SetTarget(m_member[0]);
	}
}

void CParty::SetPartyMember(vector<CHero*> party)
{
	m_member = party;
}

CHero* CParty::GetHero(int index)
{
	return index < m_member.size() ? m_member[index] : nullptr;
}

void CParty::FormationMove()
{
	int substraction[3];
	for (size_t i = 1; i < m_member.size(); i++)
	{
		substraction[i - 1] = abs(m_member[i - 1]->m_transform->m_pos.x - m_member[i]->m_transform->m_pos.x);
	}

	bool vk_Left = MG_INPUT->isStayKeyDown(VK_LEFT);
	bool vk_Right = MG_INPUT->isStayKeyDown(VK_RIGHT);

	m_member[0]->Move();
	for (size_t i = 1; i < m_member.size(); i++)
	{
		if (vk_Right | vk_Left)
		{
			if (vk_Left)
			{
				if (WB_btwHeroes > substraction[i - 1])
				{
					m_member[i]->Move();
					continue;
				}
			}
			if (vk_Right)
			{
				if (substraction[i - 1] > WF_btwHeroes)
				{
					m_member[i]->Move();
				}
			}
		}
		else 
		{
			m_member[i]->Move();
		}
	}
}

void CParty::setTorch(int torch)
{
	m_Item_Torch = torch;
}

void CParty::setFood(int food)
{
	m_Item_food = food;
}

void CParty::setBandage(int bandage)
{
	m_Item_bandage = bandage;
}

void CParty::setBrightness(int brightness)
{
	m_brightness = brightness;
}

void CParty::decreaseBright_movement()
{
	if (MG_INPUT->isStayKeyDown(VK_RIGHT) || MG_INPUT->isStayKeyDown(VK_LEFT))
	{
		if (m_member[0]->getMoveDis() > limit && m_member[0]->getMoveDis() > 200)
		{
			limit += 200;
			if (getBrightness() > 0)
			setBrightness(getBrightness() - 1);
		}
	}
}

void CParty::getStress_movement()
{
	int ran = MG_GAME->GetParty()->getBrightness() - MG_RND->getInt(100);

	if (MG_INPUT->isStayKeyDown(VK_RIGHT))
	{
		if (m_member[0]->getMoveDis() > limit2 )
		{
			if (ran < MG_RND->getInt(3))
			{
				m_member[MG_RND->getInt(MG_GAME->GetHeroPartySize())]->addStress(MG_RND->getInt(5));
			}
			limit2 += 300;
		}
	}
}

void CParty::showMemberInfo(HDC _hdc)
{
	//나중에 스테이더스를 확인하는 용도로 사용할 것
	char str[256];
	string strFrame;
	SetBkMode(_hdc, TRANSPARENT);
	SetTextColor(_hdc, RGB(255, 255, 255));

	for (size_t i = 0; i < 4; i++)
	{
		if (GetHero(i) != nullptr)
		{
			sprintf_s(str, "Hero POS: %d Stress : %d", GetHero(i)->GetPartyIndex(), GetHero(i)->getStress());
			TextOut(_hdc, WINSIZEX - 200, 10 + i * 20, str, strlen(str));
		}
	}

	for (int i = 0; i < m_member.size(); i++)
	{
		sprintf_s(str, "selectedHero: %d", m_member[i]->isSelected);
		TextOut(_hdc, WINSIZEX - 200, 300 + 20 * i, str, strlen(str));
	}
}

void CParty::showItem(HDC _hdc)
{
	char str[256];
	string strFrame;
	SetBkMode(_hdc, TRANSPARENT);
	SetTextColor(_hdc, RGB(255, 255, 255));

	sprintf_s(str, "Brightness : %d", m_brightness);
	TextOut(_hdc, WINSIZEX - 200, 180, str, strlen(str));
	sprintf_s(str, "Torch : %d", m_Item_Torch);
	TextOut(_hdc, WINSIZEX - 200, 200, str, strlen(str));
	sprintf_s(str, "Food : %d", m_Item_food);
	TextOut(_hdc, WINSIZEX - 200, 220, str, strlen(str));
	sprintf_s(str, "Bandage : %d", m_Item_bandage);
	TextOut(_hdc, WINSIZEX - 200, 240, str, strlen(str));
}

void CParty::showDis(HDC _hdc)
{
	char str[256];
	string strFrame;
	SetBkMode(_hdc, TRANSPARENT);
	SetTextColor(_hdc, RGB(255, 0, 255));

	sprintf_s(str, "distance : %d", GetHero(0)->getMoveDis());
	TextOut(_hdc, WINSIZEX - 200, 90, str, strlen(str));
	sprintf_s(str, "distance (retreat) : %d", GetHero(0)->getMoveDis_reteat());
	TextOut(_hdc, WINSIZEX - 200, 110, str, strlen(str));
}