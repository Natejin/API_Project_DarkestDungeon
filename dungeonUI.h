#pragma once
#include "CButton.h"

class CParty;
class CUIPanel;
class dungeonUI : public GameObject
{
public:
	vector<ImageData> vUI;
	vector<class CBTN_Skill*> skillBTNs;

	int m_sceneSize;

	CButton* bt_inven;
	CButton* bt_map;
	CButton* bt_passTurn;
	CButton* bt_changePos;

	class DungeonScene* scene;

	class CMapSystem* m_pMapSystem;
	class CBattleSystem* m_pBattleSystem;
	class CInventorySystem* m_invenSystem;

	CUIPanel* panel_bg1;
	CUIPanel* panel_bg2;
	CUIPanel* banner;
	CUIPanel* hero;


	CUIPanel* invenPanel;
	CUIPanel* mapPanel1;
	class CDragButtonMinimapBG* mapPanel2;

	//class CDragButtonMinimapBG* mapPanel1;
	//class CUIPanel* mapPanel2;

	//==================================

	HRESULT Init();

	virtual void Update(float deltaTime, float worldTime);
	virtual void LateUpdate();

	virtual void BackRender(HDC _hdc);
	virtual void Render(HDC _hdc);
	virtual void FrontRender(HDC _hdc);

	virtual void Release();

	//==================================

	void SetUIIMG();
	void SetButton();
	void SetTorchUIimg();

	void SetSkillButton();
	void SelectSkillButton();

	void TorchLightBarDecrease();

	void ShowInven();
	void ShowMap();

	void ShowUI(HDC _hdc);

	CUIPanel* CreatePanel(string name, Vector2 pos, LAYER layer);
	CUIPanel* CreatePanel(IMAGE image, Vector2 pos, LAYER layer);
};