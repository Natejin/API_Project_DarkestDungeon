#pragma once
#include "CButton.h"
#include "CButton_move.h"

class CParty;
class CHero;
class CObjOnRoad :public CButton
{
private:
	RoadObjType objType;

	bool isOpen;

public:
	CObjOnRoad();
	~CObjOnRoad();

	class DungeonScene* dungeonScene;
	
	//will be created according to the number of road
	HRESULT Init();
	HRESULT Init(RoadObjType type, int index, bool isPassed);

	virtual void Update(float deltaTime, float worldTime);
	virtual void LateUpdate();

	virtual void BackRender(HDC _hdc);
	virtual void Render(HDC _hdc);
	virtual void FrontRender(HDC _hdc);

	virtual void Release();


	//==================================


	void setCollider();

	void Interaction_collision();

	void Interaction_treassure();
	void Interaction_trap();
	void Interaction_trap_fail();
	void Interaction_trap_success();
	void Interaction_battle(); //change the scene

};