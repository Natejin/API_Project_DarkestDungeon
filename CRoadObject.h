#pragma once
#include "GameObject.h"
#include "CBackground.h"

#define ROADSIZEX 4320 

class CParty;
class CHero;
class CRoadObject : public GameObject
{
private:
	vector<CTransform> DividedArea;
	vector<ImageData> roadObj;
	vector<Rect> roadObj_rc;

	CParty* party;

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

	void reach_InteractionArea(CParty* _party);
	void Interaction_treassure();
	void Interaction_trap();
	void Interaction_battle(); //not sure

	void showDividedArea(HDC _hdc);

};