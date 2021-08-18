#include "framework.h"
//#include "CAnimator.h"
#include "image.h"

CAnimator::CAnimator()
{
	curImageIndex = 0;
	curFrameX = 0;

	curFrameY = 0;
	m_animeFrame = 0;

	m_optimizeFrame = 0;
	 m_curAnimeFrame = 1;
	 trans = nullptr;
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

			m_curAnimeFrame = 1;
		}
		m_curAnimeFrame++;
		m_imageVec[curImageIndex]->frameRender(_hdc, trans, m_imageSize[curImageIndex], curFrameX, curFrameY);
		//m_imageVec[curImageIndex]->RotateFrameRender(_hdc, trans, m_imageSize[curImageIndex], 0, curFrameY);
	}
}

void CAnimator::SetIndex(int index) 
{
	curImageIndex = index;
	auto a = m_imageVec[curImageIndex];
	curFrameX = 0;
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