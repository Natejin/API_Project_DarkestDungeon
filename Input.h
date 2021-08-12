#pragma once
#include"singleton.h"
#include<bitset>
using namespace std;
#define KEYMAX 256

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

public:
	CInputManager();
	~CInputManager();

	HRESULT init();

	void release();


	void Update(float deltaTime, float worldTime);
	
	//�ѹ��� ������
	bool isOnceKeyDown(int key);
	//�����ٰ� �³�
	bool isOnceKeyUp(int key);
	//������ �ֳ�
	bool isStayKeyDown(int key);
	//���Ű��
	bool isToggleKey(int key);

	//�ѹ��� ������
	bool isOnceKeyClick(int key);

	bool IsDownLMB() { return isDownLMB && !wasDownLMB; }
	bool IsStayLMB() { return isDownLMB && wasDownLMB; }  
	bool IsUpLMB() {   return !isDownLMB && wasDownLMB; } 
	bool WasDownLMB() { return wasDownLMB; }

	Vector2 GetptDeltaMouse() { return m_ptDeltaMouse; }
};