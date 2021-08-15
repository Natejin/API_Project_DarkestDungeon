#include "framework.h"
#include "CObjOnRoom.h"

CObjOnRoom::CObjOnRoom() {}
CObjOnRoom::~CObjOnRoom() {}

HRESULT CObjOnRoom::Init()
{
    return S_OK;
}

HRESULT CObjOnRoom::Init(RoadObjType type, int index, bool isPassed)
{
	m_layer = LAYER::BackGround;
	objType = type;
	isOpened = isPassed;
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
			m_spriteRenderer->SetImage(IMAGE::enemy);
			break;
		case RoadObjType::Tresure:
			m_spriteRenderer->SetImage(IMAGE::obj_treasure1);
			break;
		default:
			m_spriteRenderer->SetImage("button");
			break;
		}
	}
	else
	{
		switch (objType)
		{
		case RoadObjType::Trap:
			m_spriteRenderer->SetImage(IMAGE::obj_trap2);
			break;

		case RoadObjType::Enemy:
			m_spriteRenderer->SetImage(IMAGE::enemy);
			break;

		case RoadObjType::Tresure:
			m_spriteRenderer->SetImage(IMAGE::obj_treasure2);
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

void CObjOnRoom::Update(float deltaTime, float worldTime)
{
}

void CObjOnRoom::LateUpdate()
{
}

void CObjOnRoom::BackRender(HDC _hdc)
{
}

void CObjOnRoom::Render(HDC _hdc)
{
}

void CObjOnRoom::FrontRender(HDC _hdc)
{
}

void CObjOnRoom::Release()
{
}

void CObjOnRoom::setCollider()
{
}

void CObjOnRoom::setTreasureSlots()
{
}

void CObjOnRoom::Interaction_collision()
{
}

void CObjOnRoom::Interaction_treassure()
{
}

void CObjOnRoom::Interaction_battle()
{
}
