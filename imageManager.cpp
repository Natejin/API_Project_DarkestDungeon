#include "framework.h"
#include "imageManager.h"

imageManager::imageManager() {}
imageManager::~imageManager() {}

HRESULT imageManager::init()
{
	//여기에 모든 이미지를 넣어두고 사용
	MG_IMAGE->addImage("배경화면", "images/배경.bmp", WORLDSIZEX, WORLDSIZEY, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("카메라", "images/카메라.bmp", WINSIZEX / 10, WINSIZEY / 10, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("미니맵", "images/배경.bmp", WINSIZEX * 2 / 10, WINSIZEY / 10, true, RGB(255, 0, 255));

	//Darkest dungeon
	MG_IMAGE->addFrameImage("록맨", "images/록맨.bmp", 960, 200, 10, 2, true, RGB(255, 0, 255));
	MG_IMAGE->addFrameImage(IMAGE::Vestal_Idle, "images/Heroes/Vestal_Idle_Frame.bmp", 2400, 300, 12, 1, true, RGB(255, 0, 255));

	//resistance
	MG_IMAGE->addImage("bleed", "images/resistance/skill_attribute_bleed.bmp", 24, 24, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("buff", "images/resistance/skill_attribute_buff.bmp", 24, 24, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("debuff", "images/resistance/skill_attribute_debuff.bmp", 24, 24, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("diseade", "images/resistance/skill_attribute_disease.bmp", 24, 24, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("gaurd", "images/resistance/skill_attribute_guard.bmp", 24, 24, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("heal", "images/resistance/skill_attribute_heal.bmp", 24, 24, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("move", "images/resistance/skill_attribute_move.bmp", 24, 24, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("poison", "images/resistance/skill_attribute_poison.bmp", 24, 24, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("stress", "images/resistance/skill_attribute_stress.bmp", 24, 24, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("stun", "images/resistance/skill_attribute_stun.bmp", 24, 24, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("tag", "images/resistance/skill_attribute_tag.bmp", 24, 24, true, RGB(255, 0, 255));

	//panel
	MG_IMAGE->addImage("banner", "images/panel/panel_banner.bmp", 754, 136, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("controller", "images/panel/panel_banner_controller.bmp", 754, 136, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("hero", "images/panel/panel_hero.bmp", 720, 224, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("inventory", "images/panel/panel_inventory.bmp", 720, 360, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("map", "images/panel/panel_map.bmp", 720, 360, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("monster", "images/panel/panel_map.bmp", 702, 368, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("scouting", "images/panel/scoutingbanner.bmp", 366, 63, true, RGB(255, 0, 255));

	//Icon_Map
	MG_IMAGE->addImage("hall_clear", "images/icons_map/hall_clear.bmp", 24, 24, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("hall_dark", "images/icons_map/hall_dark.bmp", 24, 24, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("hall_dim", "images/icons_map/hall_dim.bmp", 24, 24, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("hall_door", "images/icons_map/hall_door.bmp", 24, 24, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("indicator", "images/icons_map/indicator.bmp", 51, 48, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("LockedRoom", "images/icons_map/LockedRoom.bmp", 64, 64, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("LockedRoom_Blue", "images/icons_map/LockedRoom_Blue.bmp", 64, 64, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("LockedRoom_Green", "images/icons_map/LockedRoom_Green.bmp", 64, 64, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("LockedRoom_Red", "images/icons_map/LockedRoom_Red.bmp", 64, 64, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("LockedRoom_Yellow", "images/icons_map/LockedRoom_Yellow.bmp", 64, 64, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("marker_battle", "images/icons_map/marker_battle.bmp", 24, 24, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("marker_curio", "images/icons_map/marker_curio.bmp", 24, 24, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("marker_hunger", "images/icons_map/marker_hunger.bmp", 24, 24, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("marker_obstacle", "images/icons_map/marker_obstacle.bmp", 24, 24, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("marker_room_visited", "images/icons_map/marker_room_visited.bmp", 64, 64, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("marker_secret", "images/icons_map/marker_secret.bmp", 24, 24, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("marker_trap", "images/icons_map/marker_trap.bmp", 24, 24, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("moving_room", "images/icons_map/moving_room.bmp", 64, 64, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("PrisonerRoom", "images/icons_map/PrisonerRoom.bmp", 64, 64, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("room_battle", "images/icons_map/room_battle.bmp", 64, 64, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("room_boss", "images/icons_map/room_boss.bmp", 64, 64, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("room_curio", "images/icons_map/room_curio.bmp", 64, 64, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("room_empty", "images/icons_map/room_empty.bmp", 64, 64, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("room_entrance", "images/icons_map/room_entrance.bmp", 64, 64, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("room_treasure", "images/icons_map/room_treasure.bmp", 64, 64, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("room_unknown", "images/icons_map/room_unknown.bmp", 64, 64, true, RGB(255, 0, 255));


	//========================================================
	//ruins-map
	//제일 뒷 배경
	MG_IMAGE->addImage("ruins_bg", "images/ruins/crypts_corridor_bg.bmp", WINSIZEY, WINSIZEY, false, RGB(255, 0, 255));

	//통로 벽
	MG_IMAGE->addImage("ruins_wall0", "images/ruins/crypts_corridor_door_basic.bmp", WINSIZEY, WINSIZEY, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("ruins_wall1", "images/ruins/crypts_corridor_wall_00.bmp", WINSIZEY, WINSIZEY, false, RGB(255, 0, 255));
	MG_IMAGE->addImage("ruins_wall3", "images/ruins/crypts_corridor_wall_02.bmp", WINSIZEY, WINSIZEY, false, RGB(255, 0, 255));
	MG_IMAGE->addImage("ruins_wall4", "images/ruins/crypts_corridor_wall_03.bmp", WINSIZEY, WINSIZEY, false, RGB(255, 0, 255));
	MG_IMAGE->addImage("ruins_wall7", "images/ruins/crypts_corridor_wall_06.bmp", WINSIZEY, WINSIZEY, false, RGB(255, 0, 255));
	//뚫린 벽
	MG_IMAGE->addImage("ruins_wall2", "images/ruins/transperant/crypts_corridor_wall_01.bmp", WINSIZEY, WINSIZEY, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("ruins_wall5", "images/ruins/transperant/crypts.corridor_wall_04.bmp", WINSIZEY, WINSIZEY, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("ruins_wall6", "images/ruins/transperant/crypts_corridor_wall_05.bmp", WINSIZEY, WINSIZEY, true, RGB(255, 0, 255));

	//방
	MG_IMAGE->addImage("ruins_room1", "images/ruins/crypts_room_wall_empty.bmp", WINSIZEX, WINSIZEY, false, RGB(255, 0, 255));
	MG_IMAGE->addImage("ruins_room2", "images/ruins/crypts_room_wall_library.bmp", WINSIZEX, WINSIZEY, false, RGB(255, 0, 255));
	MG_IMAGE->addImage("ruins_room3", "images/ruins/crypts_room_wall_entrance.bmp", WINSIZEX, WINSIZEY, false, RGB(255, 0, 255));
	MG_IMAGE->addImage("ruins_room4", "images/ruins/crypts_room_wall_drain.bmp", WINSIZEX, WINSIZEY, false, RGB(255, 0, 255));
	MG_IMAGE->addImage("ruins_room5", "images/ruins/crypts_room_wall_barrels.bmp", WINSIZEX, WINSIZEY, false, RGB(255, 0, 255));
	MG_IMAGE->addImage("ruins_room6", "images/ruins/crypts_room_wall_arch.bmp", WINSIZEX, WINSIZEY, false, RGB(255, 0, 255));
	MG_IMAGE->addImage("ruins_room7", "images/ruins/crypts_room_wall_altar.bmp", WINSIZEX, WINSIZEY, false, RGB(255, 0, 255));
	MG_IMAGE->addImage("ruins_room8", "images/ruins/crypts_entrance_room_wall.bmp", WINSIZEX, WINSIZEY, false, RGB(255, 0, 255));
	MG_IMAGE->addImage("ruins_room9", "images/ruins/crypts_room_wall_torture.bmp", WINSIZEX, WINSIZEY, false, RGB(255, 0, 255));

	//기타
	MG_IMAGE->addImage("ruins_endhall", "images/ruins/transperant/crypts_endhall_01.bmp", WINSIZEY, WINSIZEY, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("ruins_mid", "images/ruins/transperant/crypts_corridor_mid.bmp", WINSIZEY, WINSIZEY, true, RGB(255, 0, 255));

	//제일 앞 배경
	MG_IMAGE->addImage("ruins_bottom", "images/ruins/transperant/crypts_foreground_bottom_01.bmp", WINSIZEY, 101, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("ruins_top", "images/ruins/transperant/crypts_foreground_top_01.bmp", WINSIZEY, 330, true, RGB(255, 0, 255));


	//========================================================
	//임시 이미지
	//캐릭터
	MG_IMAGE->addFrameImage(IMAGE::Vestal_Idle, "images/임시/임시이미지(플레이어).bmp", 400, 700, 1, 1, true, RGB(255, 0, 255));
	MG_IMAGE->addFrameImage("crusader", "images/임시/임시이미지(플레이어).bmp", 400, 700, 1, 1, true, RGB(255, 0, 255));
	MG_IMAGE->addFrameImage("highwayMan", "images/임시/임시이미지(플레이어).bmp", 400, 700, 1, 1, true, RGB(255, 0, 255));
	MG_IMAGE->addFrameImage("plagueDoctor", "images/임시/임시이미지(플레이어).bmp", 400, 700, 1, 1, true, RGB(255, 0, 255));

	//몬스터
	MG_IMAGE->addFrameImage("mon1", "images/임시/임시이미지(적).bmp", 400, 700, 1, 1, true, RGB(255, 0, 255));
	MG_IMAGE->addFrameImage("mon2", "images/임시/임시이미지(적).bmp", 400, 700, 1, 1, true, RGB(255, 0, 255));
	MG_IMAGE->addFrameImage("mon3", "images/임시/임시이미지(적).bmp", 400, 700, 1, 1, true, RGB(255, 0, 255));
	MG_IMAGE->addFrameImage("mon4", "images/임시/임시이미지(적).bmp", 400, 700, 1, 1, true, RGB(255, 0, 255));

	//배경
	MG_IMAGE->addFrameImage("bg", "images/임시/temporary bg.bmp", WORLDSIZEX, WORLDSIZEY, 1, 1, true, RGB(255, 0, 255));
	return S_OK;
}

void imageManager::release()
{
	deleteAll();
}

Image* imageManager::addImage(string strKey, const int width, const int height)
{
	//추가하려는 키값으로 이미지 존재하는지 확인
	Image* img = findImage(strKey);
	//추가하려는 이미지가 이미 있으면 리턴
	if (img)return img;

	img = new Image;

	//이미지가 초기화되지 않으면
	if (FAILED(img->init(width, height)))
	{
		SAFE_DELETE(img);
		return NULL;
	}

	//생성된 이미지를 맵으로 만든 이미지 목록에추가한다.
	_mImageList.insert(make_pair(strKey, img));

	return img;
}

Image* imageManager::addImage(string strKey, const char* fileName, const int width, const int height, bool trans, COLORREF transColor)
{
	//추가하려는 키값으로 이미지 존재하는지 확인
	Image* img = findImage(strKey);
	//추가하려는 이미지가 이미 있으면 리턴
	if (img)return img;

	img = new Image;

	//이미지가 초기화되지 않으면
	if (FAILED(img->init(fileName, width, height, trans, transColor)))
	{
		SAFE_DELETE(img);
		return NULL;
	}

	//생성된 이미지를 맵으로 만든 이미지 목록에추가한다.
	_mImageList.insert(make_pair(strKey, img));

	return img;
}

Image* imageManager::addImage(string strKey, const char* fileName, const float x, const float y, const int const width, const int height, bool trans, COLORREF transColor)
{
	//추가하려는 키값으로 이미지 존재하는지 확인
	Image* img = findImage(strKey);
	//추가하려는 이미지가 이미 있으면 리턴
	if (img)return img;

	img = new Image;

	//이미지가 초기화되지 않으면
	if (FAILED(img->init(fileName, x, y, width, height, trans, transColor)))
	{
		SAFE_DELETE(img);
		return NULL;
	}

	//생성된 이미지를 맵으로 만든 이미지 목록에추가한다.
	_mImageList.insert(make_pair(strKey, img));

	return img;
}

Image* imageManager::addFrameImage(string strKey, const char* fileName, const int width, const int height, const int frameX, const int frameY, bool trans, COLORREF transColor)
{
	//추가하려는 키값으로 이미지 존재하는지 확인
	Image* img = findImage(strKey);
	//추가하려는 이미지가 이미 있으면 리턴
	if (img)return img;

	img = new Image;

	//이미지가 초기화되지 않으면
	if (FAILED(img->init(fileName, width, height, frameX, frameY, trans, transColor)))
	{
		SAFE_DELETE(img);
		return NULL;
	}

	//생성된 이미지를 맵으로 만든 이미지 목록에추가한다.
	_mImageList.insert(make_pair(strKey, img));

	return img;
}

Image* imageManager::addFrameImage(string strKey, const char* fileName, const float x, const float y, const int width, const int height, const int frameX, const int frameY, bool trans, COLORREF transColor)
{
	//추가하려는 키값으로 이미지 존재하는지 확인
	Image* img = findImage(strKey);
	//추가하려는 이미지가 이미 있으면 리턴
	if (img)return img;

	img = new Image;

	//이미지가 초기화되지 않으면
	if (FAILED(img->init(fileName, x, y, width, height, frameX, frameY, trans, transColor)))
	{
		SAFE_DELETE(img);
		return NULL;
	}

	//생성된 이미지를 맵으로 만든 이미지 목록에추가한다.
	_mImageList.insert(make_pair(strKey, img));

	return img;
}

Image* imageManager::findImage(string strKey)
{
	//해당키 검색
	mapImageListIter key = _mImageList.find(strKey);

	//키를 찾으면
	if (key != _mImageList.end())
	{
		return key->second;
	}
	return NULL;
}

bool imageManager::deleteImage(string strKey)
{
	mapImageListIter key = _mImageList.find(strKey);

	if (key != _mImageList.end())
	{
		key->second->release();
		SAFE_DELETE(key->second);
		_mImageList.erase(key);
		return true;
	}
	return false;
}

bool imageManager::deleteAll()
{
	//맵 전체를 돌면서 삭제한다.
	mapImageListIter iter = _mImageList.begin();

	for (iter; iter != _mImageList.end();)
	{
		if (iter->second != NULL)
		{
			SAFE_DELETE(iter->second);
			iter = _mImageList.erase(iter);
		}
		else ++iter;
	}
	_mImageList.clear();
	return true;
}





void imageManager::render(string strKey, HDC hdc)
{
	//이미지를 찾은 후 렌더
	Image* img = findImage(strKey);
	if (img) img->render(hdc);
}

void imageManager::render(string strKey, HDC hdc, const int destX, const int destY)
{
	Image* img = findImage(strKey);
	if (img) img->render(hdc, destX, destY);
}

void imageManager::render(string strKey, HDC hdc, const int destX, const int destY, const int sourX, const int sourY, const int sourWidth, const int sourHeight)
{
	Image* img = findImage(strKey);
	if (img) img->render(hdc, destX, destY, sourX, sourY, sourWidth, sourHeight);
}

void imageManager::frameRender(string strKey, HDC hdc, const int destX, const int destY)
{
	Image* img = findImage(strKey);
	if (img) img->frameRender(hdc, destX, destY);
}

void imageManager::frameRender(string strKey, HDC hdc, const int destX, const int destY, const int currentFrameX, const int currentFrameY)
{
	Image* img = findImage(strKey);
	if (img) img->frameRender(hdc, destX, destY, currentFrameX, currentFrameY);
}

void imageManager::loopRender(string strKey, HDC hdc, const LPRECT drawArea,int offSetX, int offSetY)
{
	Image* img = findImage(strKey);
	if (img) img->loopRender(hdc, drawArea, offSetX, offSetY);
}

void imageManager::loopAlphaRender(string strKey, HDC hdc, const LPRECT drawArea, int offSetX, int offSetY, BYTE alpha)
{
	Image* img = findImage(strKey);
	if (img) img->loopAlphaRender(hdc, drawArea, offSetX, offSetY, alpha);
}






//
//
Image* imageManager::addImage(IMAGE strKey, const int width, const int height)
{
	//추가하려는 키값으로 이미지 존재하는지 확인
	Image* img = findImage(strKey);
	//추가하려는 이미지가 이미 있으면 리턴
	if (img)return img;

	img = new Image;

	//이미지가 초기화되지 않으면
	if (FAILED(img->init(width, height)))
	{
		SAFE_DELETE(img);
		return NULL;
	}

	//생성된 이미지를 맵으로 만든 이미지 목록에추가한다.
	m_ImageMap.insert(make_pair(strKey, img));

	return img;
}

Image* imageManager::addImage(IMAGE strKey, const char* fileName, const int width, const int height, bool trans, COLORREF transColor)
{
	//추가하려는 키값으로 이미지 존재하는지 확인
	Image* img = findImage(strKey);
	//추가하려는 이미지가 이미 있으면 리턴
	if (img)return img;

	img = new Image;

	//이미지가 초기화되지 않으면
	if (FAILED(img->init(fileName, width, height, trans, transColor)))
	{
		SAFE_DELETE(img);
		return NULL;
	}

	//생성된 이미지를 맵으로 만든 이미지 목록에추가한다.
	m_ImageMap.insert(make_pair(strKey, img));

	return img;
}

Image* imageManager::addImage(IMAGE strKey, const char* fileName, const float x, const float y, const int const width, const int height, bool trans, COLORREF transColor)
{
	//추가하려는 키값으로 이미지 존재하는지 확인
	Image* img = findImage(strKey);
	//추가하려는 이미지가 이미 있으면 리턴
	if (img)return img;

	img = new Image;

	//이미지가 초기화되지 않으면
	if (FAILED(img->init(fileName, x, y, width, height, trans, transColor)))
	{
		SAFE_DELETE(img);
		return NULL;
	}

	//생성된 이미지를 맵으로 만든 이미지 목록에추가한다.
	m_ImageMap.insert(make_pair(strKey, img));

	return img;
}

Image* imageManager::addFrameImage(IMAGE strKey, const char* fileName, const int width, const int height, const int frameX, const int frameY, bool trans, COLORREF transColor)
{
	//추가하려는 키값으로 이미지 존재하는지 확인
	Image* img = findImage(strKey);
	//추가하려는 이미지가 이미 있으면 리턴
	if (img)return img;

	img = new Image;

	//이미지가 초기화되지 않으면
	if (FAILED(img->init(fileName, width, height, frameX, frameY, trans, transColor)))
	{
		SAFE_DELETE(img);
		return NULL;
	}

	//생성된 이미지를 맵으로 만든 이미지 목록에추가한다.
	m_ImageMap.insert(make_pair(strKey, img));

	return img;
}

Image* imageManager::addFrameImage(IMAGE strKey, const char* fileName, const float x, const float y, const int width, const int height, const int frameX, const int frameY, bool trans, COLORREF transColor)
{
	//추가하려는 키값으로 이미지 존재하는지 확인
	Image* img = findImage(strKey);
	//추가하려는 이미지가 이미 있으면 리턴
	if (img)return img;

	img = new Image;

	//이미지가 초기화되지 않으면
	if (FAILED(img->init(fileName, x, y, width, height, frameX, frameY, trans, transColor)))
	{
		SAFE_DELETE(img);
		return NULL;
	}

	//생성된 이미지를 맵으로 만든 이미지 목록에추가한다.
	m_ImageMap.insert(make_pair(strKey, img));

	return img;
}

Image* imageManager::findImage(IMAGE strKey)
{
	//해당키 검색
	mapImageIter key = m_ImageMap.find(strKey);

	//키를 찾으면
	if (key != m_ImageMap.end())
	{
		return key->second;
	}
	return NULL;
}

bool imageManager::deleteImage(IMAGE strKey)
{
	mapImageIter key = m_ImageMap.find(strKey);

	if (key != m_ImageMap.end())
	{
		key->second->release();
		SAFE_DELETE(key->second);
		m_ImageMap.erase(key);
		return true;
	}
	return false;
}



void imageManager::render(IMAGE strKey, HDC hdc)
{
	//이미지를 찾은 후 렌더
	Image* img = findImage(strKey);
	if (img) img->render(hdc);
}

void imageManager::render(IMAGE strKey, HDC hdc, const int destX, const int destY)
{
	Image* img = findImage(strKey);
	if (img) img->render(hdc, destX, destY);
}

void imageManager::render(IMAGE strKey, HDC hdc, const int destX, const int destY, const int sourX, const int sourY, const int sourWidth, const int sourHeight)
{
	Image* img = findImage(strKey);
	if (img) img->render(hdc, destX, destY, sourX, sourY, sourWidth, sourHeight);
}

void imageManager::frameRender(IMAGE strKey, HDC hdc, const int destX, const int destY)
{
	Image* img = findImage(strKey);
	if (img) img->frameRender(hdc, destX, destY);
}

void imageManager::frameRender(IMAGE strKey, HDC hdc, const int destX, const int destY, const int currentFrameX, const int currentFrameY)
{
	Image* img = findImage(strKey);
	if (img) img->frameRender(hdc, destX, destY, currentFrameX, currentFrameY);
}

void imageManager::loopRender(IMAGE strKey, HDC hdc, const LPRECT drawArea, int offSetX, int offSetY)
{
	Image* img = findImage(strKey);
	if (img) img->loopRender(hdc, drawArea, offSetX, offSetY);
}

void imageManager::loopAlphaRender(IMAGE strKey, HDC hdc, const LPRECT drawArea, int offSetX, int offSetY, BYTE alpha)
{
	Image* img = findImage(strKey);
	if (img) img->loopAlphaRender(hdc, drawArea, offSetX, offSetY, alpha);
}