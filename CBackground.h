#pragma once
#include "GameObject.h"

class CTransform;
class CBackground : public GameObject
{
protected:
	vector<ImageData> road;
	vector<ImageData> mostBG;
	vector<ImageData> mostFG_Top;
	vector<ImageData> mostFG_Bottom;

	int bgCount;
	int roadCount;

	//구역의 특성
	DUNGEONMAPSTATE m_kindOfRoad;
	Image* tresure;
	Image* trap;
	CTransform ts_event[3];

public:
	CBackground();
	~CBackground();

	HRESULT Init();

	virtual void Update(float deltaTime, float worldTime);
	virtual void LateUpdate();

	virtual void BackRender(HDC _hdc);
	virtual void Render(HDC _hdc);
	virtual void FrontRender(HDC _hdc);

	virtual void Release();

	//==================================

	virtual void SetRoadIMG();
};