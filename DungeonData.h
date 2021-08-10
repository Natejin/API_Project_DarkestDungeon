#pragma once

struct DungeonData {
	DUNGEONMAPSTATE dungeonMapState = DUNGEONMAPSTATE::NONE;
	bool dirMap[4] = { false };
	Image* m_image = nullptr;

	Vector2Int pos;
	bool isRoom = false;
	bool isSearched = false;
};