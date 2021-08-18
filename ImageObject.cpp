#include "framework.h"
#include "ImageObject.h"
//#include "CSpriteRenderer.h"
ImageObject::ImageObject()
{
    m_layer = LAYER::UIMotion;
}

ImageObject::~ImageObject()
{

}

HRESULT ImageObject::Init()
{
    m_transform->m_pivot = Vector2(0.5, 1);
    coolTime = 3;
    AddSpriteRenderer(IMAGE::NONE);

	hp1GUI = new CSpriteRenderer(IMAGE::NONE, m_transform);
    hp1GUI->useCustomPos = true;
	hp10GUI = new CSpriteRenderer(IMAGE::NONE, m_transform);
    hp10GUI->useCustomPos = true;
    return S_OK;
}

void ImageObject::Update(float deltaTime, float worldTime)
{
    float distance = (targetPos - m_transform->m_pos).Magnitude();
    Vector2 Normalize = (targetPos - m_transform->m_pos).Normalize();
    if (distance > 200)
    {
        m_transform->m_pos += Normalize * speed * 3;
    }
    else if (distance > 10) 
    {
        m_transform->m_pos += Normalize * speed;
    }

    if (curTime < worldTime)
    {
        Disable();
    }
}

void ImageObject::LateUpdate()
{

}

void ImageObject::BackRender(HDC _hdc)
{

}

void ImageObject::Render(HDC _hdc)
{
    
}

void ImageObject::FrontRender(HDC _hdc)
{
    m_spriteRenderer->RenderUI(_hdc);
}

void ImageObject::Release()
{

}

void ImageObject::Enable()
{
    m_transform->m_pos = originPos;
    curTime = MG_TIME->getWorldTime() + coolTime;
    isActive = true;
}

void ImageObject::Disable()
{
    isActive = false;
}
