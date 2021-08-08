#include "framework.h"
#include "dungeonUI.h"
#include "CParty.h"

HRESULT dungeonUI::Init()
{
	m_layer = LAYER::UI;

	showMap = false;

	SetUIIMG();
	SetButton();

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
}

void dungeonUI::FrontRender(HDC _hdc)
{
	//bg의 frontRender에 가려져서 여기에 넣음
	ShowUI(_hdc);

	//캐릭터 정보, 인벤토리, 맵 정보
}

void dungeonUI::Release()
{

}

void dungeonUI::SetUIIMG()
{
	ImageData UIimg;

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

	SetTorchUI();

}

void dungeonUI::SetButton()
{	
	bt_inven = new CButton();
	bt_inven->m_transform->m_pos = Vector2(1550, 1080 - 235);
	bt_inven->SetButtonSize(50, 65);
	bt_inven->AddSpriteRenderer("button");
	bt_inven->SetTriggerWhenClick(this, &dungeonUI::ShowInven);
	MG_GMOBJ->RegisterObj("dungeonUI_invenButton", bt_inven);

	bt_map = new CButton();
	bt_map->m_transform->m_pos = Vector2(1550, 1080 - 150);
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

void dungeonUI::TorchLightBarDecrease()
{
	vUI[7].m_img->setWidth(20);
	vUI[8].m_img->setWidth2(20);
	vUI[8].m_trans.m_pos.x = 1400;

	vUI[7].m_img->setWidth(20 + (422 / 100) * (100 - m_party->getBrightness()));
	vUI[8].m_img->setWidth2(20 + (422 / 100) * (100 - m_party->getBrightness()));
	vUI[8].m_trans.m_pos.x = 1400 - ((422 / 100) * (100 - m_party->getBrightness()));
}

void dungeonUI::ShowUI(HDC _hdc)
{
	for (int i = 0; i < vUI.size(); i++)
	{
		vUI[i].m_img->renderUI(_hdc, &vUI[i].m_trans);

		if (showMap == true)
		{
			vUI[4].m_img->renderUI(_hdc, &vUI[4].m_trans);
		}
	}
}

void dungeonUI::setNowSceneParty(CParty* party)
{
	m_party = party;
}