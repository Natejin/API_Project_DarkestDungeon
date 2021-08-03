#pragma once
#include "GameObject.h"

class CHero;
class Vestal;
class CParty : public GameObject
{
private:
	//�ʱ�ȭ���� ��� �Ҵ�, ������ ����
	//����� 1�� ������ �����Ұ�����
	vector<CHero*> m_member;
	//vector<CHero*>::iterator m_imember;

	//���� ����� 0���� �ƴ���
	bool memberCount0;

	int maxPartyMember;

	//�Ҹ� �������� ����
	int m_Item_food;
	int m_Item_bandage;
	int m_Item_Torch;

	//ȶ���� ���
	int m_brightness;

	//�׽�Ʈ��
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

	//UI�� ���� ���⿡�� �ø� �ʿ䰡 ����?
	virtual void BackRender(HDC _hdc);
	virtual void Render(HDC _hdc);
	virtual void FrontRender(HDC _hdc);

	virtual void Release();

	//=====================================

	void SetParty(vector<CHero*> member);
	void SetHero(CHero* member);
	void SetCamera();
	CHero* GetHero(int index);

	//void createParty(); //�׽�Ʈ��
	//void createParty(CHero* mem1, CHero* mem2, CHero* mem3, CHero* mem4);

	//1. vector�� ������ pos���� �°� ���� (�� �ʿ��Ѱ�?)
	//2. ���ݰ��ɿ��δ� pos������ Ȯ��
	//3. pos���� ���� ȭ��� �������� ��ġ
	void SetFormation();
	void getFormation(string name);

	//void createVestal(string name, Vector2 pos);
	//void createCrusader(CHero* hero, string name);
	//void createPlagueDoctor(CHero* hero, string name);
	//void createHighwayMan(CHero* hero, string name);

	void FormationMove();

	//�������� ���� get/set
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
