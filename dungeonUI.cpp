#include "framework.h"
#include "dungeonUI.h"
#include "CParty.h"
#include "CMapSystem.h"
#include "CInventorySystem.h"
#include "CUIPanel.h"
#include "CDragButtonMinimapBG.h"
HRESULT dungeonUI::Init()
{
	m_layer = LAYER::UI;

	showMap = false;

	SetUIIMG();
	SetButton();
	SetInven();
	ShowInven();
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

	CreatePanel("panel_bg2", Vector2(0, 700), LAYER::MinimapBackground);
	CreatePanel("panel_bg2", Vector2(1580, 700), LAYER::MinimapBackground);
	CreatePanel(IMAGE::banner, Vector2(300, 700), LAYER::UI);
	CreatePanel(IMAGE::hero, Vector2(330, 820), LAYER::UI);

	invenPanel = CreatePanel(IMAGE::inventory, Vector2(965, 700), LAYER::UI);
	//invenPanel->UseBackRender();

	//mapPanel1 = new CDragButtonMinimapBG();
	//mapPanel1->SetMapSystem(m_pMapSystem);


	//mapPanel2 = CreatePanel(IMAGE::map2, Vector2(965, 700), LAYER::MinimapBackground);
	//mapPanel2->UseBackRender();




	mapPanel1 = CreatePanel(IMAGE::map1, Vector2(965, 700), LAYER::UI);
	mapPanel1->UseFrontRender();


	mapPanel2 = new CDragButtonMinimapBG();
	mapPanel2->Init();
	mapPanel2->m_transform->m_pos = Vector2(965, 700);
	mapPanel2->AddSpriteRenderer(IMAGE::map2);
	mapPanel2->SetMapSystem(m_pMapSystem);
	mapPanel2->AddColliderBox();
	MG_GMOBJ->RegisterObj("minimapBG", mapPanel2);

	//mapPanel2 = CreatePanel(IMAGE::map2, Vector2(965, 700), LAYER::MinimapBackground);
	//mapPanel2->UseBackRender();
}

void dungeonUI::SetButton()
{	
	bt_inven = new CButton();
	bt_inven->m_transform->m_pos = Vector2(1570, 1080 - 90);
	bt_inven->AddColliderBox(50, 65);
	bt_inven->AddSpriteRenderer("button");
	bt_inven->SetTriggerWhenDown(this, &dungeonUI::ShowInven);
	MG_GMOBJ->RegisterObj("dungeonUI_invenButton", bt_inven);

	bt_map = new CButton();
	bt_map->m_transform->m_pos = Vector2(1570, 1080 - 170);
	bt_map->AddColliderBox(50, 65);
	bt_map->AddSpriteRenderer("button");
	bt_map->SetTriggerWhenDown(this, &dungeonUI::ShowMap);
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

void dungeonUI::SetSkillButton()
{
	//battle���¿����� skill��ư�� Ȱ��ȭ �ǵ���
	


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

	invenPanel->isActive = true;
	m_inven->Enable();
	mapPanel1->isActive = false;
	mapPanel2->isActive = false;
	showMap = false;
	m_inven->isActive = true;
}

void dungeonUI::ShowMap()
{
	m_inven->Unable();
	showMap = true;
	m_pMapSystem->MapButtonOnOff(true);

	invenPanel->isActive = false;
	mapPanel1->isActive = true;
	mapPanel2->isActive = true;
	showMap = true;
	m_inven->isActive = false;
}

void dungeonUI::ShowUI(HDC _hdc)
{
	for (int i = 0; i < vUI.size(); i++)
	{
		vUI[i].RenderUI(_hdc);
	}

	//if (showMap)
	//{
	//	//vUI[9].RenderUI(_hdc);
	//	ShowUIMap(_hdc);
	//}
	//else
	//{
	//	ShowUIUInven(_hdc);
	//}
}

void dungeonUI::ShowUIMap(HDC _hdc)
{
	//m_pMapSystem->dungeonMapCreate[0].m_imageData.m_trans.m_pos = Vector2(500, 500);
	//m_pMapSystem->dungeonMapCreate[0].m_imageData.RenderUI(_hdc);

	//m_inven->Enable();
}

void dungeonUI::ShowUIUInven(HDC _hdc)
{
	//m_inven->Unable();
}

CUIPanel* dungeonUI::CreatePanel(string name, Vector2 pos, LAYER layer)
{
	CUIPanel* uiPanel = new CUIPanel();
	uiPanel->Init();
	uiPanel->AddSpriteRenderer(name);
	uiPanel->m_transform->m_pos = pos;
	uiPanel->m_layer = layer;
	uiPanel->UseFrontRender();
	MG_GMOBJ->RegisterObj(name, uiPanel);
	return uiPanel;
}

CUIPanel* dungeonUI::CreatePanel(IMAGE image, Vector2 pos, LAYER layer)
{
	CUIPanel* uiPanel = new CUIPanel();
	uiPanel->Init();
	uiPanel->AddSpriteRenderer(image);
	uiPanel->m_transform->m_pos = pos;
	uiPanel->m_layer = layer;
	uiPanel->UseFrontRender();
	MG_GMOBJ->RegisterObj("panel", uiPanel);
	return uiPanel;
}