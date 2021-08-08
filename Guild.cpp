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
    Setquick();
    return S_OK;
}

void Guild::Update(float deltaTime, float worldTime)
{
    if (isUi == true)
    {

        isUI = true;

    }
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
    }
   
}

void Guild::Release()
{
}

void Guild::Setquick()
{
    //나가기버튼
    CButton* m_quick = new CButton();
    m_quick->m_transform->m_pos = Vector2(WINSIZEX - 500, 100);
    m_quick->SetButtonSize(200, 200);
    m_quick->AddSpriteRenderer("quick");
    m_quick->SetTriggerWhenClick(this, &Guild::FinishUI);
    MG_GMOBJ->RegisterObj("quick", m_quick);
}

void Guild::FinishUI()
{
    isUi = false;
    isUI = false;
}
