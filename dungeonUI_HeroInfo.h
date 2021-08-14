#pragma once
#include "GameObject.h"
#include "CButton_buttonPosMove.h"

class CHero;
class CParty;
class CDungeonUI_HeroInfo : public GameObject
{
private:
	vector<ImageData> m_heroInfoImage; //���, ����� ������, ��ų �̹���
	vector<ImageData> m_invenOrMapImage; 

	ImageData portrait;

	ImageData armor;
	ImageData weapon;

	int selectedHeroIndex;

public:
	class DungeonScene* scene;

	CDungeonUI_HeroInfo();
	~CDungeonUI_HeroInfo();

	HRESULT Init();

	virtual void Update(float deltaTime, float worldTime);
	virtual void LateUpdate();

	virtual void BackRender(HDC _hdc);
	virtual void Render(HDC _hdc);
	virtual void FrontRender(HDC _hdc);

	virtual void Release();

	//==================================

	void setInfoImage(); //��� job�� �̹��� ����
	void setSkillIcon(); //��ư�� ��ų�Լ��� ����

	void setButton(); 
	void ShowHeroState(HDC _hdc);
	void showHeroSkill(HDC _hdc);
	void showHeroEquip(HDC _hdc);


	void SelectHero(int i);

	void SetPortrait(IMAGE _image);
	void SetWeapon(IMAGE _image);
	void SetArmor(IMAGE _image);


};