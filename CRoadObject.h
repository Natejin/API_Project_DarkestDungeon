#pragma once
#include "GameObject.h"

class CParty;
class CRoadObject : public GameObject
{
private:
	vector<Image*> img_object;
	vector<CTransform> ts_area;

	vector<ImageData> roadObj;

public:
	CRoadObject();
	~CRoadObject();

	//will be created according to the number of road
	HRESULT Init();

	virtual void Update(float deltaTime, float worldTime);
	virtual void LateUpdate();

	virtual void BackRender(HDC _hdc);
	virtual void Render(HDC _hdc);
	virtual void FrontRender(HDC _hdc);

	virtual void Release();

	//==================================
	
	void setRoadObjIMG();
	void getMapInfo(int a1, int a2, int a3); //get what should be in this area
	void setRoadObj(); //set Obj according to MapInfo

	void Interaction_tressure(CHero* member);
	void Interaction_trap(CHero* member);
	void Interaction_battle(CParty* party); //not sure

};