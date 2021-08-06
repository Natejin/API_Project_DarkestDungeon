#include "framework.h"
#include "CSpriteRenderer.h"

CSpriteRenderer::CSpriteRenderer()
{
}

CSpriteRenderer::~CSpriteRenderer()
{
}

void CSpriteRenderer::SetImage(string imageName)
{
	m_image = MG_IMAGE->findImage(imageName);
	m_imageSize = Vector2(m_image->getWidth(), m_image->getHeight());
}

void CSpriteRenderer::SetImage(IMAGE imageName)
{
	m_image = MG_IMAGE->findImage(imageName);
	m_imageSize = Vector2(m_image->getWidth(), m_image->getHeight());
}

void CSpriteRenderer::Render(HDC _hdc)
{
	m_image->render(_hdc, m_trans, m_imageSize);
}
