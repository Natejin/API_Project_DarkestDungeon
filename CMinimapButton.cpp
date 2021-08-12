#include "framework.h"
#include "CMinimapButton.h"
#include "CMapSystem.h"

CMinimapButton::CMinimapButton()
{
	m_layer = LAYER::UIButton;
}

CMinimapButton::~CMinimapButton()
{
}

HRESULT CMinimapButton::Init()
{
	
	return S_OK;
}

void CMinimapButton::Update(float deltaTime, float worldTime)
{
	if (m_collider->new_CheckColliderBoxWithPoint(m_ptMouse))
	{
		if (m_transform->m_scale.x < 1.5)
		{
			m_transform->m_scale += 0.05;
		}
		if (MG_INPUT->isOnceKeyDown(VK_LBUTTON))
		{
			if (m_pMapSystem)
			{
				m_pMapSystem->UseClickToMoveCurPoint(dungeonData);
			}
		}
	}
	else {
		if (m_transform->m_scale.x > 1)
		{
			m_transform->m_scale -= 0.05;
		}
	}
}

void CMinimapButton::LateUpdate()
{
}

void CMinimapButton::BackRender(HDC _hdc)
{
	m_spriteRenderer->RenderUI(_hdc);
}

void CMinimapButton::Render(HDC _hdc)
{
	
}

void CMinimapButton::FrontRender(HDC _hdc)
{

}

void CMinimapButton::AddSpriteRenderer(IMAGE imageName)
{
	m_spriteRenderer = new CSpriteRenderer(imageName, m_transform);
	m_spriteRenderer->SetTrans(m_transform);
	m_spriteRenderer->SetImage(imageName);

	Vector2 imageSize = m_spriteRenderer->GetImageSize()/2;
	AddColliderBox(Vector2(0,0), -imageSize.x, -imageSize.y, imageSize.x, imageSize.y);
}

void CMinimapButton::SetMapSystem(CMapSystem* _mapSystem)
{
	m_pMapSystem = _mapSystem;
}
