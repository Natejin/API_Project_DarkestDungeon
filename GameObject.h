#pragma once
#include "Object.h"


class GameObject : public Object
{
public:
	class CTransform* m_transform;
	class CCollider* m_collider;
	class CAnimator* m_animator;
	class CSpriteRenderer* m_spriteRenderer;

	LAYER m_layer;
	bool isActive;



public:
	GameObject();
	~GameObject();

	HRESULT Init();

	virtual void Update(float deltaTime, float worldTime);
	virtual void LateUpdate();

	virtual void BackRender(HDC _hdc);
	virtual void Render(HDC _hdc);
	virtual void FrontRender(HDC _hdc);

	virtual void Release();


	void AddColliderBox(Vector2 pos,
		float l,
		float t,
		float r,
		float b);

	void AddAnimator(string imageName);
	void AddAnimator(IMAGE imageName);

	void AddSpriteRenderer(IMAGE imageName);
	void AddSpriteRenderer(string imageName);


};
