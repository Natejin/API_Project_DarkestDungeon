#include "framework.h"
#include "mainScene.h"
#include"StartBG.h"
#include"TitleButton.h"
mainScene::mainScene()
{
}

mainScene::~mainScene()
{
}

HRESULT mainScene::Init()
{
    MG_SOUND->play(SOUND::Title_Theme,0.1f);
    m_startscene = new StartBG();
    m_startscene->Init();
    MG_GMOBJ->RegisterObj("StartScene", m_startscene);

    m_titleButton = new TitleButton();
    m_titleButton->Init();
    m_titleButton->AddSpriteRenderer(IMAGE::start_button);
    m_titleButton->AddColliderBox();
    m_titleButton->SetTriggerWhenDown(this, &mainScene::ChangeTown);
    m_titleButton->m_transform->m_pos = Vector2(WINSIZEX / 2 ,1200);
    MG_GMOBJ->RegisterObj("Title", m_titleButton);

    return S_OK;
}

void mainScene::Release()
{
    MG_SOUND->stop(SOUND::Title_Theme);
    MG_GMOBJ->RemoveObj(m_startscene);
    MG_GMOBJ->RemoveObj(m_titleButton);

}

void mainScene::Update()
{

}

void mainScene::Render()
{
}

void mainScene::Render(HDC _hdc)
{
}

void mainScene::ChangeTown()
{
    MG_SCENE->changeScene(SCENETYPE::Town);
}
