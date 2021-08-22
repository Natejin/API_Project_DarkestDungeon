#include "framework.h"
#include "FinishPanelUI.h"
#include "CButton.h"
#include "DungeonScene.h"
FinishPanelUI::FinishPanelUI()
{
    m_layer = LAYER::UIMotion;
}

FinishPanelUI::~FinishPanelUI()
{
}

HRESULT FinishPanelUI::Init()
{
    m_transform->m_pivot = Vector2(0.5, 0.5);
    m_transform->m_pos = Vector2(WINSIZEX/ 2, WINSIZEY / 2);


    buttonEnd = new CButton();
    buttonEnd->m_layer = LAYER::UIMotion;
    buttonEnd->m_transform->m_pos = m_transform->m_pos + Vector2(-100, 300);
    buttonEnd->AddSpriteRenderer(IMAGE::start_button);
    buttonEnd->AddColliderBox();
    buttonContinue->SetTriggerWhenDown(this, &FinishPanelUI::GoBackToHome);
    MG_GMOBJ->RegisterObj(buttonEnd);


    buttonContinue = new CButton();
    buttonContinue->m_layer = LAYER::UIMotion;
    buttonContinue->m_transform->m_pos = m_transform->m_pos + Vector2(-100, 300);
    buttonContinue->AddSpriteRenderer(IMAGE::start_button);
    buttonContinue->AddColliderBox();
    buttonContinue->SetTriggerWhenDown(this, &FinishPanelUI::Disable);
    MG_GMOBJ->RegisterObj(buttonContinue);

    Disable();
    return S_OK;
}

void FinishPanelUI::Update(float deltaTime, float worldTime)
{
}

void FinishPanelUI::FrontRender(HDC _hdc)
{
}

void FinishPanelUI::Release()
{
    GameObject::Release();
    MG_GMOBJ->RemoveObj(buttonEnd);
    MG_GMOBJ->RemoveObj(buttonContinue);
}

void FinishPanelUI::Enable()
{
    buttonEnd->Enable();
    buttonContinue->Enable();
    isActive = true;
}

void FinishPanelUI::GoBackToHome() {
    MG_SCENE->changeScene(SCENETYPE::Test);
}

void FinishPanelUI::Disable()
{
    isActive = false;
    buttonEnd->Disable();
    buttonContinue->Disable();
}
