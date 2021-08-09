#pragma once
#include "GameObject.h"

class CHero;
class CParty;
class dungeonUI_info : public GameObject
{
private:
	vector<ImageData> m_heroInfoImage; //���, ����� ������, ��ų �̹���
	vector<ImageData> m_invenOrMapImage; 

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

	void setHeroJob(); //��Ƽ�� ���� �������� ������ ����

	void setInfoImage(); //��� job�� �̹��� ����
	void setSkillIcon(); //��ư�� ��ų�Լ��� ����

	void showWhichHero(CHero* _hero); //������ ����θ� ����

};