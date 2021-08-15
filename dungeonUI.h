#pragma once
#include "CButton.h"

class CParty;
class CUIPanel;
class dungeonUI : public GameObject
{
public:
	vector<ImageData> vUI;

	int m_sceneSize;

	CButton* bt_inven;
	CButton* bt_map;

	//CButton* bt_skill1;
	//CButton* bt_skill2;
	//CButton* bt_skill3;
	//CButton* bt_skill4;
	CButton* bt_passTurn;
	CButton* bt_changePos;

	vector<class CBTN_Skill*> skillBTNs;

	class DungeonScene* scene;

	
	class CMapSystem* m_pMapSystem;
	class CInventorySystem* m_invenSystem;

	CUIPanel* invenPanel;
	//class CDragButtonMinimapBG* mapPanel1;
	CUIPanel* mapPanel1;
	class CDragButtonMinimapBG* mapPanel2;
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
	void SetInven();

	void SetSkillButton();
	void SelectSkillButton();

	void TorchLightBarDecrease();

	void ShowInven();
	void ShowMap();

	void ShowUI(HDC _hdc);

	//CUIPanel* CreatePanel(string name, Vector2 pos);
	CUIPanel* CreatePanel(string name, Vector2 pos, LAYER layer);
	CUIPanel* CreatePanel(IMAGE image, Vector2 pos, LAYER layer);

	CInventorySystem* getInven();
};