#pragma once
#include "singleton.h"
#include "Vector2.h"

class CCameraManager : public Singleton<CCameraManager>
{
private:
	Vector2 worldSize; //���� ��ũ��
	Vector2 screenSize; //ī�޶� ũ��
	Vector2 pos; //ī�޶���ǥ
	Vector2 targetPivot; //Ÿ���� ȭ��� ��ġ

	class GameObject* m_pTarget;
	Vector2 cameraSize;
	bool isBattle;
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
	Vector2 getSCPV()const { return screenSize.x * targetPivot.x; }
	void SetWorldSize(Vector2 size);
	Vector2 GetWorldSize();
	Vector2 GetCenterPos();

};