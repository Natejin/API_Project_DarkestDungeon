#include "framework.h"
#include "CUIPanel_Sanitarium.h"
#include"CButton.h"
#include"CHeroList_button.h"
#include"TownScene.h"
#include"CBuilding_PanelButton.h"
#include"CHero.h"
CUIPanel_Sanitarium::CUIPanel_Sanitarium()
{
}
CUIPanel_Sanitarium::~CUIPanel_Sanitarium()
{
}
HRESULT CUIPanel_Sanitarium::Init()
{
	CEst_UI::Init();

	m_windowPanelBG = new CSpriteRenderer(IMAGE::sanitarium_bg, m_transform);
	m_windowPanelChar = new CSpriteRenderer(IMAGE::sanitarium_char, m_transform);
	m_transform->m_pivot = Vector2(-0.095, -0.095);
	//panelbutton = new CBuilding_PanelButton();

	CreateRooms();
	Disable();

	//hero = new CHero();	
	return S_OK;

}

void CUIPanel_Sanitarium::Update(float deltaTime, float worldTime)
{
	if (MG_INPUT->IsUpLMB())
	{
		if (true)
		{	//���߿� Ÿ������� ȸ���� �Ѿ�� �����ϰԲ� �����ؾ��Ѵ�.
			ReduceStress();


		}
	}
	//for (size_t i = 0; i < panelVec.size(); i++)
	//{
	//	if (panelVec[i]->hero != nullptr)
	//	{

	//		checkVec[i]->isActive = true;
	//	}

	//}
}

void CUIPanel_Sanitarium::LateUpdate()
{
}

void CUIPanel_Sanitarium::BackRender(HDC _hdc)
{
}

void CUIPanel_Sanitarium::Render(HDC _hdc)
{
}

void CUIPanel_Sanitarium::FrontRender(HDC _hdc)
{
	m_windowPanelBG->Render(_hdc);
	m_windowPanelChar->Render(_hdc);
	m_quit->isActive = true;
	CheckStress(_hdc);
}

void CUIPanel_Sanitarium::Release()
{
	CEst_UI::Release();
	for (size_t i = 0; i < panelVec.size(); i++)
	{
		MG_GMOBJ->RemoveObj(panelVec[i]);
	}

	panelVec.clear();
}

void CUIPanel_Sanitarium::CreateRooms() //panel
{
	int k = 0;
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 2; j++)
		{
			CBuilding_PanelButton* m_room = new CBuilding_PanelButton();
			m_room->m_transform->m_pos = Vector2(WINSIZEX / 2 + 180 + i * 135, WINSIZEY / 2 - 280 + j * 225);
			m_room->buttonID = k;
			m_room->scene = townScene;
			m_room->Init();
			panelVec.push_back(m_room);
			k++;
		}
	}
}

void CUIPanel_Sanitarium::SetcloseRoom()
{
	/*
	sanitarium_disease_quirk_cost,
	sanitarium_cost,
	sanitarium_room,
	*/
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 2; j++)
		{
			if (i % 3 == 0)
			{
				panelVec[i]->m_spriteRenderer->SetImage(IMAGE::sanitarium_disease_quirk_cost);

			}
			if (i % 3 == 1)
			{
				panelVec[i]->m_spriteRenderer->SetImage(IMAGE::sanitarium_cost);
			}
			if (i % 3 == 2)
			{
				panelVec[i]->m_spriteRenderer->SetImage(IMAGE::sanitarium_room);

			}
		}
	}

}

void CUIPanel_Sanitarium::Enable()
{
	for (size_t i = 0; i < panelVec.size(); i++)
	{
		panelVec[i]->isActive = true;
	}
	CEst_UI::Enable();
}

void CUIPanel_Sanitarium::Disable()
{
	CEst_UI::Disable();
	for (size_t i = 0; i < panelVec.size(); i++)
	{
		panelVec[i]->isActive = false;
	}

	
}

void CUIPanel_Sanitarium::CheckStress(HDC _hdc)
{
	char strCount[64];
	string strFrame;
	SetBkMode(_hdc, TRANSPARENT);
	SetTextColor(_hdc, RGB(255, 0, 255));
	//
	//for (size_t i = 0; i < MG_GAME->m_ownHeroes.size(); i++) 
	//{	
	//	sprintf_s(strCount, "stress : %d", hero->getStress());
	//	TextOut(_hdc, 100, 100 + i * 20, strCount, strlen(strCount));
	//};

	for (size_t i = 0; i < panelVec.size(); i++)
	{
		if (panelVec[i]->hero != nullptr)
		{
			sprintf_s(strCount, "stress : %d", panelVec[i]->hero->getStress());
			TextOut(_hdc, 200, 100 + i * 20, strCount, strlen(strCount));
		}

	}
}

void CUIPanel_Sanitarium::ReduceStress()
{
	for (size_t i = 0; i < panelVec.size(); i++)
	{
		if (panelVec[i]->hero != nullptr)
		{
			panelVec[i]->hero->setStress(panelVec[i]->hero->getStress() - 15);
		}
	}
}
