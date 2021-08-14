#include "framework.h"
#include "CObjOnRoad.h"
#include "DungeonScene.h"
#include "CTransform.h"

CObjOnRoad::CObjOnRoad() {}
CObjOnRoad::~CObjOnRoad() {}

HRESULT CObjOnRoad::Init()
{
	return S_OK;
}

HRESULT CObjOnRoad::Init(RoadObjType type, int index)
{
	m_layer = LAYER::BackGround;

	AddSpriteRenderer();

    objType = type;

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
	Interaction_collision();
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
		RectangleMake(_hdc, m_collider->rect, m_transform->m_pos);
	}
}

void CObjOnRoad::Release()
{

}

void CObjOnRoad::setCollider()
{
	AddColliderBox();
}

void CObjOnRoad::setRoadObj()
{
}

void CObjOnRoad::Interaction_collision()
{
}

void CObjOnRoad::Interaction_treassure()
{
}

void CObjOnRoad::Interaction_trap()
{
}

void CObjOnRoad::Interaction_trap_fail()
{
}

void CObjOnRoad::Interaction_trap_success()
{
}

void CObjOnRoad::Interaction_battle()
{
}
