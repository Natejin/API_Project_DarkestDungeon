#pragma once
#include "CButton.h"
#include "CButton_move.h"
#include "CSlotItemButton.h"

class CParty;
class CHero;
class CObjOnRoom : public CButton
{
private:
	RoadObjType objType;
	bool isOpened;
	bool isPassed;

public:
	CObjOnRoom();
	~CObjOnRoom();

	class DungeonScene* dungeonScene;

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
	void setTreasureSlots();

	void Interaction_collision();

	void Interaction_treassure();
	void Interaction_battle(); //change the scene

};