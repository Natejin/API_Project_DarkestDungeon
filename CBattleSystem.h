#pragma once
#include "GameObject.h"

class Unit;
class CBattleSystem : public GameObject
{
	struct TurnSpeedOfUnit {
		Unit* unit;
		int turnSpeed;
	};

	enum class TURN
	{
		Player,
		Enemy
	};

	TURN turn;

	vector<class CHero*> heroParty;
	vector<class CEnemy*> enemyParty;
	queue<TurnSpeedOfUnit> speedQueue;
	vector<pair<int, Unit*>> speedVec;


	int randomDice6 = 6;
	int randomDice100 = 100;

	int curTurn;

	class CHero* curHero;
	class CEnemy* curEnemy;


	int currentSkill;

	class ImageObject* heroZoomImage;
	class ImageObject* enemyZoomImage;
	class MonsterIndicator* monsterIndicator;


	float startTriggerTime;
	bool startNextTurn;
	vector< Vector2> targetEnemyPosVec;
	
public:
	class DungeonScene* scene;
	class dungeonUI* dungeonUI;
	class CDungeonUI_HeroInfo* dungeonUIHeroinfo;
	CBattleSystem();
	~CBattleSystem();



	HRESULT Init();

	void SetZoomImage();

	virtual void Update(float deltaTime, float worldTime);
	virtual void LateUpdate();

	virtual void BackRender(HDC _hdc);
	virtual void Render(HDC _hdc);
	virtual void FrontRender(HDC _hdc);

	virtual void Release();


	void BattleSystemInitiate();
	void BattleSystemEnd();

	void StartTurn();
	void HeroTurn();
	void EnemyTurn();
	void EndTurn();

	void UseSkill(int _index);


private:
	CEnemy* GetEnemy(int i);
	void SelectEnemy(int index);

	void CheckAndDamageEnemy(CInfo_Skill* tempSkill, int index);

	void SelectHero(int index);
	void CheckAndHealAlly(CInfo_Skill* tempSkill, int index);
	void SelectHeroTarget(SKILL skill);

	void DeselectAll();

	void SetEnemyIndicator(int index);
	void SelectEnemyTarget(SKILL skill);

	CHero* GetHero(int i);
	void StartHeroTrun(int index);

	void StartEnemyTrun(int index);

	void ShowTargetBySkill(int index);


private:
	void CreateEnemyParty();
	void CreateHeroesParty();
	void Compare_P_E_Speed_ReArray();
};