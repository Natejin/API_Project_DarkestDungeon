#pragma once
#include "GameObject.h"
#include "CBackground.h"
#include "CButton_move.h"

#define ROADSIZEX 4320 

class CParty;
class CHero;
class CRoadObject : public GameObject
{
private:
	vector <ImageData> m_roadObj;
	vector <CTransform> m_SettingArea;
	bool isTreasureOpen;
	bool clearTrap;

	CButton_move* bt_treasure;
	CButton_move* bt_trap;
	CButton_move* bt_battle;

	CCollider* testCollider;
	bool isCollision;

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
	
	void setButton();

	void getMapInfo(int a1, int a2, int a3); //get what should be in this area
	void setRoadObjIMG();
	void setRoadObj(); //set Obj according to MapInfo

	void Interaction_collision();
	void Interaction_treassure();
	void Interaction_trap();
	void Interaction_trap_fail();
	void Interaction_trap_success();
	void Interaction_battle(); //change the scene

};