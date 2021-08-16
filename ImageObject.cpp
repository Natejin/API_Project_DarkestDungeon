#include "framework.h"
#include "ImageObject.h"

ImageObject::ImageObject()
{
    m_layer = LAYER::UI;
}

ImageObject::~ImageObject()
{

}

HRESULT ImageObject::Init()
{
    m_transform->m_pivot = Vector2(0.5, 1);
    coolTime = 4;
    AddSpriteRenderer(IMAGE::NONE);
    return S_OK;
}

void ImageObject::Update(float deltaTime, float worldTime)
{
    m_transform->m_pos += speed;
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
    m_spriteRenderer->RenderUI(_hdc);
}

void ImageObject::FrontRender(HDC _hdc)
{

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
