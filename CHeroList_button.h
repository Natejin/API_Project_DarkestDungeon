#pragma once
#include"CDragButtion.h"
class CHeroList_button : public CDragButton
{
	//Vector2 buttonSize;
	//function<void()> m_triggerWhenDrag;

	class CSpriteRenderer* m_heroBG;
	Vector2 originPos;

public:
	CHeroList_button();
	~CHeroList_button();

	HRESULT Init();

	virtual void Update(float deltaTime, float worldTime);
	virtual void LateUpdate();

	virtual void BackRender(HDC _hdc);
	virtual void Render(HDC _hdc);
	virtual void FrontRender(HDC _hdc);

<<<<<<< HEAD
	//void SetButtonSize(float width, float height);

	//template <typename T>
	//void SetTriggerWhenDrag(T* pObj, void(T::* func)())
	//{
	//	canTriggerDrag = true;
	//	m_triggerWhenDrag = bind(func, pObj);
	//}
=======
	void DragHeroList();

>>>>>>> parent of 9433e27 (2021.08.12)

	void DragHeroList();

};

