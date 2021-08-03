#pragma once
#include "GameObject.h"

class CHero;
class Vestal;
class CParty : public GameObject
{
private:
	//초기화에서 멤버 할당, 없으면 삭제
	//멤버가 1명도 없으면 원정불가판정
	vector<CHero*> m_member;
	//vector<CHero*>::iterator m_imember;

	//원정 멤버가 0인지 아닌지
	bool memberCount0;

	int maxPartyMember;

	//소모성 아이템의 갯수
	int m_Item_food;
	int m_Item_bandage;
	int m_Item_Torch;

	//횃불의 밝기
	int m_brightness;

	//테스트용
	//CHero* member1;
	//CHero* member2;
	//CHero* member3;
	//CHero* member4;

	Vestal* member5;

	//formation
	//walkFont 
	int WF_btwHeroes = 150;
	//wlakBack
	int WB_btwHeroes = 100;


public:
	CParty();
	~CParty();

	HRESULT Init();
	HRESULT Init(int food, int bandage, int torch);

	virtual void Update(float deltaTime, float worldTime);
	virtual void LateUpdate();

	//UI는 따로 여기에서 올릴 필요가 없나?
	virtual void BackRender(HDC _hdc);
	virtual void Render(HDC _hdc);
	virtual void FrontRender(HDC _hdc);

	virtual void Release();

	//=====================================

	void SetParty(vector<CHero*> member);
	void SetHero(CHero* member);
	void SetCamera();
	CHero* GetHero(int index);

	//void createParty(); //테스트용
	//void createParty(CHero* mem1, CHero* mem2, CHero* mem3, CHero* mem4);

	//1. vector의 순서를 pos값에 맞게 조정 (꼭 필요한가?)
	//2. 공격가능여부는 pos값으로 확인
	//3. pos값에 따라 화면상 렌더링과 배치
	void SetFormation();
	void getFormation(string name);

	//void createVestal(string name, Vector2 pos);
	//void createCrusader(CHero* hero, string name);
	//void createPlagueDoctor(CHero* hero, string name);
	//void createHighwayMan(CHero* hero, string name);

	void FormationMove();

	//아이템의 갯수 get/set
	void setTorch(int torch);
	int getTorch() { return m_Item_bandage; }
	void setFood(int food);
	int getFood() { return m_Item_food; }
	void setBandage(int bandage);
	int getBandage() { return m_Item_bandage; }

	void setBrightness(int brightness);
	int getBrightness() { return m_brightness; }

	void decreaseBright_movement();

	void showMemberInfo(HDC _hdc);
	void showItem(HDC _hdc);
	void showDis(HDC _hdc);
};
