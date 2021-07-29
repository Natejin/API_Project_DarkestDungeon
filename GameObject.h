#pragma once
#include "Object.h"
#include "Transform.h"

class GameObject : public Object
{
public:
	//Vector2 m_pos;
	//Vector2 m_scale;
	//Vector2 m_pivot;
	Transform* m_transform;
	class image* m_image;

	LAYER m_layer;

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
};