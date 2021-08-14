#pragma once
#include"CDragButtion.h"
#include <functional>


class CHeroList_button : public CDragButton
{
	class CSpriteRenderer* m_heroBG;
	class CSpriteRenderer* m_characterBG;
	Vector2 originPos;
	function<void()> m_triggerWhenDownRightButton;
	bool canTriggerDownRightButton;


public:
	class TownScene* townScene;
	class CUI_Panel_Hero* hero_panel;
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
	void SetHeroPanel();
	template <typename T>
	void SetTriggerWhenDownRightButton(T* pObj, void(T::* func)())
	{
		canTriggerDownRightButton = true;
		m_triggerWhenDownRightButton = bind(func, pObj);
	}

};