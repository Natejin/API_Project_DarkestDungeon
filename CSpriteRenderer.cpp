#include "framework.h"
//#include "CSpriteRenderer.h"

CSpriteRenderer::CSpriteRenderer()
{
	useCustomPos = false;
	useCustomScale = false;
	scale = Vector2(1, 1);
	pos = Vector2(0,0);
	m_image = nullptr;
}

CSpriteRenderer::CSpriteRenderer(string imageName, CTransform* _trans)
{
	m_trans = _trans;
	m_image = MG_IMAGE->findImage(imageName);
	m_imageSize = Vector2(m_image->getWidth(), m_image->getHeight());
	useCustomPos = false;
}

CSpriteRenderer::CSpriteRenderer(IMAGE imageName, CTransform* _trans)
{
	m_trans = _trans;
	m_image = MG_IMAGE->findImage(imageName);
	m_imageSize = Vector2(m_image->getWidth(), m_image->getHeight());
	useCustomPos = false;
}

CSpriteRenderer::~CSpriteRenderer()
{

}

void CSpriteRenderer::SetImage(Image* image)
{
	m_image = image;
	m_imageSize = Vector2(m_image->getWidth(), m_image->getHeight());
}

void CSpriteRenderer::SetImage()
{
	m_image = nullptr;
	m_imageSize = Vector2(0, 0);
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

Image* CSpriteRenderer::GetImage()
{
	return m_image;
}

void CSpriteRenderer::Render(HDC _hdc)
{
	if (useCustomPos)
	{

		if (useCustomScale)
		{
			m_image->render(_hdc, m_trans, m_imageSize, pos, scale);
		}
		else {
			m_image->render(_hdc, m_trans, m_imageSize, pos);
		}
	}
	else
	{
		m_image->render(_hdc, m_trans, m_imageSize);
	}
}

void CSpriteRenderer::AlphaRenderUI(HDC _hdc, BYTE alpha)
{
	m_image->AlphaRenderUI(_hdc, m_trans, alpha);
}

void CSpriteRenderer::AlphaRender(HDC _hdc, BYTE alpha)
{
	m_image->AlphaRender(_hdc, m_trans, alpha);
}


void CSpriteRenderer::RenderUI(HDC _hdc)
{


	if (useCustomPos)
	{
		if (useCustomScale)
		{
			m_image->renderUI(_hdc, m_trans, pos, scale);
		}
		else {
			m_image->renderUI(_hdc, m_trans, pos);
		}
	}
	else {
		if (useCustomScale)
		{
			m_image->renderUI(_hdc, m_trans, Vector2(0,0), scale);
		}
		else {
			m_image->renderUI(_hdc, m_trans);
		}
	
	}
}

Vector2 CSpriteRenderer::GetImageSize()
{
	return m_imageSize;
}

bool CSpriteRenderer::HasImage()
{
	return m_image ? true : false;
}