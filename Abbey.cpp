#include "framework.h"
#include "Abbey.h"

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
	
	m_quick->m_transform->m_pos = Vector2(WINSIZEX - 500, 100);
	m_quick->SetButtonSize(200, 200);
	m_quick->AddSpriteRenderer("quick");
	MG_GMOBJ->RegisterObj("quick", m_quick);
	m_quick->isActive = false;

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
}

void Abbey::FrontRender(HDC _hdc)
{
	//m_spriteRenderer->RenderUI(_hdc);
	if (isUI == true)
	{
		MG_IMAGE->findImage("abbey.character.bg")->render(_hdc);
		MG_IMAGE->findImage("abbey.character")->render(_hdc);
		m_quick->isActive = true;
	}
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
