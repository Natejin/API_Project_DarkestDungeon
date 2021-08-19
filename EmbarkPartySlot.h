#pragma once
#include "GameObject.h"
#include "DungeonScene.h"
#include "CEst_UI.h"

class EmbarkPartySlot : public CEst_UI
{
public:
	class TownScene* m_townScene;
	class CHero* m_hero;

	//class CHeroList_button* m_listButton;
	//class CButton* checkBt;

public:
	EmbarkPartySlot();
	~EmbarkPartySlot();

	HRESULT Init();

	virtual void Update(float deltaTime, float worldTime);
	virtual void LateUpdate();

	virtual void BackRender(HDC _hdc);
	virtual void Render(HDC _hdc);
	virtual void FrontRender(HDC _hdc);

	virtual void Release();

	//===================================

	virtual void Enable();
	virtual void Disable();

};