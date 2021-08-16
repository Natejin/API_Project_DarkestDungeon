#pragma once
#include "GameObject.h"

class Image;
class CMapSystem : public GameObject
{
public:
	DUNGEONSTATE m_dungeonState;
	DUNGEONMODE dungeonMode;
	DungeonData dungeonMap[MAPSIZE][MAPSIZE];

	DungeonData curDungeonMap;

	vector<class CMinimapButton*> dungeonMapCreate;
	class CMinimapButton* curPosPanel;
	class DungeonScene* dungeonScene;

	Vector2Int curPos;
	Vector2Int curDir;

	Vector2 minimapCenterPos;
	Vector2 minimapOriginPos;

	Vector2 customDragPos;

	bool canMoveAnotherRoom;

	int roadCount;
	int remainRoom;

	bool isCreatedEnemyOnRoad;
	bool isCreatedTresureOnRoad;
	bool isCreatedTrabOnRoad;

	float moveDistance;

private:
	vector<int> rndRoom;
	vector<int> rndRoad;

protected:
	int randRoomEnemy;
	int randRoomCurio;
	int randomRoadEnemy;
	int randomRoadCurio;
	int randomRoadTrap;

public:
	CMapSystem();
	~CMapSystem();

	HRESULT Init();

	virtual void Update(float deltaTime, float worldTime);
	virtual void LateUpdate();

	virtual void BackRender(HDC _hdc);
	virtual void Render(HDC _hdc);
	virtual void FrontRender(HDC _hdc);

	virtual void Release();


	void SetRandomCreateValue();

	//virtual void Update(float deltaTime, float worldTime);
	//virtual void LateUpdate();

	//virtual void BackRender(HDC _hdc);
	//virtual void Render(HDC _hdc);
	//virtual void FrontRender(HDC _hdc);

	void CreateDungeon();
	void CreateMapPart(int i, int j, int count, Vector2Int lastDir);

	Vector2Int GetDirFromInt(int dir);

	void MapButtonOnOff(bool active);

	void SetMapWitchCreated();

	void DragMinimap(Vector2 deltaMove);
	void SetMinimapPos(Vector2 deltaMove);
	void SetMinimapPosOrigin();

	DungeonData GetCurDungeonData();
	void SetIsPassed();
	void SetIsOpened();

	DungeonData GetCurDungeonData(int i);
	void SetIsPassed(int i);

	void UseClickToMoveCurPoint(DungeonData pos);
	void MoveCurPoint(Vector2Int dir);
	void UseKeyBoardToMoveCurPoint();
	void UseKeyBoardToReverseMoveCurPoint();
};