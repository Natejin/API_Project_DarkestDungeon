#pragma once

struct DungeonData {
public:
	DUNGEONMAPSTATE dungeonMapState = DUNGEONMAPSTATE::NONE;
	bool dirMap[4] = { false };
	Vector2Int pos;
	Vector2 posFromCenter;
	bool isRoom = false;
	bool isSearched = false;
	bool isHorizontal = false;
};