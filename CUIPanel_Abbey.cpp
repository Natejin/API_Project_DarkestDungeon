#include "framework.h"
#include "CUIPanel_Abbey.h"
#include "CButton.h"
#include "CHeroList_button.h"
#include "TownScene.h"
#include"CBuilding_PanelButton.h"
#include"CHero.h"
CUIPanel_Abbey::CUIPanel_Abbey()
{

}

CUIPanel_Abbey::~CUIPanel_Abbey()
{
}

HRESULT CUIPanel_Abbey::Init()
{
	CEst_UI::Init();
	
	m_windowPanelBG = new CSpriteRenderer(IMAGE::abbey_bg, m_transform);
	m_windowPanelChar = new CSpriteRenderer(IMAGE::abbey_char, m_transform);
	m_transform->m_pivot = Vector2(-0.095,-0.095);
	panelbutton = new CBuilding_PanelButton();

	CreateRooms();
	//Creatchecks();
	Unable();
	
	hero = new CHero();	
	return S_OK;
}

void CUIPanel_Abbey::Update(float deltaTime, float worldTime)
{
	if (MG_INPUT->IsUpLMB())
	{
		if (true)
		{	//���߿� Ÿ������� ȸ���� �Ѿ�� �����ϰԲ� �����ؾ��Ѵ�.
			ReduceStress();

			
		}
	}
	for (size_t i = 0; i < panelVec.size(); i++)
	{
		if (panelVec[i]->hero != nullptr)
		{

			checkVec[i]->isActive = true;
		}

	}

}
void CUIPanel_Abbey::LateUpdate()
{
}

void CUIPanel_Abbey::BackRender(HDC _hdc)
{
}

void CUIPanel_Abbey::Render(HDC _hdc)
{

}
void CUIPanel_Abbey::FrontRender(HDC _hdc)
{
	m_windowPanelBG->Render(_hdc);
	m_windowPanelChar->Render(_hdc);
	m_quick->isActive = true;
	CheckStress(_hdc);
}

void CUIPanel_Abbey::Release()
{
	
}
void CUIPanel_Abbey::CreateRooms() //panel
{
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 3; j++)
		{
			CBuilding_PanelButton* m_room = new CBuilding_PanelButton();
			
			m_room->m_transform->m_pos = Vector2(WINSIZEX / 2 + 180 + i *135 , WINSIZEY / 2 - 280 + j * 225);
			m_room->AddSpriteRenderer(IMAGE::hero_slot_bg);
			m_room->AddColliderBox();
			m_room->isActive = false;
			m_room->townScene = townScene;
			panelVec.push_back(m_room);
			MG_GMOBJ->RegisterObj("emptyroom", m_room);

			m_roomcheck = new CButton();
			m_roomcheck->m_transform->m_pos = Vector2(WINSIZEX / 2 + 180+i*135, WINSIZEY / 2 - 240 + 50+j*225);
			m_roomcheck->AddSpriteRenderer(IMAGE::check);
			m_roomcheck->AddColliderBox();
			m_roomcheck->Unable();
			checkVec.push_back(m_roomcheck);
			MG_GMOBJ->RegisterObj("check", m_roomcheck);
		}
	}
}

void CUIPanel_Abbey::Creatchecks() // check Button
{
	


}

void CUIPanel_Abbey::Enable()
{
	CEst_UI::Enable();
	for (size_t i = 0; i < panelVec.size(); i++)
	{
		panelVec[i]->isActive = true;
	}
	isActive = true;
	
}

void CUIPanel_Abbey::Unable()
{
	CEst_UI::Unable();
	for (size_t i = 0; i < panelVec.size(); i++)
	{
		panelVec[i]->isActive = false;
	}
	isActive = false;
	//m_check->isActive = false;
}

void CUIPanel_Abbey::CheckStress(HDC _hdc)
{
	char strCount[64];
	string strFrame;
	SetBkMode(_hdc, TRANSPARENT);
	SetTextColor(_hdc, RGB(255, 0, 255));
	
	for (size_t i = 0; i < MG_GAME->m_ownHeroes.size(); i++) 
	{	
		sprintf_s(strCount, "stress : %d", hero->getStress());
		TextOut(_hdc, 100, 100 + i * 20, strCount, strlen(strCount));
	};

	for (size_t i = 0; i < panelVec.size(); i++)
	{
		if (panelVec[i]->hero!=nullptr)
		{
			sprintf_s(strCount, "stress : %d", panelVec[i]->hero->getStress());
			TextOut(_hdc, 200, 100 + i * 20, strCount, strlen(strCount));
		}

	}
}

void CUIPanel_Abbey::ReduceStress()
{
	//��Ʈ������ ������.
	//�۵������� ������ ���ڸ�ĭ�� ����̵Ǿ�����
	//panelbutton�� ������ ��ϵǾ����� '��' �뺴�� ��Ʈ������ �����ؾ� �Ѵ�.
	//�� �뺴�� ��Ʈ������ �ٿ��� �ϴϱ�. �� �뺴�� ���������� �˾ƾ���.

	for (size_t i = 0; i < panelVec.size(); i++)
	{
		if (panelVec[i]->hero != nullptr)
		{
			
			panelVec[i]->hero->setStress(panelVec[i]->hero->getStress() - 15);
			
		}

	}
}
