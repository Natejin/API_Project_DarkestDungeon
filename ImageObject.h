#pragma once
#include "GameObject.h"

class ImageObject : public GameObject
{
public:
	float curTime;
	float coolTime;
	Vector2 speed;
	Vector2 originPos;


public:
	ImageObject();
	~ImageObject();

	HRESULT Init();

	virtual void Update(float deltaTime, float worldTime);
	virtual void LateUpdate();

	virtual void BackRender(HDC _hdc);
	virtual void Render(HDC _hdc);
	virtual void FrontRender(HDC _hdc);

	virtual void Release();

	virtual void Enable();
	virtual void Disable();
};

