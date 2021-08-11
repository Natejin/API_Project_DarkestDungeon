#include "framework.h"
#include "CInventorySystem.h"
#include "CParty.h"
#include "CButton.h"

#include "CCollider.h"

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
	showInvenItem(_hdc);

	int k = 0;
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
	//�������� 72
	for (int i = 0; i < m_inven.size(); i++)
	{
		m_inven[i].m_imgData.m_img->renderUI(_hdc, &m_inven[i].m_imgData.m_trans);
	}



}

void CInventorySystem::changePos()
{
	////�巡���Ͽ� �ű��
	//CCollider* _collider = new CCollider;
	//for (int j = 0; j < 2; j++)
	//{
	//	for (int i = 0; i < 8; i++)
	//	{
	//		_collider->SetRect(982 + 70 * i, 725 + 135 * j, 982 + 70 * (i + 1), 725 + 135 * (j + 1));
	//		if (_collider->CheckColliderBoxWithPoint(m_ptMouse))
	//		{
	//			if (MG_INPUT->isStayKeyDown(VK_LBUTTON))
	//			{

	//			}
	//		}
	//	}
	//}
}

void CInventorySystem::interactWithItem()
{
	//CCollider* _collider = new CCollider;
	//for (int j = 0; j < 2; j++)
	//{
	//	for (int i = 0; i < 8; i++)
	//	{
	//		_collider->SetRect(982 + 70 * i, 725 + 135 * j, 982 + 70 * (i + 1), 725 + 135 * (j + 1));
	//		if (_collider->CheckColliderBoxWithPoint(m_ptMouse))
	//		{
	//			if (m_inven[i * (j + 1)].itemKind == ITEM::ITEM_NONE) continue;
	//			else if (m_inven[i * (j + 1)].itemKind == ITEM::ITEM_CONSUMABLE)
	//			{
	//				if (m_inven[i * (j + 1)].count > 0)
	//				{
	//					useConsumableItem(i * (j + 1));
	//				}
	//			}
	//			MG_GAME->GetParty()->setTorch(m_inven[0].count);
	//			MG_GAME->GetParty()->setFood(m_inven[1].count);
	//			MG_GAME->GetParty()->setBandage(m_inven[2].count);
	//		}
	//	}
	//}
}

void CInventorySystem::useConsumableItem(int itemInfoIndex)
{
	if (itemInfoIndex == 0)
	{
		if (MG_GAME->GetParty()->getBrightness() < 100)
		{
			m_inven[0].count--;
			if (MG_GAME->GetParty()->getBrightness() + 20 > 100) MG_GAME->GetParty()->setBrightness(100);
			else MG_GAME->GetParty()->setBrightness(MG_GAME->GetParty()->getBrightness() + 20);
		}
		else return;
	}

	if (itemInfoIndex == 1)
	{
		int SelMemIndex;
		for (int i = 0; i < MG_GAME->GetHeroes().size(); i++)
		{
			if (MG_GAME->GetHero(i)->isSelected) SelMemIndex = i;

		}
		if (MG_GAME->GetHero(SelMemIndex)->getHP() < 25) //���� fullHp�� �ƴ� ��츦 ������ ��
		{
			MG_GAME->GetHero(SelMemIndex)->setHP(MG_GAME->GetHero(SelMemIndex)->getHP() + MG_RND->getFromIntTo(1, 4));
			m_inven[1].count--;
		}
		else return;
	}

	//���� ���¸� ������ �ڿ� �ϼ��� ��
	if (itemInfoIndex == 2)
	{
		m_inven[2].count--;
	}
}

void CInventorySystem::setEmptyItem()
{
	none.m_imgData.m_img = MG_IMAGE->findImage("button");
	none.itemKind = ITEM::ITEM_NONE;
	none.name = "nothing";
	none.description = "empty.";
	none.count = 0;
	for (int j = 0; j < 2; j++)
	{
		for (int i = 0; i < 8; i++)
		{
			if (i == 0 && j == 0 || i == 1 && j == 0 || i == 2 && j == 0) continue;
			none.m_imgData.m_trans.m_pos = Vector2(982 + 70 * i, 725 + 135 * j);
			m_inven.push_back(none);
		}
	}
}