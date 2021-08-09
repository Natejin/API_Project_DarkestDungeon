#pragma once
#include "GameObject.h"

class CHero;
class CParty;
class dungeonUI_info : public GameObject
{
private:
	vector<ImageData> m_heroInfoImage; //장비, 히어로 아이콘, 스킬 이미지
	vector<ImageData> m_invenOrMapImage; 

	int selectedHeroIndex;

public:
	dungeonUI_info();
	~dungeonUI_info();

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

	void showWhichHero(CHero* _hero); //보여줄 히어로를 선택
	void showHeroState(HDC _hdc);
	void showHeroSkill(HDC _hdc);
	void showHeroEquip(HDC _hdc);
};