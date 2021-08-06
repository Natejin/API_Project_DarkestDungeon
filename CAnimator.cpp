#include "framework.h"
#include "CAnimator.h"
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

CAnimator::~CAnimator()
{
}

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
			else {
				curFrameX++;
			}

			m_curAnimeFrame = 1;
		}
		m_curAnimeFrame++;
		m_imageVec[curImageIndex]->frameRender(_hdc, trans, curFrameX, curFrameY);
	}

}

void CAnimator::AddImageFrame(string imageName)
{
	m_imageVec.push_back(MG_IMAGE->findImage(imageName));
	maxFrameX.push_back( MG_IMAGE->findImage(imageName)->getMaxFrameX());
}

void CAnimator::AddImageFrame(IMAGE imageName)
{
	m_imageVec.push_back(MG_IMAGE->findImage(imageName));
	maxFrameX.push_back(MG_IMAGE->findImage(imageName)->getMaxFrameX());
}

Image* CAnimator::GetCurImage()
{
	return m_imageVec[curImageIndex];
}
