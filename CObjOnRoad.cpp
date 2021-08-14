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

HRESULT CObjOnRoad::Init(RoadObjType type, int index, bool isPassed)
{
	m_layer = LAYER::BackGround;
    objType = type;
	isOpen = isPassed;

	AddSpriteRenderer();

	if (!isOpen)
	{
		switch (objType)
		{
		case RoadObjType::Trap:
			m_spriteRenderer->SetImage(IMAGE::trap);
			break;
		case RoadObjType::Enemy:
			m_spriteRenderer->SetImage(IMAGE::enemy);
			break;
		case RoadObjType::Tresure:
			m_spriteRenderer->SetImage(IMAGE::treasure);
			break;
		}

	}
	else {
		m_spriteRenderer->SetImage(IMAGE::nothing);
	}

	m_transform->m_pos.y = 600;

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
	if (!isOpen)
	{
		Interaction_collision();

		if (m_collider->CheckColliderBoxWithPoint(g_ptMouse))
		{
			Interaction_trap_fail();
		}
	}
	}
	

void CObjOnRoad::LateUpdate()
{

}

void CObjOnRoad::BackRender(HDC _hdc)
{

}


void CObjOnRoad::Render(HDC _hdc)
{
	if (m_spriteRenderer->GetImage())
	{
		m_spriteRenderer->Render(_hdc);
	}
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
	AddColliderBox();
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


	
	if (m_collider->CheckColliderBoxWithPoint(MG_GAME->GetHero(0)->m_transform->m_pos - MG_CAMERA->GetPos()))
	{		
		m_spriteRenderer->SetImage(IMAGE::nothing);
		//if (m_collider->CheckColliderBoxWithPoint(PointToVector))
		//{
		//	if (MG_INPUT->isOnceKeyDown(VK_LBUTTON))
		//	{
		//		if (isOpen) return;
		//		else
		//		{
		//			if (MG_RND->getInt(10) > 0)
		//			{
		//				m_spriteRenderer->SetImage(IMAGE::nothing);

		//				int torch = MG_RND->getFromIntTo(1, 3);
		//				int food = MG_RND->getFromIntTo(1, 3);
		//				int band = MG_RND->getFromIntTo(1, 3);

		//				MG_GAME->GetParty()->setBandage(MG_GAME->GetParty()->getBandage() + band);
		//				MG_GAME->GetParty()->setFood(MG_GAME->GetParty()->getFood() + food);
		//				MG_GAME->GetParty()->setTorch(MG_GAME->GetParty()->getTorch() + torch);
		//				isOpen = true;
		//			}
		//			else
		//			{
		//				m_spriteRenderer->SetImage(IMAGE::nothing);
		//				isOpen = true;
		//			}
		//		}
		//	}
		//}
	}
}

void CObjOnRoad::Interaction_trap()
{
	//Vector2 PointToVector = Vector2(g_ptMouse) + MG_CAMERA->getCameraPos();
	if (m_collider->CheckColliderBoxWithPoint(MG_GAME->GetHero(0)->m_transform->m_pos - MG_CAMERA->GetPos()))
	{
		if (isOpen) return;
	//	else
	//	{
	//		Vector2 PointToVector = Vector2(g_ptMouse) + MG_CAMERA->getCameraPos();
	//		if (m_collider->CheckColliderBoxWithPoint(PointToVector))
	//		{
	//			m_spriteRenderer->SetImage(IMAGE::nothing);
	//			if (MG_RND->getInt(4) > 0)
	//			{
	//				Interaction_trap_success();
	//			}
	//			else
	//			{
	//				//tryed but fail
	//				Interaction_trap_fail();
	//			}
	//		}
	//	}
	}
	
	if (isOpen) return;
	if (m_collider->CheckColliderBoxWithPoint(MG_GAME->GetHero(0)->m_transform->m_pos - MG_CAMERA->GetPos()))
	{
		Interaction_trap_fail();
	}
}

void CObjOnRoad::Interaction_trap_fail()
{
	m_spriteRenderer->SetImage(IMAGE::nothing);
	MG_GAME->GetParty()->GetHero(MG_RND->getInt(3))->setStress(MG_GAME->GetParty()->GetHero(0)->getStress() + MG_RND->getFromIntTo(10, 20));
	isOpen = true;
}

void CObjOnRoad::Interaction_trap_success()
{
	m_spriteRenderer->SetImage(IMAGE::nothing);
	isOpen = true;
}

void CObjOnRoad::Interaction_battle()
{
	m_spriteRenderer->SetImage(IMAGE::nothing);
	MG_GAME->GetParty()->GetHero(MG_RND->getInt(3))->setStress(MG_GAME->GetParty()->GetHero(0)->getStress() + MG_RND->getFromIntTo(10, 20));
	isOpen = true;

	m_spriteRenderer->SetImage(IMAGE::nothing);
}