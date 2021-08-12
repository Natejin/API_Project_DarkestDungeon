#pragma once
#include "CButton.h"

class CObjOnRoad :public CButton
{
	RoadObjType objType;

public:

	class DungeonScene* dungeonScene;
	CObjOnRoad();
	~CObjOnRoad();

	//will be created according to the number of road
	HRESULT Init();
	HRESULT Init(RoadObjType type, int index);

	virtual void Update(float deltaTime, float worldTime);
	virtual void LateUpdate();

	virtual void BackRender(HDC _hdc);
	virtual void Render(HDC _hdc);
	virtual void FrontRender(HDC _hdc);

	virtual void Release();


};

