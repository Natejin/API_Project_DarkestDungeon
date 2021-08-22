#include "framework.h"
//#include "CAnimator.h"
#include "image.h"

CAnimator::CAnimator(CTransform* _trans)
{
	curImageIndex = 0;
	curFrameX = 0;
	curFrameY = 0;

	m_animeFrame = 0;
	m_optimizeFrame = 0;
	m_curAnimeFrame = 1;
	trans = _trans;
}
CAnimator::~CAnimator() {}

void CAnimator::FrameRender(HDC _hdc)
{
	//assert(m_imageVec.size() > 0);
	if (m_imageVec.size() > 0)
	{
		if (m_curAnimeFrame > m_animeFrame)
		{
			if (maxFrameX[curImageIndex] == curFrameX)
			{
				curFrameX = 0;
			}
			else 
			{
				curFrameX++;
			}

			m_curAnimeFrame = 0;
		}
		m_curAnimeFrame++;
		if (useCustomPos)
		{

			m_imageVec[curImageIndex]->frameRender(_hdc, trans, m_imageSize[curImageIndex],customPos, curFrameX, curFrameY);
		}
		else {

			m_imageVec[curImageIndex]->frameRender(_hdc, trans, m_imageSize[curImageIndex], curFrameX, curFrameY);
		}
		//m_imageVec[curImageIndex]->RotateFrameRender(_hdc, trans, m_imageSize[curImageIndex], 0, curFrameY);
	}
}

void CAnimator::FrameRenderUI(HDC _hdc)
{
	//assert(m_imageVec.size() > 0);
	if (m_imageVec.size() > 0)
	{
		if (m_curAnimeFrame > m_animeFrame)
		{
			if (maxFrameX[curImageIndex] == curFrameX)
			{
				curFrameX = 0;
			}
			else
			{
				curFrameX++;
			}
			m_curAnimeFrame = 0;
		}
		m_curAnimeFrame++;
		if (useCustomPos)
		{
			m_imageVec[curImageIndex]->frameRenderUI(_hdc, trans, m_imageSize[curImageIndex], customPos, curFrameX, curFrameY);
		}
		else 
		{
			m_imageVec[curImageIndex]->frameRenderUI(_hdc, trans, m_imageSize[curImageIndex], curFrameX, curFrameY);
		}
		//m_imageVec[curImageIndex]->RotateFrameRender(_hdc, trans, m_imageSize[curImageIndex], 0, curFrameY);
	}
}

void CAnimator::FrameRender(HDC _hdc, int Xindex, int Yindex) 
{
	if (useCustomPos)
	{
		m_imageVec[curImageIndex]->frameRender(_hdc, trans , m_imageSize[curImageIndex], customPos, Xindex, Yindex);
	}
	else 
	{
		m_imageVec[curImageIndex]->frameRender(_hdc, trans, m_imageSize[curImageIndex], Xindex, Yindex);
	}
	
}

void CAnimator::FrameRenderUI(HDC _hdc, int Xindex, int Yindex)
{
	if (useCustomPos)
	{
		m_imageVec[curImageIndex]->frameRenderUI(_hdc, trans, m_imageSize[curImageIndex], customPos, Xindex, Yindex);
	}
	else 
	{
		m_imageVec[curImageIndex]->frameRenderUI(_hdc, trans, m_imageSize[curImageIndex], Xindex, Yindex);
	}

}

void CAnimator::AlphaFrameRender(HDC _hdc, BYTE alpha)
{
	if (m_imageVec.size() > 0)
	{
		if (m_curAnimeFrame > m_animeFrame)
		{
			if (maxFrameX[curImageIndex] == curFrameX)
			{
				curFrameX = 0;
			}
			else
			{
				curFrameX++;
			}

			m_curAnimeFrame = 0;
		}
		m_curAnimeFrame++;
		if (useCustomPos)
		{
			m_imageVec[curImageIndex]->frameRender(_hdc, trans, m_imageSize[curImageIndex], customPos, curFrameX, curFrameY);
		}
		else 
		{
			m_imageVec[curImageIndex]->frameRender(_hdc, trans, m_imageSize[curImageIndex], curFrameX, curFrameY);
		}
		//m_imageVec[curImageIndex]->RotateFrameRender(_hdc, trans, m_imageSize[curImageIndex], 0, curFrameY);
	}
}

void CAnimator::AlphaFrameRender(HDC _hdc, BYTE alpha, int Xindex, int Yindex)
{
	if (useCustomPos)
	{
		m_imageVec[curImageIndex]->AlphaFrameRender(_hdc, trans, m_imageSize[curImageIndex], customPos, Xindex, Yindex, alpha);
	}
	else 
	{
		m_imageVec[curImageIndex]->AlphaFrameRender(_hdc, trans, m_imageSize[curImageIndex], Xindex, Yindex, alpha);
	}
}

void CAnimator::SetIndex(int index) 
{
	curImageIndex = index;
	auto a = m_imageVec[curImageIndex];
}

void CAnimator::AddImageFrame(string imageName)
{
	m_imageVec.push_back(MG_IMAGE->findImage(imageName));
	maxFrameX.push_back(MG_IMAGE->findImage(imageName)->getMaxFrameX());
	m_imageSize.push_back(Vector2(MG_IMAGE->findImage(imageName)->getFrameWidth(), MG_IMAGE->findImage(imageName)->getFrameHeight()));
}

void CAnimator::AddImageFrame(IMAGE imageName)
{
	m_imageVec.push_back(MG_IMAGE->findImage(imageName));
	maxFrameX.push_back(MG_IMAGE->findImage(imageName)->getMaxFrameX());
	m_imageSize.push_back(Vector2(MG_IMAGE->findImage(imageName)->getFrameWidth(), MG_IMAGE->findImage(imageName)->getFrameHeight()));
}

void CAnimator::ResetAnimation() 
{
	curFrameX = 0;
	m_curAnimeFrame = 0;
}

Image* CAnimator::GetCurImage()
{
	return m_imageVec[curImageIndex];
}

Vector2 CAnimator::GetFrameSize()
{
	return m_imageSize[curImageIndex];
}

void CAnimator::SetCurFrameX(int x)
{
	curFrameX = x;
}