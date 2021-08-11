#include "framework.h"
#include "CDragButtonMinimapBG.h"
#include "CMapSystem.h"
CDragButtonMinimapBG::CDragButtonMinimapBG()
{
	m_layer = LAYER::MinimapBackground;
	canTriggerDrag = false;
}

CDragButtonMinimapBG::~CDragButtonMinimapBG()
{
}

HRESULT CDragButtonMinimapBG::Init()
{
	
	m_transform->m_pivot = Vector2(0, 0);
	return S_OK;
}

void CDragButtonMinimapBG::Update(float deltaTime, float worldTime)
{
	if (m_collider->new_CheckColliderBoxWithPoint(m_ptMouse))
	{
		if (MG_INPUT->isOnceKeyDown(VK_RBUTTON))
		{
			previousMousePoint = m_ptMouse;
		}

		if (MG_INPUT->isStayKeyDown(VK_RBUTTON))
		{
			m_pMapSystem->DragMinimap(previousMousePoint);
			previousMousePoint = m_ptMouse;
		}


	}

}

void CDragButtonMinimapBG::LateUpdate()
{
}

void CDragButtonMinimapBG::BackRender(HDC _hdc)
{
	m_spriteRenderer->RenderUI(_hdc);
}

void CDragButtonMinimapBG::Render(HDC _hdc)
{

}

void CDragButtonMinimapBG::FrontRender(HDC _hdc)
{
	//m_spriteRenderer->RenderUI(_hdc);
}

void CDragButtonMinimapBG::SetMapSystem(CMapSystem* _mapSystem)
{
	m_pMapSystem = _mapSystem;
}
