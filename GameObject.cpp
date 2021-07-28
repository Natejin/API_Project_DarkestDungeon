#include "framework.h"
#include "GameObject.h"
#include "image.h"


GameObject::GameObject()
{
	m_image = nullptr;
	m_transform = new Transform;
	m_transform->m_pos = Vector2(0, 0);
	m_transform->m_scale = Vector2(0, 0);
	m_transform->m_pivot = Vector2(0.5, 0.5);
}

GameObject::~GameObject()
{
}

HRESULT GameObject::Init()
{
	return S_OK;
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
	SAFE_DELETE(m_transform)
	SAFE_DELETE(m_image);
}
