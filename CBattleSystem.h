#pragma once
#include "GameObject.h"

class Unit;
class CBattleSystem : public GameObject
{
	struct TurnSpeedOfUnit {
		Unit* unit;
		int turnSpeed;

	};


	vector<class CHero*> heroParty;
	vector<class CEnemy*> enemyParty;
	queue<TurnSpeedOfUnit> speedQueue;

	vector<pair <int, Unit*> > speedVec;

	int randomDice6 = 6;

	int curTurn;

public:
	class DungeonScene* scene;

	CBattleSystem();
	~CBattleSystem();

	HRESULT Init();

	virtual void Update(float deltaTime, float worldTime);
	virtual void LateUpdate();

	virtual void BackRender(HDC _hdc);
	virtual void Render(HDC _hdc);
	virtual void FrontRender(HDC _hdc);

	virtual void Release();


	void BattleSystemInitiate();
	void BattleSystemEnd();

	void UseSkill1();
	void UseSkill2();
	void UseSkill3();
	void UseSkill4();

private:
	void CreateEnemyParty();
	void CreateHeroesParty();
	void Compare_P_E_Speed_ReArray();
};