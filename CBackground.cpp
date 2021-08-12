#include "framework.h"
#include "CBackground.h"

CBackground::CBackground() {}
CBackground::~CBackground() {}

HRESULT CBackground::Init()
{
    m_layer = LAYER::BackGround;
	bgCount = 10;
	roadCount = 6;
    return S_OK;
}

void CBackground::Update(float deltaTime, float worldTime)
{
}

void CBackground::LateUpdate()
{
}

void CBackground::BackRender(HDC _hdc)
{
	for (size_t i = 0; i < mostBG.size(); i++)
	{
		//mostFrontBg������ �ذ��� �ڿ� �̵�ó��
		mostBG[i].Render(_hdc);
	}
	for (size_t i = 0; i < road.size(); i++)
	{
		//mostFrontBg������ �ذ��� �ڿ� �̵�ó��
		road[i].Render(_hdc);
	}
}

void CBackground::Render(HDC _hdc)
{

	for (size_t i = 0; i < most_TOWN_UI.size(); i++)
	{
		
	}
	for (size_t i = 0; i < mostFG_Bottom.size(); i++)
	{
		//-1440���� 720*8���� �׷����� �ϴµ� �׷��� ���� ���� �� ����
		mostFG_Bottom[i].Render(_hdc);
		mostFG_Top[i].Render(_hdc);
		
	}
	for (size_t i = 0; i <most_HeroList_UI.size(); i++)
	{
		most_HeroList_UI[i].Render(_hdc);
	}
}

void CBackground::FrontRender(HDC _hdc)
{
}

void CBackground::Release()
{
	for (int i = 0; i < mostBG.size(); i++)
	{
		mostBG[i].m_img = nullptr;
		mostFG_Bottom[i].m_img = nullptr;
		mostFG_Top[i].m_img = nullptr;
	}

	for (size_t i = 0; i < road.size(); i++)
	{
		road[i].m_img = nullptr;
	}
}

void CBackground::SetRoadIMG()
{
}

int CBackground::getSceneSize() const
{
	int i = road.size() - 1;
	return road[i].m_trans.m_scale.x * road.size();
}
