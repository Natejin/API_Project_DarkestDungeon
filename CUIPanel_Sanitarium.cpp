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

    m_HeroList_button = new CHeroList_button();
	CreateRooms();
	Unable();
    return S_OK;
}

void CUIPanel_Sanitarium::Update(float deltaTime, float worldTime)
{
	if (MG_INPUT->IsUpLMB())
	{
		if (true)
		{	//나중에 타운씬에서 회차가 넘어갈때 실행하게끔 변경해야한다.
			ReduceStress();


		}
	}
	for (size_t i = 0; i < panelVec.size(); i++)
	{
		if (panelVec[i]->hero != nullptr)
		{

			checkVec[i]->isActive = true;
			//panelVec[i]->hero = nullptr;
		}

	}
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
	   m_quick->isActive = true;
}

void CUIPanel_Sanitarium::Release()
{
    
}

void CUIPanel_Sanitarium::CreateRooms() //panel버튼
{
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 2; j++)
		{
			CBuilding_PanelButton* m_room = new CBuilding_PanelButton();
			m_room->m_transform->m_pos = Vector2(WINSIZEX / 2 + 180 + i * 135, WINSIZEY / 2 - 280 + j * 225);
			m_room->AddSpriteRenderer(IMAGE::hero_slot_bg);
			m_room->AddColliderBox();
			m_room->isActive = false;
			m_room->scene = townScene;
			panelVec.push_back(m_room);
			MG_GMOBJ->RegisterObj("emptyroom", m_room);

			m_roomcheck = new CButton();
			m_roomcheck->m_transform->m_pos = Vector2(WINSIZEX / 2 + 180 + i * 135, WINSIZEY / 2 - 240 + 50 + j * 225);
			m_roomcheck->AddSpriteRenderer(IMAGE::check);
			m_roomcheck->AddColliderBox();
			m_roomcheck->isActive =false;
			checkVec.push_back(m_roomcheck);
			m_roomcheck->SetTriggerWhenDown(this, &CUIPanel_Sanitarium::closeRoom);
			MG_GMOBJ->RegisterObj("check", m_roomcheck);
		}
	}

}


void CUIPanel_Sanitarium::Enable()
{
	CEst_UI::Enable();
	for (size_t i = 0; i < panelVec.size(); i++)
	{
		panelVec[i]->isActive = true;
	}
	isActive = true;
	
}

void CUIPanel_Sanitarium::Unable()
{
	CEst_UI::Unable();
	for (size_t i = 0; i < panelVec.size(); i++)
	{
		panelVec[i]->isActive = false;
	}
	isActive = false;
	//m_roomcheck->isActive = false;
}

void CUIPanel_Sanitarium::closeRoom()
{
}

void CUIPanel_Sanitarium::CheckStress(HDC _hdc)
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
		if (panelVec[i]->hero != nullptr)
		{
			sprintf_s(strCount, "stress : %d", panelVec[i]->hero->getStress());
			TextOut(_hdc, 200, 100 + i * 20, strCount, strlen(strCount));
		}

	}
}

void CUIPanel_Sanitarium::ReduceStress()
{
	//스트레스를 줄이자.
	//작동시점은 영웅이 그자리칸에 등록이되었을때
	//panelbutton에 영웅이 등록되었을때 '그' 용병의 스트레스가 감소해야 한다.
	//들어간 용병의 스트레스만 줄여야 하니깐. 들어간 용병이 누구인지도 알아야함.

	for (size_t i = 0; i < panelVec.size(); i++)
	{
		if (panelVec[i]->hero != nullptr)
		{

			panelVec[i]->hero->setStress(panelVec[i]->hero->getStress() - 15);

		}

	}
}
