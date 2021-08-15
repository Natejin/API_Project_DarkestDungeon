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
	Unable();

	//hero = new CHero();	
	return S_OK;
}

void CUIPanel_Abbey::Update(float deltaTime, float worldTime)
{
	if (MG_INPUT->IsUpLMB())
	{
		if (true)
		{	//나중에 타운씬에서 회차가 넘어갈때 실행하게끔 변경해야한다.
			ReduceStress();
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
	m_quit->isActive = true;
	CheckStress(_hdc);
}

void CUIPanel_Abbey::Release()
{
	
}
void CUIPanel_Abbey::CreateRooms() //panel
{
	int k = 0;
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 3; j++)
		{
			m_room = new CBuilding_PanelButton();
			m_room->m_transform->m_pos = Vector2(WINSIZEX / 2 + 180 + i *135 , WINSIZEY / 2 - 280 + j * 225);
			m_room->buttonID = k;
			m_room->scene = townScene;
			m_room->Init();
			panelVec.push_back(m_room);
			k++;
		}
	}
}

void CUIPanel_Abbey::SetcloseRoom()
{
	//채찍질 ::abbey_flagellation
	//기도	 ::abbey_pray
	//치료	 ::abbey_meditation
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 3; j++)
		{
				if (i % 3 == 0)
				{
					panelVec[i]->m_spriteRenderer->SetImage(IMAGE::abbey_flagellation);
					
				}
				if (i % 3 == 1)
				{
					panelVec[i]->m_spriteRenderer->SetImage(IMAGE::abbey_pray);
				}
				if (i % 3 == 2)
				{
					panelVec[i]->m_spriteRenderer->SetImage(IMAGE::abbey_meditation);

				}
				
			
		}
	}

}

void CUIPanel_Abbey::Enable()
{
	for (size_t i = 0; i < panelVec.size(); i++)
	{
		panelVec[i]->isActive = true;
	}
	CEst_UI::Enable();
}

void CUIPanel_Abbey::Unable()
{
	CEst_UI::Unable();
	for (size_t i = 0; i < panelVec.size(); i++)
	{
		panelVec[i]->isActive = false;
	}
}

void CUIPanel_Abbey::CheckStress(HDC _hdc)
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
		if (panelVec[i]->hero!=nullptr)
		{
			sprintf_s(strCount, "stress : %d", panelVec[i]->hero->getStress());
			TextOut(_hdc, 200, 100 + i * 20, strCount, strlen(strCount));
		}

	}
}

void CUIPanel_Abbey::ReduceStress()
{
	for (size_t i = 0; i < panelVec.size(); i++)
	{
		if (panelVec[i]->hero != nullptr)
		{
			panelVec[i]->hero->setStress(panelVec[i]->hero->getStress() - 15);
		}
	}
}
