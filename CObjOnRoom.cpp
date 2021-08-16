#include "framework.h"
#include "CObjOnRoom.h"
#include "CHero.h"
#include "DungeonScene.h"
#include "TreasureEventPanel.h"
#include "CMapSystem.h"

CObjOnRoom::CObjOnRoom() {}
CObjOnRoom::~CObjOnRoom() {}

HRESULT CObjOnRoom::Init()
{
	AddSpriteRenderer();
	AddColliderBox(200, 300);
	m_collider->SetColliderBox(Vector2(0, 0), Vector2(100, 100));
    return S_OK;
}

HRESULT CObjOnRoom::Init(RoomObjType type, bool _isPassed, bool _isOpened)
{
	isPassed = _isPassed;
	isOpened = _isOpened;

	m_layer = LAYER::BackGround;
	m_transform->m_pivot = Vector2(0.5, 1);
	objType = type;

	if (!isPassed)
	{
		//all obj is interactable
		switch (objType)
		{
		case RoomObjType::Treasure:
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
			case RoomObjType::Treasure:
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
			case RoomObjType::Treasure:
				m_spriteRenderer->SetImage(IMAGE::obj_treasure2);
				break;

			default:
				m_spriteRenderer->SetImage("button");
				break;
			}
		}
	}

	m_transform->m_pos.y = 665;
	m_transform->m_pos.x = 990;


	return S_OK;
}

void CObjOnRoom::Update(float deltaTime, float worldTime)
{
	if (!isOpened)
	{
		Interaction_treassure();
	}
}

void CObjOnRoom::LateUpdate()
{
}

void CObjOnRoom::BackRender(HDC _hdc)
{
	if (m_spriteRenderer->GetImage())
	{
		m_spriteRenderer->Render(_hdc);
	}
}

void CObjOnRoom::Render(HDC _hdc)
{
}

void CObjOnRoom::FrontRender(HDC _hdc)
{
	if (MG_INPUT->isToggleKey(VK_TAB))
	{
		RectangleMake(_hdc, m_collider->rect, m_transform->m_pos - MG_CAMERA->getCameraPos());
	}
}

void CObjOnRoom::Release()
{
}

void CObjOnRoom::setCollider()
{
	AddColliderBoxBigger();
}

void CObjOnRoom::Interaction_treassure()
{
	if (m_collider->UICheckColliderBoxWithPoint(MG_GAME->GetHero(0)->m_transform->m_pos + 40))
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