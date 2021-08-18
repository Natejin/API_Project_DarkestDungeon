#pragma once
#include "GameObject.h"

class Unit;
class CEnemyInfoUI;
class CBattleSystem : public GameObject
{
public:
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
	Vector2 originPosOfBattle;
	vector<class CHero*> heroParty;
	vector<class CEnemy*> enemyParty;

	vector<int> posEnemy;
	vector<int> posHero;

	queue<TurnSpeedOfUnit> speedQueue;
	vector<pair<int, Unit*>> speedVec;
	float delayTriggerEffect = 3;

	int randomDice6 = 6;
	int randomDice100 = 100;

	int curTurn;
	bool isSwapModeOn; 
	float moveSpeed;

	class CHero* curHero;
	class CEnemy* curEnemy;

	int currentSkill;

	class ImageObject* heroZoomImage;
	class ImageObject* enemyZoomImage;
	class ImageEffectBG* effectBGImage;
	class MonsterIndicator* monsterIndicator;

	float startTriggerTime;
	float soundEffectVolume = 0.5f;
	bool startNextTurn;
	bool delayForSwapSetPosition;
	vector< Vector2> targetEnemyPosVec;
	bool isBattle;
public:
	class DungeonScene* scene;
	class dungeonUI* dungeonUI;
	class CDungeonUI_HeroInfo* dungeonUIHeroinfo;
	
	CEnemyInfoUI* m_enemyInfoUI;

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

	void SwapPosSkill();

private:
	CEnemy* GetEnemy(int i);
	void SelectEnemy(int index);

	bool CheckAndDamageEnemy(CInfo_Skill* tempSkill, int index);
	void DelayUntillNextTurn(int second);
	bool CheckAndDamageHero(CInfo_Skill* tempSkill, int index);

	void SelectHero(int index);
	void CheckAndHealAlly(CInfo_Skill* tempSkill, int index);
	void SetZoomImage(ImageObject* zoomImage, IMAGE skillMotion, float distance, float speed);
	void SelectHeroTarget(SKILL skill);

	void DeselectAll();

	void CheckAndSwapHeroPos(int index);

	void SetEnemyIndicator(int index);
	void SelectEnemyTarget(SKILL skill);

	void SetPosition();

	CHero* GetHero(int i);
	void StartHeroTrun(int index);

	void StartEnemyTrun(int index);

	void SetEffectImage(Vector2 startPos, Vector2 targetPos, float speed);
	void ShowTargetBySkill(int index);

	void HeroTeamAreDead();
	void EnemyTeamAreDead();

private:
	void CreateEnemyParty();
	void CreateHeroesParty();

	void Compare_P_E_Speed_ReArray();
};