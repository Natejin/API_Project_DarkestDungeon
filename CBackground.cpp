#include "framework.h"
#include "CBackground.h"

CBackground::CBackground() {}
CBackground::~CBackground() {}

HRESULT CBackground::Init()
{
    m_layer = LAYER::BackGround;
    return S_OK;
}

void CBackground::Update(float deltaTime, float worldTime)
{
}

void CBackground::LateUpdate()
{
}

void CBackground::BackRender(HDC _hdc)
{
    m_image->render(_hdc, m_transform);
}

void CBackground::Render(HDC _hdc)
{
}

void CBackground::FrontRender(HDC _hdc)
{
}

void CBackground::Release()
{
}
