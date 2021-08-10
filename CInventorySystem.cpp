#include "framework.h"
#include "CInventorySystem.h"
#include "CParty.h"
#include "CButton.h"

CInventorySystem::CInventorySystem() {}
CInventorySystem::~CInventorySystem() {}

HRESULT CInventorySystem::Init()
{
	m_layer = LAYER::UIButton;
	setItem();
	return S_OK;
}

void CInventorySystem::Update(float deltaTime, float worldTime)
{
}

void CInventorySystem::LateUpdate()
{
}

void CInventorySystem::BackRender(HDC _hdc)
{
}

void CInventorySystem::Render(HDC _hdc)
{

}

void CInventorySystem::FrontRender(HDC _hdc)
{
	//ImageData temp;
	//temp.m_img = MG_IMAGE->findImage("testItem");
	//temp.m_trans.m_pos = Vector2(982, 725);
	//temp.m_img->renderUI(_hdc, &temp.m_trans);
	
	//UI렌더 순서 확인

	//간격차이 72
	//UIFront에 그리지 ㅏㅇㄶ으면 안보임
	for (int i = 0; i < m_inven.size(); i++)
	{
		m_inven[i].m_imgData.m_img->renderUI(_hdc, &m_inven[i].m_imgData.m_trans);
	}

	ImageData temp2;
	temp2.m_img = MG_IMAGE->findImage("testItem");
	temp2.m_trans.m_pos = Vector2(1053, 725);
	temp2.m_img->renderUI(_hdc, &temp2.m_trans);


}

void CInventorySystem::Release()
{
}


//==================================


void CInventorySystem::setItem()
{
	itemInfo torch;
	torch.m_imgData.m_img = MG_IMAGE->findImage("testItem");
	torch.m_imgData.m_trans.m_pos = Vector2(982, 725);
	torch.itemKind = ITEM::ITEM_CONSUMABLE;
	torch.name = "torch";
	torch.description = "+25 brightness";
	torch.count = MG_GAME->GetParty()->getTorch();
	m_inven.push_back(torch);

	//itemInfo food;
	//food.m_imgData.m_img = MG_IMAGE->findImage("testItem");
	//food.m_imgData.m_trans.m_pos = Vector2(500, 300);
	//food.itemKind = ITEM::ITEM_CONSUMABLE;
	//food.name = "food";
	//food.description = "+(1~3) HP";
	//food.count = MG_GAME->GetParty()->getFood();
	//m_inven.push_back(food);

	//itemInfo bandage;
	//bandage.m_imgData.m_img = MG_IMAGE->findImage("testItem");
	//bandage.m_imgData.m_trans.m_pos = Vector2(700, 300);
	//bandage.itemKind = ITEM::ITEM_CONSUMABLE;
	//bandage.name = "bandage";
	//bandage.description = "heals bleeding.";
	//bandage.count = MG_GAME->GetParty()->getBandage();
	//m_inven.push_back(bandage);

}

void CInventorySystem::setInven()
{
}

void CInventorySystem::setEquip()
{
}

void CInventorySystem::setButton()
{
	CButton* bt_iteractWithInvenItem = new CButton;
	bt_iteractWithInvenItem->m_spriteRenderer->SetImage("button2");
	bt_iteractWithInvenItem->m_transform->m_pos = Vector2(500, 500);

}

void CInventorySystem::showInvenItem()
{
}

void CInventorySystem::changePos()
{
}
