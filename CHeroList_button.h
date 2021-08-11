#pragma once
#include"CDragButtion.h"
class CHeroList_button : public CDragButton
{

	Vector2 originPos;
	class CSpriteRenderer* m_heroBG;
public:
	CHeroList_button();
	~CHeroList_button();

	HRESULT Init();
	class TownScene* townScene;
	virtual void Update(float deltaTime, float worldTime);
	virtual void LateUpdate();

	virtual void BackRender(HDC _hdc);
	virtual void Render(HDC _hdc);
	virtual void FrontRender(HDC _hdc);
	
	void SetButtonSize(float width, float height);
	

	bool isClick;
};

