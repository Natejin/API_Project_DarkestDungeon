#pragma once
#include "GameObject.h"

class CHero;
class CParty;
class dungeonUI_info : public GameObject
{
private:
	vector<ImageData> HeroInfoImage; //장비, 히어로 아이콘, 스킬 이미지
	
	CHero* pos1Hero;
	CHero* pos2Hero;
	CHero* pos3Hero;
	CHero* pos4Hero;

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
	//씬에 속한 파티를 받아오기
	void setNowSceneParty(CParty* party);
	void setHeroJob(); //파티에 속한 영웅들의 정보를 세팅

	void setInfoImage(); //모든 job의 이미지 세팅
	void setSkillIcon(); //버튼과 스킬함수를 연결

	void showWhichHero(CHero* _hero); //보여줄 히어로를 선택

};