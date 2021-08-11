#include "framework.h"
#include "slot.h"

slot::slot() {}
slot::~slot() {}

HRESULT slot::Init()
{
	LAYER::UIButton;

	return S_OK;
}

void slot::Update(float deltaTime, float worldTime)
{
}

void slot::LateUpdate()
{
}

void slot::BackRender(HDC _hdc)
{
}

void slot::Render(HDC _hdc)
{
}

void slot::FrontRender(HDC _hdc)
{
}
