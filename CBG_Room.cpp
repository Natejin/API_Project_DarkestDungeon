#include "framework.h"
#include "CBG_Room.h"

CBG_Room::CBG_Room() {}
CBG_Room::~CBG_Room() {}

HRESULT CBG_Room::Init()
{
	m_layer = LAYER::BackGround;
	bgCount = 10;
	roadCount = 6;
	SetIMG();
	return S_OK;
}

void CBG_Room::BackRender(HDC _hdc)
{
	m_spriteRenderer->Render(_hdc);
}

void CBG_Room::Render(HDC _hdc)
{
}

void CBG_Room::FrontRender(HDC _hdc)
{
}

void CBG_Room::SetIMG()
{
	m_transform->m_pivot = Vector2(0, 0);
}