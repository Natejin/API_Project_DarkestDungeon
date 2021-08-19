#pragma once
#include "GameObject.h"

class CHero;
class Vestal;
class CParty : public GameObject
{
private:
	vector<CHero*> m_member;

	bool memberCount0;
	int maxPartyMember;

	//º“∏º∫ æ∆¿Ã≈€¿« ∞πºˆ
	int m_Item_food;
	int m_Item_bandage;
	int m_Item_Torch;

	//»∂∫“¿« π‡±‚
	int m_brightness;

	//walkFont 
	int WF_btwHeroes = 150;
	//wlakBack
	int WB_btwHeroes = 125;

	int limit;
	int limit2;
	int selectedHeroIndex;

	float curWalkTime;
	float curWalkCoolTime;

	vector<SOUND> m_vSound;

	DUNGEONSTATE nowScene;

public:
	CParty();
	~CParty();

	HRESULT Init();
	HRESULT Init(int food, int bandage, int torch);

	virtual void Update(float deltaTime, float worldTime);
	virtual void LateUpdate();

	virtual void BackRender(HDC _hdc);
	virtual void Render(HDC _hdc);
	virtual void FrontRender(HDC _hdc);

	virtual void Release();

	//==================================
	void SelectHero(int index) { selectedHeroIndex = index; };


	void SetPartyMember(vector<CHero*> member);
	void SetHero(CHero* member);
	void SetCamera();
	//int GetPartySize() { return MG_GAME->GetHeroPartySizeber.size(); }

	vector<CHero*> GetParty() { return m_member; }
	int GetPartySize() { return m_member.size(); }
	CHero* GetHero(int index);

	void FormationMove();

	//æ∆¿Ã≈€¿« ∞πºˆ get/set
	void setTorch(int torch);
	int getTorch() { return m_Item_Torch; }
	void setFood(int food);
	int getFood() { return m_Item_food; }
	void setBandage(int bandage);
	int getBandage() { return m_Item_bandage; }

	void setBrightness(int brightness);
	int getBrightness() { return m_brightness; }

	void decreaseBright_movement();
	void getStress_movement();

	void showMemberInfo(HDC _hdc);
	void showItem(HDC _hdc);
	void showDis(HDC _hdc);

};