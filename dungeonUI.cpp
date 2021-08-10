#include "framework.h"
#include "dungeonUI.h"
#include "CParty.h"
#include "CMapSystem.h"
#include "CInventorySystem.h"

HRESULT dungeonUI::Init()
{
	m_layer = LAYER::UI;

	showMap = false;

	SetUIIMG();
	SetButton();
	SetInven();

	return S_OK;
}

void dungeonUI::Update(float deltaTime, float worldTime)
{
	TorchLightBarDecrease();

	//for test

	if (MG_INPUT->isOnceKeyDown('A'))
	{
		MG_GAME->GetParty()->setTorch(MG_GAME->GetParty()->getTorch() + 1);
	}
	if (MG_INPUT->isOnceKeyDown('S'))
	{
		MG_GAME->GetParty()->setFood(MG_GAME->GetParty()->getFood() + 1);
	}
	if (MG_INPUT->isOnceKeyDown('D'))
	{
		MG_GAME->GetParty()->setBandage(MG_GAME->GetParty()->getBandage() + 1);
	}

	
}

void dungeonUI::LateUpdate()
{
}

void dungeonUI::BackRender(HDC _hdc)
{
}

void dungeonUI::Render(HDC _hdc)
{
	//bg�� frontRender�� �������� ���⿡ ����
	ShowUI(_hdc);
}

void dungeonUI::FrontRender(HDC _hdc)
{

}

void dungeonUI::Release()
{

}

void dungeonUI::SetUIIMG()
{
	ImageData UIimg;
	SetTorchUI();

	UIimg.m_img = MG_IMAGE->findImage("panel_bg2");
	UIimg.m_trans.m_pos = Vector2(0, 700);
	vUI.push_back(UIimg);
	UIimg.m_trans.m_pos = Vector2(1580, 700);
	vUI.push_back(UIimg);

	UIimg.m_img = MG_IMAGE->findImage("banner");
	UIimg.m_trans.m_pos = Vector2(300, 700);
	vUI.push_back(UIimg);

	UIimg.m_img = MG_IMAGE->findImage("hero");
	UIimg.m_trans.m_pos = Vector2(330, 820);
	vUI.push_back(UIimg);

	UIimg.m_img = MG_IMAGE->findImage("inventory");
	UIimg.m_trans.m_pos = Vector2(965, 700);
	vUI.push_back(UIimg);

	UIimg.m_img = MG_IMAGE->findImage("map");
	UIimg.m_trans.m_pos = Vector2(965, 700);
	vUI.push_back(UIimg);

}

void dungeonUI::SetButton()
{	
	bt_inven = new CButton();
	bt_inven->m_transform->m_pos = Vector2(1570, 1080 - 90);
	bt_inven->SetButtonSize(50, 65);
	bt_inven->AddSpriteRenderer("button");
	bt_inven->SetTriggerWhenClick(this, &dungeonUI::ShowInven);
	MG_GMOBJ->RegisterObj("dungeonUI_invenButton", bt_inven);

	bt_map = new CButton();
	bt_map->m_transform->m_pos = Vector2(1570, 1080 - 170);
	bt_map->SetButtonSize(50, 65);
	bt_map->AddSpriteRenderer("button");
	bt_map->SetTriggerWhenClick(this, &dungeonUI::ShowMap);
	MG_GMOBJ->RegisterObj("dungeonUI_mapButton", bt_map);
}

void dungeonUI::SetTorchUI()
{
	ImageData UIimg;

	UIimg.m_img = MG_IMAGE->findImage("torchBackBar");
	UIimg.m_trans.m_pos = Vector2(524, 100); //decrese according to distance
	vUI.push_back(UIimg); //[6] torchBackBar

	UIimg.m_img = MG_IMAGE->findImage("torchBackBar2");
	UIimg.m_trans.m_pos = Vector2(510, 100);
	vUI.push_back(UIimg);

	UIimg.m_img = MG_IMAGE->findImage("torchBackBar3");
	UIimg.m_trans.m_pos = Vector2(988, 100);
	vUI.push_back(UIimg);

	UIimg.m_img = MG_IMAGE->findImage("torchFrontBar");
	UIimg.m_trans.m_pos = Vector2(520, 19);
	vUI.push_back(UIimg);
}

void dungeonUI::SetInven()
{
	m_inven = new CInventorySystem();
	m_inven->Init();
	MG_GMOBJ->RegisterObj("inventory", m_inven);
}

void dungeonUI::TorchLightBarDecrease()
{
	vUI[1].m_img->setWidth(20);
	vUI[2].m_img->setWidth2(20);
	vUI[2].m_trans.m_pos.x = 1400;

	vUI[1].m_img->setWidth(20 + (422 / 100) * (100 - MG_GAME->GetParty()->getBrightness()));
	vUI[2].m_img->setWidth2(20 + (422 / 100) * (100 - MG_GAME->GetParty()->getBrightness()));
	vUI[2].m_trans.m_pos.x = 1400 - ((422 / 100) * (100 - MG_GAME->GetParty()->getBrightness()));
}

void dungeonUI::ShowInven()
{
	showMap = false; 
	m_pMapSystem->MapButtonOnOff(false);
}

void dungeonUI::ShowMap()
{
	showMap = true;
	m_pMapSystem->MapButtonOnOff(true);
}

void dungeonUI::ShowUI(HDC _hdc)
{

	for (int i = 0; i < vUI.size() - 1; i++)
	{
		vUI[i].RenderUI(_hdc);
	}

	if (showMap)
	{
		vUI[9].RenderUI(_hdc);
		ShowUIMap(_hdc);
	}
	else
	{
		ShowUIUInven(_hdc);
	}
}

void dungeonUI::ShowUIMap(HDC _hdc)
{
	//m_pMapSystem->dungeonMapCreate[0].m_imageData.m_trans.m_pos = Vector2(500, 500);
	//m_pMapSystem->dungeonMapCreate[0].m_imageData.RenderUI(_hdc);
	m_inven->isActive = false; 
}

void dungeonUI::ShowUIUInven(HDC _hdc)
{
	m_inven->showInvenItem(_hdc);
	m_inven->isActive = true;
}
