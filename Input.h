#pragma once
#include"singleton.h"
#include<bitset>
using namespace std;
#define KEYMAX 256
#include "Vector2.h"



class CInputManager : public Singleton<CInputManager>
{
private:
	bitset<KEYMAX> _keyUp;
	bitset<KEYMAX> _keyDown;
	bitset<KEYMAX> _keyClick;

	bitset<KEYMAX> _keyDownFrame;
	bitset<KEYMAX> _keyUpFrame;

	float clickCoolTime;
	float clickCurTime;

	int curClickKeyCode;

	//vector<tKeyState>	m_vecKey;

	bool isDownLMB;
	bool wasDownLMB;


	bool isDownRMB;

	Vector2 m_OldptMouse;
	Vector2 m_Mouse;
	Vector2 m_ptDeltaMouse;

public:
	CInputManager();
	~CInputManager();

	HRESULT init();

	void release();


	void Update(float deltaTime, float worldTime);

	//한번만 눌렀냐
	bool isOnceKeyDown(int key);
	//눌렀다가 뗏냐
	bool isOnceKeyUp(int key);
	//누르고 있냐
	bool isStayKeyDown(int key);
	//토글키냐
	bool isToggleKey(int key);

	//한번만 눌렀냐
	bool isOnceKeyClick(int key);

	bool IsDownLMB() { return isDownLMB && !wasDownLMB; }
	bool IsStayLMB() { return isDownLMB && wasDownLMB; }
	bool IsUpLMB() { return !isDownLMB && wasDownLMB; }

	bool WasDownLMB() { return wasDownLMB; }



	Vector2 GetptDeltaMouse() { return m_ptDeltaMouse; }
};
