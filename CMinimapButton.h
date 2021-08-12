#pragma once
#include "CButton.h"

class CMinimapButton : public CButton
{
	class CMapSystem* m_pMapSystem;
public:
	DungeonData dungeonData;


	CMinimapButton();
	~CMinimapButton();

	HRESULT Init();



	virtual void Update(float deltaTime, float worldTime);
	virtual void LateUpdate();

	virtual void BackRender(HDC _hdc);
	virtual void Render(HDC _hdc);
	virtual void FrontRender(HDC _hdc);

	virtual void AddSpriteRenderer(IMAGE imageName);
	void SetMapSystem(class CMapSystem* _mapSystem);
};

