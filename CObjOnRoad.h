#pragma once
#include "CButton.h"
#include "CButton_move.h"
#include "CSlotItemButton.h"

class CParty;
class CHero;
class CObjOnRoad :public CButton
{
public:
	RoadObjType objType;

	bool isPassed;
	bool isOpened;

public:
	CObjOnRoad();
	~CObjOnRoad();

	class DungeonScene* m_dungeonScene;
	
	HRESULT Init();
	HRESULT Init(RoadObjType type, int index, bool _isPassed, bool _isOpened);

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