#include "framework.h"
#include "GameObject.h"
#include "image.h"


GameObject::GameObject()
{
}

GameObject::~GameObject()
{
}

HRESULT GameObject::Init()
{
	return E_NOTIMPL;
}

void GameObject::Update(float deltaTime, float worldTime)
{
}

void GameObject::LateUpdate()
{
}

void GameObject::BackRender(HDC _hdc)
{
}

void GameObject::Render(HDC _hdc)
{
}

void GameObject::FrontRender(HDC _hdc)
{
}

void GameObject::Release()
{
}
