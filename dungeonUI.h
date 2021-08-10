#pragma once
#include "CButton.h"

class CParty;
class dungeonUI : public GameObject
{
public:
	vector<ImageData> vUI;
	int m_sceneSize;
	bool showMap;

	CButton* bt_inven;
	CButton* bt_map;
	
	class CMapSystem* m_pMapSystem;
	class CInventorySystem* m_inven;

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
	void SetTorchUI();
	void SetInven();

	void TorchLightBarDecrease();
	void ShowInven();
	void ShowMap();

	void ShowUI(HDC _hdc);
	void ShowUIMap(HDC _hdc);
	void ShowUIUInven(HDC _hdc);
};