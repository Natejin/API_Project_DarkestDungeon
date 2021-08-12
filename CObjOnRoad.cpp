#include "framework.h"
#include "CObjOnRoad.h"
#include "DungeonScene.h"
#include "CTransform.h"
CObjOnRoad::CObjOnRoad()
{
}

CObjOnRoad::~CObjOnRoad()
{
}

HRESULT CObjOnRoad::Init()
{
	AddSpriteRenderer();
	AddColliderBox(200, 200);

	return S_OK;
}

HRESULT CObjOnRoad::Init(RoadObjType type, int index)
{
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
	default:
		m_spriteRenderer->SetImage(IMAGE::enemy);
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
	default:
		break;
	}


    return S_OK;
}


void CObjOnRoad::Update(float deltaTime, float worldTime)
{

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
