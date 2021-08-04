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
	bitset<KEYMAX> _keyDownFrame;
	bitset<KEYMAX> _keyUpFrame;

public:
	CInputManager();
	~CInputManager();

	HRESULT init();

	void release();

	//�ѹ��� ������
	bool isOnceKeyDown(int key);
	//�����ٰ� �³�
	bool isOnceKeyUp(int key);
	//������ �ֳ�
	bool isStayKeyDown(int key);
	//���Ű��
	bool isToggleKey(int key);
};