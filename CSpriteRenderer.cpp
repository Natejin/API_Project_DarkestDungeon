#include "framework.h"
//#include "CSpriteRenderer.h"

CSpriteRenderer::CSpriteRenderer()
{
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
		m_image->render(_hdc, m_trans, m_imageSize, pos);
	}else{
		m_image->render(_hdc, m_trans, m_imageSize);
	}

}

void CSpriteRenderer::RenderUI(HDC _hdc)
{
	if (useCustomPos)
	{
		m_image->renderUI(_hdc, m_trans, pos);
	}
	else {

		m_image->renderUI(_hdc, m_trans);
	}
	
}

Vector2 CSpriteRenderer::GetImageSize()
{
	return m_imageSize;
}
