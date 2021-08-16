#pragma once
#include "GameObject.h"

class ImageObject : public GameObject
{
public:
	float curTime;
	float coolTime;
	float speed;
	Vector2 originPos;
	Vector2 targetPos;

	class CSpriteRenderer* hp1GUI;
	class CSpriteRenderer* hp10GUI;
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

