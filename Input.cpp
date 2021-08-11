#include"framework.h"
#include "Input.h"

CInputManager::CInputManager() {}
CInputManager::~CInputManager() {}

HRESULT CInputManager::init()
{
	//키가 전부 눌려있지 않은 상태로 초기화하자
	for (int i = 0; i < KEYMAX; i++)
	{
		_keyUp.set(i, false);
		_keyDown.set(i, false);
	}
	return S_OK;
}

void CInputManager::release() {}

bool CInputManager::isOnceKeyDown(int key)
{
	//GetAsyncKeyState
	//현재키의 상태를 확인하는 함수
	//키가 눌렸을 때 혹은 떨어졌을 떄 호출
	// 0x8000 이전에는 누른적이 없고 호출시점에 눌린상태
	if (GetAsyncKeyState(key) & 0x8000)
	{
		if (!_keyDown[key])
		{
			_keyDown.set(key, true);
			return true;
		}
	}
	else
	{
		_keyDown.set(key, false);
	}
	return false;
}

bool CInputManager::isOnceKeyUp(int key)
{
	if (GetAsyncKeyState(key) & 0x8000)
	{
		_keyUp.set(key, true);
	}
	else
	{
		if (_keyUp[key])
		{
			_keyUp.set(key, false);
			return true;
		}
	}
	return false;
}

bool CInputManager::isStayKeyDown(int key)
{
	if (GetAsyncKeyState(key) & 0x8000) return true;
	return false;
}

bool CInputManager::isToggleKey(int key)
{
	//GetKeyState :현재 키의 토글상태
	//0x0001 이전에 누른적이 있고 호출시점에서 안눌린 상태
	if (GetKeyState(key) & 0x0001) return true;
	return false;
}
