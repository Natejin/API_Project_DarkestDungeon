#include "framework.h"
#include "CHeroOnStage_coach.h"

CHeroOnStage_coach::CHeroOnStage_coach()
{
}

CHeroOnStage_coach::~CHeroOnStage_coach()
{
}

HRESULT CHeroOnStage_coach::Init(Info_Hero* coach_info)
{
	CHero::Init(coach_info);
	return S_OK;
}

void CHeroOnStage_coach::Update(float deltaTime, float worldTime)
{
}

void CHeroOnStage_coach::LateUpdate()
{
}

void CHeroOnStage_coach::BackRender(HDC _hdc)
{
}

void CHeroOnStage_coach::Render(HDC _hdc)
{
	m_animator->FrameRender(_hdc);
}

void CHeroOnStage_coach::FrontRender(HDC _hdc)
{

}

void CHeroOnStage_coach::Release()
{
}

void CHeroOnStage_coach::SetHero()
{

}
