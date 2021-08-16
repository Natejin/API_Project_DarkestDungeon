#pragma once
#include "CButton.h"
#include "CButton_move.h"
#include "CSlotItemButton.h"

class CParty;
class CHero;
class CObjOnRoom : public CButton
{
private:
	RoomObjType objType;

	bool isOpened;
	bool isPassed;

public:
	CObjOnRoom();
	~CObjOnRoom();

	class DungeonScene* m_dungeonScene;

	HRESULT Init();
	HRESULT Init(RoomObjType type, bool _isPassed, bool _isOpened);

	virtual void Update(float deltaTime, float worldTime);
	virtual void LateUpdate();

	virtual void BackRender(HDC _hdc);
	virtual void Render(HDC _hdc);
	virtual void FrontRender(HDC _hdc);

	virtual void Release();


	//==================================


	void setCollider();

	void Interaction_treassure();

};