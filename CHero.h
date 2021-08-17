#pragma once
#include "Unit.h"
#include "Info_Hero.h"

class Cplayer;
class DungeonScene;
class CHero : public Unit
{
	
	int m_DIST; //�̵��� �Ÿ�
	int m_DIST_retreat; //������ �Ÿ�


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
	bool isTargetHeal;

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
	virtual bool reduceHP(int hp);
	virtual void increaseHP(int hp);
	virtual void setHP(int hp);
	virtual int getMaxHP();

	virtual int getSPD();
	virtual void setSPD(int spd);

	//virtual int GetPartyIndex();
	//virtual void SetPartyIndex(int pos);

	//virtual int GetPartyPos();
	//virtual void SetPartyPos(int pos);

	virtual int getResist(int index);
	virtual bool getAttribute(int index);

	virtual void setResist(int index, bool val);
	virtual void setAttribute(int index, bool val);
	virtual void SetMemberOverlay();
	Info_Hero* GetInfo();

	virtual int getMoveDis()const;
	virtual int getMoveDis_reteat()const; 
	virtual int getStress()const; 
	virtual void setStress(int strs); 
	virtual void addStress(int strs);
	virtual vector<SKILL>GetOwnSkill();
	virtual void SetHeroID(int id);
	virtual int GetHeroID();
	virtual void SetHeroJob(JOB job);
	virtual JOB GetJob();
	virtual void SetOwnIndex(int _ownindex);
	virtual int GetOwnIndex();
	virtual void SetAcry(int _acry);
	virtual int GetAcry();
	virtual void SetCri(int _cri);
	virtual int GetCri();
	virtual void SetDmg(int _dmg);
	virtual int GetDmg();
	virtual void SetDodge(int _dodge);
	virtual int GetDodge();
	virtual void SetDef(int _def);
	virtual int GetDef();

	virtual bool GetAffliction();
	virtual bool GetAlive();

};