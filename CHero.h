#pragma once
#include "Unit.h"

class Cplayer;
class DungeonScene;
class CHero : public Unit
{
public:
	JOB job;

	//unit: HP, SPD, POS, SKILL, resist, attribute
	//hero�� ���� ����
	int m_DMG; //skill���� �� �־��ֱ�
	int m_ACRY; //���߷�
	int m_CRI;
	int m_DEF;
	int m_DODGE; //ȸ����

	int m_LVL; //stress���� ����?
	int m_EXP;
	int m_STRS;
	int m_STRSLVL; //��Ʈ������ ����

	int m_DIST; //�̵��� �Ÿ�
	int m_DIST_retreat; //������ �Ÿ�

public:
	CHero();
	~CHero();

	HRESULT Init(JOB job, IMAGE img, int resist[],
		int HP, int SPD, int POS, int DMG,
		int ACRY, int CRI, int DEF, int DODGE);

	virtual void Update(float deltaTime, float worldTime);
	virtual void LateUpdate();

	virtual void BackRender(HDC _hdc);
	virtual void Render(HDC _hdc);
	virtual void FrontRender(HDC _hdc);

	virtual void Release();


	//=====================================


	int getMoveDis()const { return m_DIST; }
	int getMoveDis_reteat()const { return m_DIST_retreat; }

	int getStress()const { return m_STRS; }
	void setStress(int strs) { m_STRS += strs; }

	//int getPos()const { return m_POS; }
	//void setPos(int pos) { m_POS = pos; }

	void Move();
	bool PreventGetOutBg(int startX, int endX);

};