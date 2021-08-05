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
	vector<ImageData> most_EST; //�ǹ�
	vector<ImageData> most_EST_UI; //�ǹ�ui

	int bgCount;
	int roadCount;

	//������ Ư��
	DUNGEONMAPSTATE m_kindOfRoad;
	vector<ImageData> road_event;

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