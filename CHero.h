#pragma once
#include "Unit.h"

class Cplayer;
class DungeonScene;
class CHero : public Unit
{
public:
	int heroID;

	JOB job;
	int ownIndex;
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

	int limit;

	bool isSelected;
	bool isBattle;

	float speedFront;
	float speedBack;

	vector<SKILL> ownSkill;

	//always
	ImageData HPbar_front;
	ImageData HPbar_back;
	vector<ImageData> STRSbar;
	ImageData selectedMem; 
	ImageData targeted_h_Mem; //appear when some member using healSkill


protected:
	function<void()> m_triggerWhenDown;
	bool canTriggerDown;

public:
	template <typename T>
	void SetTriggerWhenClick(T* pObj, void(T::* func)())
	{
		canTriggerDown = true;
		m_triggerWhenDown = bind(func, pObj);
	}

public:
	CHero();
	~CHero();

	HRESULT Init(JOB job,  int resist[],
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
	void setStress(int strs) { m_STRS = strs; }
	void addStress(int strs) { m_STRS += strs; }

	void Move();
	bool PreventGetOutBg(int startX, int endX);

	void setMemberOverlay();
	void showSelMember(HDC _hdc);
	void showHpStrsBar(HDC _hdc);

	void useSkill1();
	void useSkill2();
	void useSkill3();
	void useSkill4();
	void useMoveSkill();
	void usePassTrun();

	void setHpBar();
	void setSTRSbar();
	void setSelectedMem();
	void setTargetedMem();

};