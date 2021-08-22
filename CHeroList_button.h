#pragma once
#include"CDragButtion.h"
#include <functional>


class CHeroList_button : public CDragButton
{
	function<void()> m_triggerWhenDownRightButton;
	class CSpriteRenderer* m_heroBG;
	class CSpriteRenderer* m_characterBG;
	Vector2 originPos;

	bool canTriggerDownRightButton;
	bool canTriggerDownForHerolist;

	function<void(HeroListBtType type, int index)> m_triggerWhenDownForHeroList;

public:
	class TownScene* townScene;
	class CUI_Panel_Hero* hero_panel;
	int m_index;

	class CHero* m_hero;
	class Hero_Roster* dummy_Roster;
	class CUIPanel_StageCoach* m_coach;

	HeroListBtType btType;

	CHeroList_button();
	~CHeroList_button();

	HRESULT Init();

	virtual void Update(float deltaTime, float worldTime);
	virtual void LateUpdate();

	virtual void BackRender(HDC _hdc);
	virtual void Render(HDC _hdc);
	virtual void FrontRender(HDC _hdc);

	virtual void Release();

	void DragHeroList();
	template <typename T>

	void SetTriggerWhenDownRightButton(T* pObj, void(T::* func)())
	{
		canTriggerDownRightButton = true;
		m_triggerWhenDownRightButton = bind(func, pObj);
	}

	template <typename T>
	void SetTriggerWhenDownForHerolist(T* pObj, void(T::* func)(HeroListBtType  type, int index))
	{
		canTriggerDownForHerolist = true;
		m_triggerWhenDownForHeroList = bind(func, pObj, std::placeholders::_1, std::placeholders::_2);
	}

	//
	// template <typename T>
	//template <typename T>
	//void SetTriggerWhenDownForHerolist(T* pObj, void(T::* func)())
	//{
	//	canTriggerDownForHerolist = true;
	//	m_triggerWhenDownForHeroList = bind(func, pObj, btType, m_index);
	//}



};