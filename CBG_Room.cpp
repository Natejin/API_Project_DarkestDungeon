#include "framework.h"
#include "CBG_Room.h"

CBG_Room::CBG_Room() {}
CBG_Room::~CBG_Room() {}

HRESULT CBG_Room::Init()
{
	m_layer = LAYER::BackGround;
	bgCount = 10;
	roadCount = 6;
	SetIMG();
	return S_OK;
}

//void CBG_Road::Update(float deltaTime, float worldTime)
//{
//}
//
//void CBG_Road::LateUpdate()
//{
//}

void CBG_Room::SetIMG()
{
	
}