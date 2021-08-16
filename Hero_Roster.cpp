#include "framework.h"
#include "Hero_Roster.h"
#include"CHero.h"
#include "TownScene.h"
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
	m_transform->m_pivot = Vector2(0.5, 0.5);
	AddSpriteRenderer();

    return S_OK;
}

void Hero_Roster::Update(float deltaTime, float worldTime)
{
	m_transform->m_pos = g_ptMouse;
}

void Hero_Roster::LateUpdate()
{
	if (MG_INPUT->IsUpLMB())
	{
		scene->isDrag = false;
		scene->curDragHeroIndex = -1;
		Disable();
	}
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
}
