#pragma once

struct DungeonData {
public:
	DUNGEONMAPSTATE dungeonMapState = DUNGEONMAPSTATE::NONE;
	bool dirMap[4] = { false };
	Vector2Int pos;
	Vector2 posFromCenter;
	RoadObjType m_roadObjType;
	int farFromHome;
	//RoomObjType m_roomObjType;
	bool reachable = false;
	bool isRoom = false;
	bool isSearched = false;
	bool isHorizontal = false;
	bool isPassed = false;
	bool isOpenedTreasure = false;
};