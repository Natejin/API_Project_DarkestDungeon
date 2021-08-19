#pragma once
#include "GameObject.h"

class MonsterIndicator : public GameObject
{
public:

	vector< Vector2> targetEnemyPosVec;

	int enemyPosIndex;
public:
	MonsterIndicator();
	~MonsterIndicator();

	HRESULT Init();

	virtual void Update(float deltaTime, float worldTime);
	virtual void LateUpdate();

	virtual void BackRender(HDC _hdc);
	virtual void Render(HDC _hdc);
	virtual void FrontRender(HDC _hdc);

	virtual void Release();

	virtual void Enable();
	virtual void Disable();


	void PushEnemyPos(Vector2 pos);
	virtual void SetPosIndex(int _index);
	virtual void MonsterIsTargetSkill(bool isTarget);
};
