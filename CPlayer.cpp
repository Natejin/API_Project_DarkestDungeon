#include "framework.h"
#include "CPlayer.h"

CPlayer::CPlayer()
{
}

CPlayer::~CPlayer()
{
}

HRESULT CPlayer::Init()
{
	m_image = MG_IMAGE->findImage("·Ï¸Ç");
	m_image->setX(WINSIZEX / 2);
	m_image->setY(WINSIZEY / 2);
	//mini_rc = RectMakeCenter(100 + m_rockman->getX() / 10 - m_camera / 10, 50 + m_rockman->getY() / 10, 10, 10);
	return S_OK;
}

void CPlayer::Update(float deltaTime, float worldTime)
{
	if (MG_INPUT->isStayKeyDown(VK_LEFT))
	{
		m_transform->m_pos.x -= 5;
	}
	if (MG_INPUT->isStayKeyDown(VK_RIGHT))
	{
		m_transform->m_pos.x += 5;
	}
	if (MG_INPUT->isStayKeyDown(VK_UP))
	{
		m_transform->m_pos.y -= 5;
	}
	if (MG_INPUT->isStayKeyDown(VK_DOWN))
	{
		m_transform->m_pos.y += 5;
	}
}

void CPlayer::LateUpdate()
{
}

void CPlayer::BackRender(HDC _hdc)
{
}

void CPlayer::Render(HDC _hdc)
{
	m_image->frameRender(_hdc,m_transform);
}

void CPlayer::FrontRender(HDC _hdc)
{
}

void CPlayer::Release()
{
	Unit::Release();
}
