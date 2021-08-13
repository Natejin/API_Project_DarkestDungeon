#pragma once
#include "GameObject.h"
#include "CButton_buttonPosMove.h"

class CHero;
class CParty;
class dungeonUI_HeroInfo : public GameObject
{
private:
	vector<ImageData> m_heroInfoImage; //���, ����� ������, ��ų �̹���
	vector<ImageData> m_invenOrMapImage; 

	ImageData portrait;

	//ImageData skill1;
	//ImageData skill2;
	//ImageData skill3;
	//ImageData skill4;

	ImageData armor;
	ImageData weapon;






	int selectedHeroIndex;

public:

	class DungeonScene* scene;

	dungeonUI_HeroInfo();
	~dungeonUI_HeroInfo();

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

	void selHero1();
	void selHero2();
	void selHero3();
	void selHero4();

};