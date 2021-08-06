#pragma once

struct DungeonData {
	DUNGEONMAPSTATE dungeonMapState = DUNGEONMAPSTATE::NONE;
	bool dirMap[4] = { false };
	int posX = 0;
	int posY = 0;
};