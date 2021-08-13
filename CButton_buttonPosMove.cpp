#include "framework.h"
#include "CButton_buttonPosMove.h"

CButton_buttonPosMove::CButton_buttonPosMove()
{
	m_layer = LAYER::BackGround;
	countNum = 0;
}
CButton_buttonPosMove::~CButton_buttonPosMove() {}

HRESULT CButton_buttonPosMove::Init()
{
	return S_OK;
}

void CButton_buttonPosMove::Update(float deltaTime, float worldTime)
{
	//마우스좌표 변환
	Vector2 PointToVector = Vector2(g_ptMouse) + MG_CAMERA->getCameraPos();

	//화면상 버튼의 좌표 변화 반영
	if (go != NULL)
	{
		m_transform->m_pos = Vector2(
			go->m_transform->m_pos.x - go->m_animator->GetCurImage()->getFrameWidth() / 4,
			go->m_transform->m_pos.y - go->m_animator->GetCurImage()->getFrameHeight());
	}
	
	setRect();

	if (m_rect.CheckCollisionWithPoint(PointToVector))
	{
		if (MG_INPUT->isOnceKeyDown(VK_LBUTTON))
		{
			m_triggerWhenClick();
		}
	}
}

void CButton_buttonPosMove::LateUpdate()
{
}

void CButton_buttonPosMove::BackRender(HDC _hdc)
{
}

void CButton_buttonPosMove::Render(HDC _hdc)
{
	m_spriteRenderer->Render(_hdc);
	//Rectangle(_hdc, m_rect.l, m_rect.t, m_rect.r, m_rect.b);
}

void CButton_buttonPosMove::FrontRender(HDC _hdc)
{
}

void CButton_buttonPosMove::Release()
{
	GameObject::Release();
}

void CButton_buttonPosMove::SetButtonSize(float width, float height)
{
	sizeX = width;
	sizeY = height;
}

void CButton_buttonPosMove::setRect()
{
	m_rect.l = m_transform->m_pos.x;
	m_rect.t = m_transform->m_pos.y;
	m_rect.r = m_transform->m_pos.x + sizeX;
	m_rect.b = m_transform->m_pos.y + sizeY;
}

void CButton_buttonPosMove::setBtTarget(GameObject* _go)
{
	go = _go;
}