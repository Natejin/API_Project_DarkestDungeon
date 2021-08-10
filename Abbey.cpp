#include "framework.h"
#include "Abbey.h"
#include "CBuilding.h"
#include "CButton.h"
#include "CDragButtion.h"
Abbey::Abbey()
{
	m_layer = LAYER::UI;
}

Abbey::~Abbey()
{
}

HRESULT Abbey::Init()
{
	isUi = false;

	m_quick = new CButton();
	m_quick->m_transform->m_pos = Vector2(WINSIZEX - 400, 100);
	m_quick->SetButtonSize(50, 50);
	m_quick->AddSpriteRenderer("quick");
	MG_GMOBJ->RegisterObj("quick", m_quick);
	m_quick->isActive = false;
	
	
	m_windowPanelBG = new CSpriteRenderer(IMAGE::abbey_bg, m_transform);
	m_windowPanelChar = new CSpriteRenderer(IMAGE::abbey_char, m_transform);
	m_transform->m_pivot = Vector2(-0.095,-0.095);

	return S_OK;
}

void Abbey::Update(float deltaTime, float worldTime)
{
	if (isUi == true)
	{
		
		isUI = true;
		
	}
	Setquick();
}

void Abbey::LateUpdate()
{
}

void Abbey::BackRender(HDC _hdc)
{
}

void Abbey::Render(HDC _hdc)
{
	if (isUI == true)
	{
		m_windowPanelBG->Render(_hdc);
		m_windowPanelChar->Render(_hdc);
		m_quick->isActive = true;
	}
}

void Abbey::FrontRender(HDC _hdc)
{
	//m_spriteRenderer->RenderUI(_hdc);
	
}

void Abbey::Release()
{
	GameObject::Release();
}

void Abbey::Setquick()
{
	//나가기버튼	
	
	m_quick->SetTriggerWhenClick(this, &Abbey::FinishUI);

}

void Abbey::FinishUI()
{
	isUi = false;
	isUI = false;
	m_quick->isActive = false;
}
