#pragma once
#include "singleton.h"
#include "Vector2.h"

class CCameraManager : public Singleton<CCameraManager>
{
private:
	Vector2 worldSize; //실제 맵크기
	Vector2 screenSize; //카메라 크기
	Vector2 pos; //카메라좌표
	Vector2 targetPivot; //타깃의 화면상 위치

	class GameObject* m_pTarget;
	Vector2 cameraSize;

public:
	CCameraManager();
	~CCameraManager();

	void SetPos(Vector2 _pos) { pos = _pos; }
	Vector2 GetPos() { return pos; }

	HRESULT Init();

	virtual void Update(float deltaTime, float worldTime);
	virtual void LateUpdate();

	//virtual void BackRender(HDC _hdc);
	virtual void Render(HDC _hdc);
	//virtual void FrontRender(HDC _hdc);

	virtual void Release();

	void SetTarget(class GameObject* target) { m_pTarget = target; }

	Vector2 getTargerPivot()const { return targetPivot; }
	Vector2 getCameraPos()const { return pos; }

};