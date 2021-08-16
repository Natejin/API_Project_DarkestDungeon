#include "framework.h"
#include "CPosition_Button.h"

CPosition_Button::CPosition_Button()
{
	m_layer = LAYER::UIButton;
}

CPosition_Button::~CPosition_Button()
{
}

HRESULT CPosition_Button::Init()
{
	m_potionButton = new CSpriteRenderer(IMAGE::PositionButton_enable, m_transform);
	//m_potionButton->useCustomPos = true;
	m_potionButton->pos = m_transform->m_pos;
	m_transform->m_pivot = Vector2(0.5, 0.5);

	return S_OK;
}

void CPosition_Button::Update(float deltaTime, float worldTime)
{
	//각 스킬 버튼 누를때 활성하는 이미지로 set하고 싶다.
}

void CPosition_Button::LateUpdate()
{
}

void CPosition_Button::BackRender(HDC _hdc)
{
}

void CPosition_Button::Render(HDC _hdc)
{

}

void CPosition_Button::FrontRender(HDC _hdc)
{

	if (enable)
	{
		m_potionButton->RenderUI(_hdc);
	}
	else
	{
		m_spriteRenderer->RenderUI(_hdc);
	}
	if (MG_INPUT->isToggleKey(VK_TAB))
	{
		RectangleMake(_hdc, m_collider->rect, m_transform->m_pos);
	}
}

void CPosition_Button::Enable()
{
	isActive = true;
}

void CPosition_Button::Disable()
{
	isActive = false;
}

void CPosition_Button::Click(bool _enable)
{
	enable = _enable;
}
