#pragma once
#include "GameObject.h"
#include "CDragButtion.h"
#include "itemInfo.h"

class slot : public CDragButton
{
public:
	itemInfo slotItem;
	ImageData slotItemImg;

	int ID; //slotPos

	CDragButton bt_slot;

public:
	slot();
	~slot();

	HRESULT Init();

	virtual void Update(float deltaTime, float worldTime);
	virtual void LateUpdate();

	virtual void BackRender(HDC _hdc);
	virtual void Render(HDC _hdc);
	virtual void FrontRender(HDC _hdc);

	//===================================

};