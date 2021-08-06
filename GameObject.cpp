#include "framework.h"
#include "GameObject.h"
#include "CTransform.h"
#include "CCollider.h"
#include "CAnimator.h"
#include "CSpriteRenderer.h"
#include "image.h"

GameObject::GameObject()
{
	m_image = nullptr;
	m_transform = new CTransform;
	m_transform->m_pos = Vector2(0, 0);
	m_transform->m_scale = Vector2(1, 1);
	m_transform->m_pivot = Vector2(0.5, 0.5);
	m_transform->angle = 0;

	m_layer = LAYER::Unknown;
	isActive = true;
}
GameObject::~GameObject() {}

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
	SAFE_DELETE(m_transform);
	SAFE_DELETE(m_image);
	SAFE_DELETE(m_collider);
}

void GameObject::AddColliderBox(Vector2 pos, 
	float l,
	float t, 
	float r, 
	float b)
{
	m_collider->m_pos = pos;
	m_collider->rect.l = l;
	m_collider->rect.t = t;
	m_collider->rect.r = r;
	m_collider->rect.b = b;
	m_collider->m_colliderType = COLLIDERTYPE::BOX;
}

void GameObject::AddAnimator(string imageName)
{
	m_animator = new CAnimator();
	m_animator->SetTrans(m_transform);
	m_animator->AddImageFrame(imageName);
}

void GameObject::AddAnimator(IMAGE imageName)
{
	m_animator = new CAnimator();
	m_animator->SetTrans(m_transform);
	m_animator->AddImageFrame(imageName);
}

void GameObject::AddSpriteRenderer(IMAGE imageName)
{
	m_spriteRenderer = new CSpriteRenderer();
	m_spriteRenderer->SetTrans(m_transform);
	m_spriteRenderer->SetImage(imageName);
}

void GameObject::AddSpriteRenderer(string imageName)
{
	m_spriteRenderer = new CSpriteRenderer();
	m_spriteRenderer->SetTrans(m_transform);
	m_spriteRenderer->SetImage(imageName);
}

