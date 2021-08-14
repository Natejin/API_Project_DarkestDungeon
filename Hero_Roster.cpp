#include "framework.h"
#include "Hero_Roster.h"
#include"CHero.h"
Hero_Roster::Hero_Roster()
{
	m_layer = LAYER::UIButton;
	//hasHero = false;
}

Hero_Roster::~Hero_Roster()
{
}

HRESULT Hero_Roster::Init()
{
	m_transform->m_pivot = Vector2(0, 0);
	AddSpriteRenderer();

    return S_OK;
}

void Hero_Roster::Update(float deltaTime, float worldTime)
{
	m_transform->m_pos = g_ptMouse;
}

void Hero_Roster::LateUpdate()
{
}

void Hero_Roster::BackRender(HDC _hdc)
{
}

void Hero_Roster::Render(HDC _hdc)
{
}

void Hero_Roster::FrontRender(HDC _hdc)
{
	m_spriteRenderer->RenderUI(_hdc);
	if (MG_INPUT->isToggleKey(VK_TAB))
	{
		RectangleMake(_hdc, m_collider->rect, m_transform->m_pos);
	}
}
