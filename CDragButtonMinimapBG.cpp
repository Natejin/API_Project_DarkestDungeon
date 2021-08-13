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
	isDraged = false;
	moveOriginPosCurTime = 0;
	moveOriginPosCoolTime = 5;
	m_transform->m_pivot = Vector2(0, 0);
	return S_OK;
}

void CDragButtonMinimapBG::Update(float deltaTime, float worldTime)
{
	if (m_collider->new_CheckColliderBoxWithPoint(g_ptMouse))
	{
		if (MG_INPUT->isOnceKeyDown(VK_RBUTTON))
		{
			previousMousePoint = g_ptMouse;
		}

		if (MG_INPUT->isStayKeyDown(VK_RBUTTON))
		{
			m_pMapSystem->DragMinimap(previousMousePoint);
			moveOriginPosCurTime = moveOriginPosCoolTime + worldTime;
			previousMousePoint = g_ptMouse;
			isDraged = true;
		}

	
	}

	if (isDraged && moveOriginPosCurTime < worldTime)
	{
		isDraged = false;
		m_pMapSystem->SetMinimapPosOrigin();
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
	if (MG_INPUT->isToggleKey(VK_TAB))
	{
		RectangleMake(_hdc, m_collider->rect, m_transform->m_pos);
	}
}

void CDragButtonMinimapBG::SetMapSystem(CMapSystem* _mapSystem)
{
	m_pMapSystem = _mapSystem;
}
