#include "framework.h"
#include "CBuilding.h"

CBuilding::CBuilding() 
{
	m_layer = LAYER::Building;
	countNum = 0;
}

CBuilding::~CBuilding()
{
}

HRESULT CBuilding::Init()
{
	m_transform->m_pivot = Vector2(0.5,0.5);
	return S_OK;
}


void CBuilding::BackRender(HDC _hdc)
{
}

void CBuilding::Render(HDC _hdc)
{
	m_spriteRenderer->Render(_hdc);

#ifdef _DEBUG
	if (MG_INPUT->isToggleKey(VK_TAB))
	{
		RectangleMake(_hdc, m_collider->rect, m_transform->m_pos);
	}

#endif // _DEBUG
}

void CBuilding::FrontRender(HDC _hdc)
{

}

