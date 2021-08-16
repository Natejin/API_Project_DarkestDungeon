#include "framework.h"
#include "CObjOnRoad.h"
#include "DungeonScene.h"
#include "CTransform.h"
#include "CCollider.h"
#include "CHero.h"
#include "CParty.h"
#include "TreasureEventPanel.h"
#include "DungeonScene.h"
#include "CBattleSystem.h"
#include "CMapSystem.h"

CObjOnRoad::CObjOnRoad() {}
CObjOnRoad::~CObjOnRoad() {}

HRESULT CObjOnRoad::Init()
{
	AddSpriteRenderer();
	AddColliderBox(300,300);
	m_collider->SetColliderBox(Vector2(0, 0), Vector2(100, 100));
	return S_OK;
}

HRESULT CObjOnRoad::Init(RoadObjType type, int index, bool _isPassed, bool _isOpened)
{
	isPassed = _isPassed;
	isOpened = _isOpened;

	m_layer = LAYER::BackGround;
	m_transform->m_pivot = Vector2(0.5, 1);
    objType = type;

	if (index != 3)
	{
		if (!isPassed)
		{
			//all obj is interactable
			switch (objType)
			{
			case RoadObjType::Trap:
				m_spriteRenderer->SetImage(IMAGE::obj_trap1);
				break;

			case RoadObjType::Enemy:
				m_spriteRenderer->SetImage(IMAGE::NONE);
				break;

			case RoadObjType::Treasure:
				m_spriteRenderer->SetImage(IMAGE::obj_treasure1);
				break;

			default:
				m_spriteRenderer->SetImage(IMAGE::NONE);
				break;
			}
		}
		else //passedWay
		{
			if (!isOpened)
			{
				switch (objType)
				{
				case RoadObjType::Trap:
					m_spriteRenderer->SetImage(IMAGE::obj_trap1);
					break;

				case RoadObjType::Enemy:
					m_spriteRenderer->SetImage(IMAGE::NONE);
					break;

				case RoadObjType::Treasure:
					m_spriteRenderer->SetImage(IMAGE::obj_treasure1);
					break;

				default:
					m_spriteRenderer->SetImage(IMAGE::NONE);
					break;
				}
			}
			else //opened
			{
				switch (objType)
				{
				case RoadObjType::Trap:
					m_spriteRenderer->SetImage(IMAGE::obj_trap2);
					break;

				case RoadObjType::Enemy:
					m_spriteRenderer->SetImage(IMAGE::NONE);
					break;

				case RoadObjType::Treasure:
					m_spriteRenderer->SetImage(IMAGE::obj_treasure2);
					break;

				default:
					m_spriteRenderer->SetImage(IMAGE::NONE);
					break;
				}
			}
		}
	}
	else {
		if (!isPassed)
		{
			//all obj is interactable
			switch (objType)
			{
			case RoadObjType::Treasure:
				m_spriteRenderer->SetImage(IMAGE::obj_treasure1);
				break;

			default:
				m_spriteRenderer->SetImage(IMAGE::NONE);
				break;
			}
		}
		else //passedWay
		{
			if (!isOpened)
			{
				switch (objType)
				{
				case RoadObjType::Treasure:
					m_spriteRenderer->SetImage(IMAGE::obj_treasure1);
					break;

				default:
					m_spriteRenderer->SetImage("button");
					break;
				}
			}
			else //opened
			{
				switch (objType)
				{
				case RoadObjType::Treasure:
					m_spriteRenderer->SetImage(IMAGE::obj_treasure2);
					break;

				default:
					m_spriteRenderer->SetImage("button");
					break;
				}
			}
		}
	}
	

	m_transform->m_pos.y = 665;

	int limitDistance = 100;

	switch (index)
	{

	case 0:
		m_transform->m_pos.x = MG_RND->getFromIntTo(ROOMSIZE, ROOMSIZE * 2 - limitDistance);
		break;
	case 1:
		m_transform->m_pos.x = MG_RND->getFromIntTo(ROOMSIZE * 2 + limitDistance, ROOMSIZE * 4 - limitDistance);
		break;
	case 2:
		m_transform->m_pos.x = MG_RND->getFromIntTo(ROOMSIZE * 4 + limitDistance, ROOMSIZE * 5);
		break;
	case 3:
		m_transform->m_pos.x = 990;
	}

    return S_OK;
}

void CObjOnRoad::Update(float deltaTime, float worldTime)
{
	if (!isOpened)
	{
		Interaction_collision();
	}
}

void CObjOnRoad::LateUpdate()
{

}

void CObjOnRoad::BackRender(HDC _hdc)
{
	if (m_spriteRenderer->GetImage())
	{
		m_spriteRenderer->Render(_hdc);
	}
}

void CObjOnRoad::Render(HDC _hdc)
{
}

void CObjOnRoad::FrontRender(HDC _hdc)
{
	if (MG_INPUT->isToggleKey(VK_TAB))
	{
		RectangleMake(_hdc, m_collider->rect, m_transform->m_pos - MG_CAMERA->getCameraPos());
	}
}

void CObjOnRoad::Release()
{

}

void CObjOnRoad::setCollider()
{
	AddColliderBoxBigger();
}

void CObjOnRoad::Interaction_collision()
{
	switch (objType)
	{
	case RoadObjType::Trap:
		Interaction_trap();
		break;

	case RoadObjType::Enemy:
		Interaction_battle();
		break;

	case RoadObjType::Treasure:
		Interaction_treassure();
		break;
	}
}

void CObjOnRoad::Interaction_treassure()
{
	//treasure
	//touchable when it's collision with Hero(0)
	if (m_collider->UICheckColliderBoxWithPoint(MG_GAME->GetHero(0)->m_transform->m_pos + 100))
	{
		if (m_collider->CheckColliderBoxWithPoint(g_ptMouse))
		{
			if (MG_INPUT->isOnceKeyDown(VK_LBUTTON))
			{
				m_spriteRenderer->SetImage(IMAGE::obj_treasure2);
				m_dungeonScene->m_treasurePanel->Enable();
				m_dungeonScene->m_pMapSystem->SetIsOpened();
				isOpened = true;
			}
		}
	}
}

void CObjOnRoad::Interaction_trap()
{
	if (m_collider->UICheckColliderBoxWithPoint(MG_GAME->GetHero(0)->m_transform->m_pos + 120))
	{
		if (m_collider->CheckColliderBoxWithPoint(g_ptMouse))
		{
			//테두리 필요
			if (MG_INPUT->isOnceKeyDown(VK_LBUTTON))
			{
				if (MG_RND->getInt(4) > 0)
				{
					Interaction_trap_success();
				}
				else
				{
					Interaction_trap_fail();
				}
				m_dungeonScene->m_pMapSystem->SetIsOpened();
				isOpened = true;
			}
		}
	}

	if (m_collider->UICheckColliderBoxWithPoint(MG_GAME->GetHero(0)->m_transform->m_pos - 50))
	{
		Interaction_trap_fail();
		m_dungeonScene->m_pMapSystem->SetIsOpened();
		isOpened = true;
	}
}

void CObjOnRoad::Interaction_trap_fail()
{
	m_spriteRenderer->SetImage(IMAGE::obj_trap2);
	for (int i = 0; i < MG_GAME->GetHeroes().size(); i++)
	{
		if (MG_GAME->GetHero(i)->isSelected)
		{
			MG_GAME->GetHero(i)->setStress(MG_GAME->GetParty()->GetHero(i)->getStress() + MG_RND->getFromIntTo(10, 25));
			break;
		}
	}
}

void CObjOnRoad::Interaction_trap_success()
{
	m_spriteRenderer->SetImage(IMAGE::obj_trap3);
}

void CObjOnRoad::Interaction_battle()
{
	if (m_collider->UICheckColliderBoxWithPoint(MG_GAME->GetHero(0)->m_transform->m_pos))
	{
		m_dungeonScene->m_pBattleSystem->BattleSystemInitiate();
		m_dungeonScene->m_pMapSystem->SetIsOpened();
		isOpened = true;
	}
}