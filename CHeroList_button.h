#pragma once
#include"CDragButtion.h"

class CHeroList_button : public CDragButton
{
	class CSpriteRenderer* m_heroBG;
	Vector2 originPos;
	

public:
	class	TownScene* townScene;
	int index;

	class CHero* m_hero;
	class Hero_Roster* dummy_Roster;
	CHeroList_button();
	~CHeroList_button();


	HRESULT Init();

	virtual void Update(float deltaTime, float worldTime);
	virtual void LateUpdate();

	virtual void BackRender(HDC _hdc);
	virtual void Render(HDC _hdc);
	virtual void FrontRender(HDC _hdc);

	void DragHeroList();
	
};