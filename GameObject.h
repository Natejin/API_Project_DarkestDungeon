#pragma once
#include "Object.h"

class GameObject : public Object
{

public:
	Vector2 m_pos;
	Vector2 m_scale;

	class image* m_image;

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

