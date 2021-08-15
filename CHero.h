#pragma once
#include "Unit.h"
#include "Info_Hero.h"

class Cplayer;
class DungeonScene;
class CHero : public Unit
{
	
	int m_DIST; //이동한 거리
	int m_DIST_retreat; //후퇴한 거리


	int heroID;
	int ownIndex;


	int limit;
	bool isBattle;
	float speedFront;
	float speedBack;
	vector<ImageData> STRSbar;
	ImageData targeted_h_Mem; //appear when some member using healSkill
	
	Info_Hero* info;

	int weaponLvl;
	int armorLvl;


public:
	CHero();
	~CHero();

	//HRESULT Init(JOB job,  int resist[],
	//	int HP, int SPD, int POS, int DMG,
	//	int ACRY, int CRI, int DEF, int DODGE);
	HRESULT Init(Info_Hero* _info);
	virtual void Update(float deltaTime, float worldTime);
	virtual void LateUpdate();

	virtual void BackRender(HDC _hdc);
	virtual void Render(HDC _hdc);
	virtual void FrontRender(HDC _hdc);

	virtual void Release();

	virtual IMAGE GetArmor();
	virtual IMAGE GetWeapon();

	virtual class Image* GetTrinketL();
	virtual class Image* GetTrinketR();


	//=====================================


	


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

	//GetStatus;
	virtual UNITTYPE GetUnitType();
	virtual int GetSpeed();

	virtual int getHP();
	virtual int getSPD();

	virtual int GetPartyIndex();
	virtual void SetPartyIndex(int pos);

	virtual int GetPartyPos();
	virtual void SetPartyPos(int pos);

	virtual int getResist(int index);
	virtual bool getAttribute(int index);
	virtual void setHP(int hp);
	virtual void setSPD(int spd);

	virtual void setResist(int index, bool val);
	virtual void setAttribute(int index, bool val);
	virtual void SetMemberOverlay();
	Info_Hero* GetInfo();

	int getMoveDis()const;
	int getMoveDis_reteat()const; 
	int getStress()const; 
	void setStress(int strs); 
	void addStress(int strs);
	vector<SKILL>GetOwnSkill();
	void SetHeroID(int id);
	int GetHeroID();
	void SetHeroJob(JOB job);
	JOB GetJob();
	void SetOwnIndex(int _ownindex);
	int GetOwnIndex();
	void SetAcry(int _acry);
	int GetAcry();
	void SetCri(int _cri);
	int GetCri();
	void SetDmg(int _dmg);
	int GetDmg();
	void SetDodge(int _dodge);
	int GetDodge();
	void SetDef(int _def);
	int GetDef();
};