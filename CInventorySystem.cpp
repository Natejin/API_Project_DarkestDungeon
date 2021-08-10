#include "framework.h"
#include "CInventorySystem.h"
#include "CParty.h"
#include "CButton.h"

CInventorySystem::CInventorySystem() {}
CInventorySystem::~CInventorySystem() {}

HRESULT CInventorySystem::Init()
{
	return E_NOTIMPL;
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
	for (int i = 0; i < m_inven.size(); i++)
	{
		m_inven[i].m_imgData.m_img->renderUI(_hdc, &m_inven[i].m_imgData.m_trans);
	}
}

void CInventorySystem::FrontRender(HDC _hdc)
{
}

void CInventorySystem::Release()
{
}


//==================================


void CInventorySystem::setItem()
{
	itemInfo torch;
	torch.m_imgData.m_img = MG_IMAGE->findImage("");
	torch.m_imgData.m_trans.m_pos = Vector2(300, 300);
	torch.itemKind = ITEM::ITEM_CONSUMABLE;
	torch.name = "torch";
	torch.description = "+25 brightness";
	torch.count = MG_GAME->GetParty()->getTorch();
	m_inven.push_back(torch);

	itemInfo food;
	food.m_imgData.m_img = MG_IMAGE->findImage("");
	food.m_imgData.m_trans.m_pos = Vector2(500, 300);
	food.itemKind = ITEM::ITEM_CONSUMABLE;
	food.name = "food";
	food.description = "+(1~3) HP";
	food.count = MG_GAME->GetParty()->getFood();
	m_inven.push_back(food);

	itemInfo bandage;
	bandage.m_imgData.m_img = MG_IMAGE->findImage("");
	bandage.m_imgData.m_trans.m_pos = Vector2(700, 300);
	bandage.itemKind = ITEM::ITEM_CONSUMABLE;
	bandage.name = "bandage";
	bandage.description = "heals bleeding.";
	bandage.count = MG_GAME->GetParty()->getBandage();
	m_inven.push_back(bandage);

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
