#pragma once

struct DungeonData {
	DUNGEONMAPSTATE dungeonMapState = DUNGEONMAPSTATE::NONE;
	bool dirMap[4] = { false };
	ImageData m_imageData;

	Vector2Int pos;
	bool isRoom = false;
	bool isSearched = false;
};