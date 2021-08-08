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
	Setquick();

	return S_OK;
}

void Abbey::Update(float deltaTime, float worldTime)
{
	if (isUi == true)
	{
		
		isUI = true;
		
	}
	
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
	}
}

void Abbey::Release()
{
	GameObject::Release();
}

void Abbey::Setquick()
{
	//나가기버튼
	CButton* m_quick = new CButton();
	m_quick->m_transform->m_pos = Vector2(WINSIZEX -500, 100);
	m_quick->SetButtonSize(200, 200);
	m_quick->AddSpriteRenderer("quick");
	m_quick->SetTriggerWhenClick(this, &Abbey::FinishUI);
	MG_GMOBJ->RegisterObj("quick", m_quick);
}

void Abbey::FinishUI()
{
	isUi = false;
	isUI = false;
}
