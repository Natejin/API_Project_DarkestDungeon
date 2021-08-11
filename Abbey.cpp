#include "framework.h"
#include "Abbey.h"
#include "CBuilding.h"
#include "CButton.h"
#include "CDragButtion.h"
#include "CHeroList_button.h"
Abbey::Abbey()
{
	m_layer = LAYER::UI;
}

Abbey::~Abbey()
{
}

HRESULT Abbey::Init()
{
	isActive = false;

	m_quick = new CButton();
	m_quick->m_transform->m_pos = Vector2(WINSIZEX - 400, 100);
	m_quick->AddColliderBox(50, 50);
	m_quick->AddSpriteRenderer("quick");
	m_quick->isActive = false;
	m_quick->SetTriggerWhenDown(this, &Abbey::FinishUI);
	MG_GMOBJ->RegisterObj("quick", m_quick);
	
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

	m_windowPanelBG->Render(_hdc);
	m_windowPanelChar->Render(_hdc);
	m_quick->isActive = true;

}

void Abbey::FrontRender(HDC _hdc)
{
	//m_spriteRenderer->RenderUI(_hdc);
	if (MG_INPUT->isToggleKey(VK_TAB))
	{
		RectangleMake(_hdc, m_collider->rect, m_transform->m_pos);
	}
}

void Abbey::Release()
{
	GameObject::Release();
}

void Abbey::FinishUI()
{
	m_quick->isActive = false;
	isActive = false;
}
