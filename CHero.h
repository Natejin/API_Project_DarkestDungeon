#pragma once
#include "Unit.h"

class Cplayer;
class DungeonScene;
class CHero : public Unit
{
	int heroID;

	int limit;
	bool isBattle;
	float speedFront;
	float speedBack;
	vector<ImageData> STRSbar;
	ImageData targeted_h_Mem; //appear when some member using healSkill
	



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


	void showStrsBar(HDC _hdc);

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

	virtual void SetMemberOverlay();

};