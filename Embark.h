#pragma once
#include "GameObject.h"
#include "TownScene.h"
#include "CSpriteRenderer.h"
#include "EmbarkPartySlot.h"

class Embark : public GameObject
{
public:
	TownScene* m_townScene;
	bool isEmbark;

	vector<CSpriteRenderer*> m_images;
	vector<EmbarkPartySlot*> m_slots;

	class CButton* bt_embark;
	class CButton* bt_selDungeon;

	//==================================
public:
	Embark();
	~Embark();

	HRESULT Init();

	virtual void Update(float deltaTime, float worldTime);
	virtual void LateUpdate();

	virtual void BackRender(HDC _hdc);
	virtual void Render(HDC _hdc);
	virtual void FrontRender(HDC _hdc);

	virtual void Release();


	//==================================

	void embarkBg();

	void setImg();

	void setEmbarkBt();
	void setEmbarkPartySlot();
	void setDungeonBt();

	void setEmbark();

	void setPartySlot();

	void enterDungeon();


};