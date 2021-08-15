#include "framework.h"
#include "dungeonUI.h"
#include "CParty.h"
#include "CMapSystem.h"
#include "CInventorySystem.h"
#include "CUIPanel.h"
#include "CDragButtonMinimapBG.h"
#include "CBTN_Skill.h";
#include "DungeonScene.h"
#include "CBattleSystem.h"
HRESULT dungeonUI::Init()
{
	m_layer = LAYER::UI;

	SetUIIMG();
	SetButton();
	SetInven();
	ShowInven();
	//SetSkillButton();
	return S_OK;
}

void dungeonUI::Update(float deltaTime, float worldTime)
{
	TorchLightBarDecrease();
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
	SetTorchUIimg();

	//왼쪽아래 UI
	CreatePanel("panel_bg2", Vector2(0, 700), LAYER::MinimapBackground);
	//오른쪽아래 UI
	CreatePanel("panel_bg2", Vector2(1580, 700), LAYER::MinimapBackground);
	//영웅 로스터 아이콘 + 스킬아이콘 뒷배경
	CreatePanel(IMAGE::banner, Vector2(300, 700), LAYER::UI);
	//영웅 아이템 +장신구 뒷 배경
	CreatePanel(IMAGE::hero, Vector2(330, 820), LAYER::UI);

	//인벤토리 패널
	invenPanel = CreatePanel(IMAGE::inventory, Vector2(965, 700), LAYER::UI);

	//맵패널
	mapPanel1 = CreatePanel(IMAGE::map1, Vector2(965, 700), LAYER::UI);
	mapPanel1->UseFrontRender();

	//맵 뒤 그리드 배경
	mapPanel2 = new CDragButtonMinimapBG();
	mapPanel2->Init();
	mapPanel2->m_transform->m_pos = Vector2(965, 700);
	mapPanel2->AddSpriteRenderer(IMAGE::map2);
	mapPanel2->SetMapSystem(m_pMapSystem);
	mapPanel2->AddColliderBox();
	MG_GMOBJ->RegisterObj("minimapBG", mapPanel2);
}

void dungeonUI::SetButton()
{	
	//클릭시 인벤토리 보이기
	bt_inven = new CButton();
	bt_inven->m_transform->m_pos = Vector2(1570, 1080 - 90);
	bt_inven->AddColliderBox(50, 65);
	bt_inven->AddSpriteRenderer("button");
	bt_inven->SetTriggerWhenDown(this, &dungeonUI::ShowInven);
	MG_GMOBJ->RegisterObj("dungeonUI_invenButton", bt_inven);

	//클릭시 맵 보이기
	bt_map = new CButton();
	bt_map->m_transform->m_pos = Vector2(1570, 1080 - 170);
	bt_map->AddColliderBox(50, 65);
	bt_map->AddSpriteRenderer("button");
	bt_map->SetTriggerWhenDown(this, &dungeonUI::ShowMap);
	MG_GMOBJ->RegisterObj("dungeonUI_mapButton", bt_map);
}


void dungeonUI::SetTorchUIimg()
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
	m_invenSystem = new CInventorySystem();
	m_invenSystem->Init();
	MG_GMOBJ->RegisterObj("inventory", m_invenSystem);
}

void dungeonUI::SetSkillButton()
{

	for (size_t i = 0; i < 5; i++)
	{
		CBTN_Skill* temp = new CBTN_Skill();
		temp->scene = scene;
		temp->Init();
		temp->m_transform->m_pos = Vector2(620 + 70 * i, 764);
		temp->m_pBattleSystem = m_pBattleSystem;
		temp->index = i;
		string tempStr = "SkillBTN";
		tempStr += i;
		temp->SetName(tempStr);
		skillBTNs.push_back(temp);
		MG_GMOBJ->RegisterObj(temp);
	}
	

	


	//temp = new CBTN_Skill();
	//temp->scene = scene;
	//temp->Init();
	//temp->m_transform->m_pos = Vector2(655, 732);
	//temp->SetTriggerWhenDown(scene->m_pBattleSystem, &CBattleSystem::UseSkill2);
	//skillBTNs.push_back(temp);
	//MG_GMOBJ->RegisterObj("SkillBTN 2", temp);

	//temp = new CBTN_Skill();
	//temp->scene = scene;
	//temp->Init();
	//temp->m_transform->m_pos = Vector2(725, 732);
	//temp->SetTriggerWhenDown(scene->m_pBattleSystem, &CBattleSystem::UseSkill3);
	//skillBTNs.push_back(temp);
	//
	//MG_GMOBJ->RegisterObj("SkillBTN 3", temp);

	//temp = new CBTN_Skill();
	//temp->scene = scene;
	//temp->Init();
	//temp->m_transform->m_pos = Vector2(795, 732);
	//temp->SetTriggerWhenDown(scene->m_pBattleSystem, &CBattleSystem::UseSkill4);
	//skillBTNs.push_back(temp);
	//MG_GMOBJ->RegisterObj("SkillBTN 4", temp);
}

void dungeonUI::SelectSkillButton()
{

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
	m_pMapSystem->MapButtonOnOff(false);

	invenPanel->isActive = true;
	m_invenSystem->isActive = true;
	m_invenSystem->Enable();

	mapPanel1->isActive = false;
	mapPanel2->isActive = false;
}

void dungeonUI::ShowMap()
{
	m_pMapSystem->MapButtonOnOff(true);

	invenPanel->isActive = false;
	m_invenSystem->isActive = false;
	m_invenSystem->Unable();

	mapPanel1->isActive = true;
	mapPanel2->isActive = true;
}

void dungeonUI::ShowUI(HDC _hdc)
{
	for (int i = 0; i < vUI.size(); i++)
	{
		vUI[i].RenderUI(_hdc);
	}
}

CUIPanel* dungeonUI::CreatePanel(string name, Vector2 pos, LAYER layer)
{
	CUIPanel* uiPanel = new CUIPanel();
	uiPanel->Init();
	uiPanel->AddSpriteRenderer(name);
	uiPanel->m_transform->m_pos = pos;
	uiPanel->m_layer = layer;
	uiPanel->UseRender();
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
	uiPanel->UseRender();
	MG_GMOBJ->RegisterObj("panel", uiPanel);
	return uiPanel;
}

CInventorySystem* dungeonUI::getInven()
{
	return m_invenSystem;
}
