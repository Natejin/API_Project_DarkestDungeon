#include "framework.h"
#include "CInventorySystem.h"
#include "CParty.h"
#include "CButton.h"

CInventorySystem::CInventorySystem() {}
CInventorySystem::~CInventorySystem() {}

HRESULT CInventorySystem::Init()
{
	m_layer = LAYER::UI;
	setItem();
	return S_OK;
}

void CInventorySystem::Update(float deltaTime, float worldTime)
{
	updateItem();
	//interactWithItem();
}

void CInventorySystem::LateUpdate()
{
}

void CInventorySystem::BackRender(HDC _hdc)
{
}

void CInventorySystem::Render(HDC _hdc)
{
	showInvenItem(_hdc);

}

void CInventorySystem::FrontRender(HDC _hdc)
{
	char str[256];
	string strFrame;
	SetBkMode(_hdc, RGB(0, 0, 0));
	SetTextColor(_hdc, RGB(255, 255, 255));
	sprintf_s(str, "%d", m_inven[0].count);
	TextOut(_hdc, 990, 730, str, strlen(str));

	sprintf_s(str, "%d", m_inven[1].count);
	TextOut(_hdc, 1060, 730, str, strlen(str));

	sprintf_s(str, "%d", m_inven[2].count);
	TextOut(_hdc, 1130, 730, str, strlen(str));

}

void CInventorySystem::Release()
{
}


//==================================


void CInventorySystem::setItem()
{
	itemInfo torch;
	torch.m_imgData.m_img = MG_IMAGE->findImage("torch");
	torch.m_imgData.m_trans.m_pos = Vector2(982, 725);
	torch.itemKind = ITEM::ITEM_CONSUMABLE;
	torch.name = "torch";
	torch.description = "+25 brightness";
	torch.count = MG_GAME->GetParty()->getTorch();
	m_inven.push_back(torch);

	itemInfo food;
	food.m_imgData.m_img = MG_IMAGE->findImage("food1");
	food.m_imgData.m_trans.m_pos = Vector2(1052, 725);
	food.itemKind = ITEM::ITEM_CONSUMABLE;
	food.name = "food";
	food.description = "+(1~3) HP";
	food.count = MG_GAME->GetParty()->getFood();
	m_inven.push_back(food);

	itemInfo bandage;
	bandage.m_imgData.m_img = MG_IMAGE->findImage("bandage");
	bandage.m_imgData.m_trans.m_pos = Vector2(1122, 725);
	bandage.itemKind = ITEM::ITEM_CONSUMABLE;
	bandage.name = "bandage";
	bandage.description = "heals bleeding.";
	bandage.count = MG_GAME->GetParty()->getBandage();
	m_inven.push_back(bandage);

	m_inven[0].count = MG_GAME->GetParty()->getTorch();
	m_inven[1].count = MG_GAME->GetParty()->getFood();
	m_inven[2].count = MG_GAME->GetParty()->getBandage();

}

void CInventorySystem::setInven()
{
}

void CInventorySystem::setEquip()
{
}

void CInventorySystem::setButton()
{
	CButton* bt_iteractWithInvenItem = new CButton();
	bt_iteractWithInvenItem->m_transform->m_pos = Vector2(982, 725);
	bt_iteractWithInvenItem->SetButtonSize(70, 135);
	bt_iteractWithInvenItem->m_spriteRenderer->SetImage("button");
	bt_iteractWithInvenItem->SetTriggerWhenClick(this, &CInventorySystem::interactWithItem);
	MG_GMOBJ->RegisterObj("bt_invenInteract", bt_iteractWithInvenItem);
}

void CInventorySystem::updateItem()
{
	m_inven[0].count = MG_GAME->GetParty()->getTorch();
	m_inven[1].count = MG_GAME->GetParty()->getFood();
	m_inven[2].count = MG_GAME->GetParty()->getBandage();

}

void CInventorySystem::showInvenItem(HDC _hdc)
{
	//간격차이 72
	for (int i = 0; i < m_inven.size(); i++)
	{
		m_inven[i].m_imgData.m_img->renderUI(_hdc, &m_inven[i].m_imgData.m_trans);
	}



}

void CInventorySystem::changePos()
{
}

void CInventorySystem::interactWithItem()
{
	CCollider* _collider = new CCollider;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			_collider->SetRect(982 + 70 * i, 725 + 135 * j, 982 + 70 * (i + 1), 725 + 135 * (j + 1));
			if (_collider->CheckColliderBoxWithPoint(m_ptMouse))
			{
				if (m_inven[i * (j + 1)].count != NULL) m_inven[i * (j + 1)].count--;
				MG_GAME->GetParty()->setTorch(m_inven[0].count);
				MG_GAME->GetParty()->setFood(m_inven[1].count);
				MG_GAME->GetParty()->setBandage(m_inven[2].count);
			}
		}
	}
}