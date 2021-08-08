#pragma once
#include "GameObject.h"

class CHero;
class CParty;
class dungeonUI_info : public GameObject
{
private:
	vector<ImageData> HeroInfoImage; //���, ����� ������, ��ų �̹���
	
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
	//���� ���� ��Ƽ�� �޾ƿ���
	void setNowSceneParty(CParty* party);
	void setHeroJob(); //��Ƽ�� ���� �������� ������ ����

	void setInfoImage(); //��� job�� �̹��� ����
	void setSkillIcon(); //��ư�� ��ų�Լ��� ����

	void showWhichHero(CHero* _hero); //������ ����θ� ����

};