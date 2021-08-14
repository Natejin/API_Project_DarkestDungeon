#pragma once
#include "GameObject.h"
#include "CButton_buttonPosMove.h"

class CHero;
class CParty;
class CDungeonUI_HeroInfo : public GameObject
{
private:
	vector<ImageData> m_heroInfoImage; //장비, 히어로 아이콘, 스킬 이미지
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

	void setInfoImage(); //모든 job의 이미지 세팅
	void setSkillIcon(); //버튼과 스킬함수를 연결

	void setButton(); 
	void ShowHeroState(HDC _hdc);
	void showHeroSkill(HDC _hdc);
	void showHeroEquip(HDC _hdc);


	void SelectHero(int i);

	void SetPortrait(IMAGE _image);
	void SetWeapon(IMAGE _image);
	void SetArmor(IMAGE _image);


};