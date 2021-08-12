#include "framework.h"
#include "CCameraManager.h"
#include "GameObject.h"
#include "CTransform.h"

CCameraManager::~CCameraManager() {}
CCameraManager::CCameraManager() { m_pTarget = nullptr; }

HRESULT CCameraManager::Init()
{
	worldSize = Vector2(WORLDSIZEX, WORLDSIZEY);
	screenSize = Vector2(WINSIZEX, WINSIZEY);
	targetPivot = Vector2(0.5, 0.5);
	return S_OK;
}

void CCameraManager::Update(float deltaTime, float worldTime)
{
	if (m_pTarget != nullptr)
	{
		Vector2 fpos = m_pTarget->m_transform->m_pos;
		Vector2 fpivot = m_pTarget->m_transform->m_pivot;
		Vector2 fscale = m_pTarget->m_animator->GetFrameSize();

		float left = fpos.x - fpivot.x * fscale.x;
		float top = fpos.y - fpivot.y * fscale.y;
		float right = left + fscale.x;
		float bottom = top + fscale.y;

		float leftArea = screenSize.x * fpivot.x;
		float rightArea = screenSize.x - leftArea;
		float topArea = screenSize.y * fpivot.y;
		float bottomArea = screenSize.y - topArea;

		//플레이어가 왼쪽에 붙었을때 카메라는 왼쪽 끝에서 이동시키지 않음
		if (fpos.x < leftArea)
		{
			pos.x = 0.f;
		}

		//플레이어가 오른쪽에 붙었을때 카메라는 오른쪽 끝에서 이동시키지 않음
		else if (fpos.x >= worldSize.x - rightArea) 
		{
			this->pos.x = worldSize.x - screenSize.x;
		}

		//플레이어가 월드맵에서 오른쪽이나 왼쪽에 붙어있지 않을 때
		//카메라를 플레이어의 위치에 맞게 이동시킴
		else 
		{
			pos.x = fpos.x - screenSize.x * targetPivot.x;
		}

		////플레이어가 위에 붙었을때 카메라는 왼쪽 끝에서 이동시키지 않음
		//if (fpos.y < topArea)
		//{
		//	pos.y = 0.f;
		//}
		////플레이어가 아래에 붙었을때 카메라는 오른쪽 끝에서 이동시키지 않음
		//else if (fpos.y >= worldSize.y - bottomArea) 
		//{
		//	this->pos.y = worldSize.y - screenSize.y;
		//}

		////플레이어가 월드맵에서 위 혹은 아래에 붙어있지않을때
		////카메라를 플레이어위치에 맞게 이동시킴
		//else {
		//	pos.y = fpos.y - screenSize.y * targetPivot.y;
		//}
	}
}

void CCameraManager::LateUpdate()
{

}

void CCameraManager::Render(HDC _hdc)
{
	if (m_pTarget != nullptr)
	{
		char str[256];
		string strFrame;
		SetBkMode(_hdc, TRANSPARENT);
		SetTextColor(_hdc, RGB(0, 0, 255));
		//디버그 모드라면

#ifdef _DEBUG

		sprintf_s(str, "CameraPos : %f, %f", pos.x, pos.y);
		TextOut(_hdc, 0, 500, str, strlen(str));

#else
		//if (_timer != nullptr)
		//{
		//	//FPS
		//	sprintf_s(str, "FPS : %d", _timer->getFrameRate());
		//	TextOut(hdc, 0, 0, str, strlen(str));
		//}

#endif // DEBUG

	}
}

void CCameraManager::Release() 
{

}

void CCameraManager::SetWorldSize(Vector2 size)
{
	worldSize = size;
}

Vector2 CCameraManager::GetWorldSize()
{
	return worldSize;
}
