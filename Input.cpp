#include"framework.h"
#include "Input.h"

CInputManager::CInputManager() {}
CInputManager::~CInputManager() {}

HRESULT CInputManager::init()
{
	//Ű�� ���� �������� ���� ���·� �ʱ�ȭ����
	for (int i = 0; i < KEYMAX; i++)
	{
		_keyUp.set(i, false);
		_keyDown.set(i, false);
	}

	clickCoolTime = 2.f;
	clickCurTime = 0.f;
	return S_OK;
}

void CInputManager::release() {}

void CInputManager::Update(float deltaTime, float worldTime)
{
	if (curClickKeyCode > -1)
	{
		if (clickCurTime < worldTime)
		{
			_keyClick.set(curClickKeyCode, false);
			curClickKeyCode = -1;
		}
	}
}


bool CInputManager::isOnceKeyDown(int key)
{
	//GetAsyncKeyState
	//����Ű�� ���¸� Ȯ���ϴ� �Լ�
	//Ű�� ������ �� Ȥ�� �������� �� ȣ��
	// 0x8000 �������� �������� ���� ȣ������� ��������
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
	//GetKeyState :���� Ű�� ��ۻ���
	//0x0001 ������ �������� �ְ� ȣ��������� �ȴ��� ����
	if (GetKeyState(key) & 0x0001) return true;
	return false;
}

bool CInputManager::isOnceKeyClick(int key)
{
	if (GetAsyncKeyState(key) & 0x8000)
	{
		if (!_keyClick[key])
		{
			_keyClick.set(key, true);
			clickCurTime = clickCoolTime + MG_TIME->getWorldTime();
			return false;
		}
	}
	else
	{
		if (_keyClick[key])
		{
			_keyClick.set(key, false);
			curClickKeyCode = -1;
			if (clickCurTime > MG_TIME->getWorldTime())
			{

				return true;
			}
		}
	}
	return false;
}
