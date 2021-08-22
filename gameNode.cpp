#include "framework.h"
#include "gameNode.h"

gameNode::gameNode() {}
gameNode::~gameNode() {}

HRESULT gameNode::init()
{
	//Ÿ�̸Ӷ� ������ �ֱ⸶�� ������ �Լ��� �����Ѵ�.
	//1 : ������ �ڵ�
	//2 :  Ÿ�̸� ��ȣ
	//3 :  Ÿ�̸��ֱ� 1000=1��
	//4 :  �ֱ⸶�� ������ �Լ�
	//NULL�̸� WM_TIMER�� ����
	
	//setBackBuffer();

	_hdc = GetDC(m_hWnd);
	_managerInit = false;
	return S_OK;
}

HRESULT gameNode::init(bool managerInit)
{
	_hdc = GetDC(m_hWnd);
	_managerInit = managerInit;

	if (managerInit)
	{
		SetTimer(m_hWnd, 1, 10, NULL);
		//�Ŵ��� �ʱ�ȭ
		MG_INPUT->init();
		MG_IMAGE->init();
		MG_TIME->init();
		MG_SOUND->init();

	}
	return S_OK;
}

//void gameNode::setBackBuffer()
//{
//	_backBuffer = new image;
//	_backBuffer->init(WINSIZEX, WINSIZEY);
//}

void gameNode::release()
{	//Ÿ�̸� ����

	if (_managerInit)
	{
		//������ ���ϸ� ���Ḧ �ص� �޸𸮰� ������~
		KillTimer(m_hWnd, 1);
		//�Ŵ��� ����


		MG_SCENE->release();
		MG_IMAGE->release();
		MG_TIME->release();
		MG_SOUND->release();
		MG_ANIMATION->release();
		MG_EFFECT->release();
		//MG_INFO->Release();

		MG_INPUT->releaseSingleton();
		MG_IMAGE->releaseSingleton();
		MG_TIME->releaseSingleton();
		MG_RND->releaseSingleton();
		MG_TXT->releaseSingleton();
		MG_SCENE->releaseSingleton();
		MG_SOUND->releaseSingleton();
		MG_ANIMATION->releaseSingleton();
		MG_EFFECT->releaseSingleton();
	}

	ReleaseDC(m_hWnd, _hdc);
	
	//SAFE_DELETE(_backBuffer);

}

void gameNode::update()
{
	//������� ���� ������� �ʴ´� true->false
	InvalidateRect(m_hWnd, NULL, false);
}

void gameNode::render(/*HDC hdc*/)
{

}

LRESULT gameNode::MainProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC hdc;

	switch (iMessage)
	{
	//case WM_TIMER:
	//	this->update();
	//	break;
	//case WM_PAINT:
	//	hdc = BeginPaint(hWnd, &ps);
	//	this->render(hdc);
	//	EndPaint(hWnd, &ps);
	//	break;
	case WM_MOUSEMOVE:
		g_ptMouse.x = LOWORD(lParam);
		g_ptMouse.y = HIWORD(lParam);
		break;
	case WM_KEYDOWN:

		switch (wParam)
		{
		case VK_ESCAPE:
			PostQuitMessage(0);
			break;
		}
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}//end of switch

	return (DefWindowProc(hWnd, iMessage, wParam, lParam));
}