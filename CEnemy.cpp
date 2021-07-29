#include "framework.h"
#include "CEnemy.h"


CEnemy::CEnemy() {}
CEnemy::~CEnemy() {}

HRESULT CEnemy::Init()
{
	m_image = MG_IMAGE->findImage("·Ï¸Ç");
	m_layer = LAYER::Enemy;
	//mini_rc = RectMakeCenter(100 + m_rockman->getX() / 10 - m_camera / 10, 50 + m_rockman->getY() / 10, 10, 10);
	return S_OK;
}

void CEnemy::Update(float deltaTime, float worldTime)
{
	
}

void CEnemy::LateUpdate()
{
}

void CEnemy::BackRender(HDC _hdc)
{
}

void CEnemy::Render(HDC _hdc)
{
	m_image->frameRender(_hdc, m_transform);
}

void CEnemy::FrontRender(HDC _hdc)
{
}

void CEnemy::Release()
{
	Unit::Release();
}