#include "framework.h"
#include "Guild.h"

Guild::Guild()
{
}

Guild::~Guild()
{
}

HRESULT Guild::Init()
{
    isUi = false;
    //나가기버튼
    m_quick->m_transform->m_pos = Vector2(WINSIZEX - 500, 100);
    m_quick->SetButtonSize(200, 200);
    m_quick->AddSpriteRenderer("quick");
    MG_GMOBJ->RegisterObj("quick", m_quick);
    m_quick->isActive = false;
    return S_OK;
}

void Guild::Update(float deltaTime, float worldTime)
{
    if (isUi == true)
    {
        isUI = true;
    }
    Setquick();
}

void Guild::LateUpdate()
{
}

void Guild::BackRender(HDC _hdc)
{
}

void Guild::Render(HDC _hdc)
{
}

void Guild::FrontRender(HDC _hdc)
{
    if (isUI)
    {
        MG_IMAGE->findImage("guild.character.bg")->render(_hdc);
        MG_IMAGE->findImage("guild.character")->render(_hdc);
        m_quick->isActive = true;

    }
   
}

void Guild::Release()
{
}

void Guild::Setquick()
{
   
    m_quick->SetTriggerWhenClick(this, &Guild::FinishUI);
}

void Guild::FinishUI()
{
    isUi = false;
    isUI = false;
    m_quick->isActive = false;

}
