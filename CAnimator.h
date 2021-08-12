#pragma once
#include "CComponent.h"

class CAnimator : public CComponent
{
private:
	class CTransform* trans;

	vector<class Image*> m_imageVec;
	vector<int> maxFrameX;
	vector<Vector2> m_imageSize;
 
	//int curAnimeCount;

	int curImageIndex;
	int curFrameX;
	int curFrameY;

	//int maxFrameX;
	//int maxFrameY;

	int m_animeFrame;
	int m_curAnimeFrame;
	int m_optimizeFrame;

public:
	ANIMATIONTYPE m_animationType;
	//Vector2 m_pos;
	//Rect rect;

	CAnimator();
	~CAnimator();

	void FrameRender(HDC _hdc);

	void SetIndex(int index);
	void SetTrans(class CTransform* _trans) { trans = _trans; }
	void SetAnimeSpeed(int speed) 
	{ 
		m_animeFrame = speed; 
		m_optimizeFrame = m_animeFrame - 2;
	}

	void SetFrameX(int frame) { curFrameX = frame; }
	void SetFrameY(int frame) { curFrameY = frame; }
	void AddImageFrame(string imageName);
	void AddImageFrame(IMAGE imageName);

	void ResetAnimation();

	class Image* GetCurImage();
	Vector2 GetFrameSize();

};