#include "framework.h"
#include "CObjOnRoad.h"
#include "DungeonScene.h"
#include "CTransform.h"
#include "CCollider.h"
#include "CHero.h"
#include "CParty.h"

CObjOnRoad::CObjOnRoad() {}
CObjOnRoad::~CObjOnRoad() {}

HRESULT CObjOnRoad::Init()
{
	return S_OK;
}

HRESULT CObjOnRoad::Init(RoadObjType type, int index, bool _isPassed)
{
	m_layer = LAYER::BackGround;
    objType = type;
	isOpened = _isPassed;
	m_transform->m_pivot = Vector2(0.5, 1);

	AddSpriteRenderer();

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
		case RoadObjType::Tresure:
			m_spriteRenderer->SetImage(IMAGE::obj_treasure1);
			break;
		default:
			m_spriteRenderer->SetImage("button");
			break;
		}
	}
	else //passed
	{
		switch (objType)
		{
		case RoadObjType::Trap:
			m_spriteRenderer->SetImage(IMAGE::obj_trap1);
			break;

		case RoadObjType::Enemy:
			m_spriteRenderer->SetImage(IMAGE::NONE);
			break;

		case RoadObjType::Tresure:
			m_spriteRenderer->SetImage(IMAGE::obj_treasure1);
			break;

		default:
			m_spriteRenderer->SetImage("button");
			break;
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
	}

	setCollider();

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

void CObjOnRoad::setTreasureSlots()
{

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

	case RoadObjType::Tresure:
		Interaction_treassure();
		break;
	}
}

void CObjOnRoad::Interaction_treassure()
{
	//treasure
	//touchable when it's collision with Hero(0)
	if (m_collider->UICheckColliderBoxWithPoint(MG_GAME->GetHero(0)->m_transform->m_pos))
	{
		if (m_collider->CheckColliderBoxWithPoint(g_ptMouse))
		{
			if (MG_INPUT->isOnceKeyDown(VK_LBUTTON))
			{
				if (isOpened) return;
				else
				{
					if (MG_RND->getInt(10) > 0)
					{
						m_spriteRenderer->SetImage(IMAGE::obj_treasure2);

						int torch = MG_RND->getFromIntTo(1, 3);
						int food = MG_RND->getFromIntTo(1, 3);
						int band = MG_RND->getFromIntTo(1, 3);

						MG_GAME->GetParty()->setBandage(MG_GAME->GetParty()->getBandage() + band);
						MG_GAME->GetParty()->setFood(MG_GAME->GetParty()->getFood() + food);
						MG_GAME->GetParty()->setTorch(MG_GAME->GetParty()->getTorch() + torch);
						isOpened = true;
					}
					else
					{
						m_spriteRenderer->SetImage(IMAGE::nothing);
						isOpened = true;
					}
				}
			}
		}
	}
}

void CObjOnRoad::Interaction_trap()
{
	if (m_collider->UICheckColliderBoxWithPoint(MG_GAME->GetHero(0)->m_transform->m_pos))
	{
		if (m_collider->CheckColliderBoxWithPoint(g_ptMouse))
		{
			//이부분 추후 질문
			ImageData temp;
			temp.m_img = MG_IMAGE->findImage(IMAGE::obj_trap3);

			if (MG_INPUT->isOnceKeyDown(VK_LBUTTON))
			{
				m_spriteRenderer->SetImage(IMAGE::nothing);
				if (MG_RND->getInt(4) > 0)
				{
					Interaction_trap_success();
				}
				else
				{
					//tryed but fail
					Interaction_trap_fail();
				}
			}
		}
		else
		{
			//AddSpriteRenderer(IMAGE::obj_trap1);
		}
	}

	if (m_collider->UICheckColliderBoxWithPoint(MG_GAME->GetHero(0)->m_transform->m_pos - 50))
	{
		Interaction_trap_fail();
	}
}

void CObjOnRoad::Interaction_trap_fail()
{
	m_spriteRenderer->SetImage(IMAGE::obj_trap2);
	for (int i = 0; i < MG_GAME->GetHeroes().size(); i++)
	{
		if (MG_GAME->GetHero(i)->isSelected)
		{
			MG_GAME->GetHero(i)->setStress(MG_GAME->GetParty()->GetHero(0)->getStress() + MG_RND->getFromIntTo(10, 25));
		}
	}
	isOpened = true;
}

void CObjOnRoad::Interaction_trap_success()
{
	m_spriteRenderer->SetImage(IMAGE::obj_trap1);
	isOpened = true;
}

void CObjOnRoad::Interaction_battle()
{
	//isOpen = true;
	//m_spriteRenderer->SetImage(IMAGE::nothing);
}