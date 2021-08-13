#include "framework.h"
#include "Unit.h"

Unit::Unit() {
    unitType = UNITTYPE::NONE;
}
Unit::~Unit() {}

HRESULT Unit::Init()
{
    return S_OK;
}

void Unit::Update(float deltaTime, float worldTime)
{
}

void Unit::LateUpdate()
{
}

void Unit::BackRender(HDC _hdc)
{
}

void Unit::Render(HDC _hdc)
{
}

void Unit::FrontRender(HDC _hdc)
{
}

void Unit::Release()
{
    GameObject::Release();
}