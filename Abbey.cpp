#include "framework.h"
#include "Abbey.h"
#include "CButton.h"
#include "CHeroList_button.h"
#include "TownScene.h"
Abbey::Abbey()
{

}

Abbey::~Abbey()
{
}

HRESULT Abbey::Init()
{
	CEst_UI::Init();
	isActive = false;

	m_windowPanelBG = new CSpriteRenderer(IMAGE::abbey_bg, m_transform);
	m_windowPanelChar = new CSpriteRenderer(IMAGE::abbey_char, m_transform);
	m_transform->m_pivot = Vector2(-0.095,-0.095);

	m_HeroList_button = new CHeroList_button();
	
	return S_OK;
}

void Abbey::Update(float deltaTime, float worldTime)
{
	
}

void Abbey::LateUpdate()
{
}

void Abbey::BackRender(HDC _hdc)
{
}

void Abbey::Render(HDC _hdc)
{

}
void Abbey::FrontRender(HDC _hdc)
{
	m_windowPanelBG->Render(_hdc);
	m_windowPanelChar->Render(_hdc);
	m_quick->isActive = true;

	
}

void Abbey::Release()
{
	
}


