#include "framework.h"
#include "ImageAdder_MJ.h"

HRESULT ImageAdder_MJ::Init()
{
	//나중에 imageMap 형식으로 업데이트
	//ruins-map
	//제일 뒷 배경
	MG_IMAGE->addImage("ruins_bg", "images/ruins/crypts_corridor_bg.bmp", 1920, 720, false, RGB(255, 0, 255));

	//통로 벽
	MG_IMAGE->addImage("ruins_wall0", "images/ruins/crypts_corridor_door_basic.bmp", 720, 720, false, RGB(255, 0, 255));
	MG_IMAGE->addImage("ruins_wall2", "images/ruins/crypts_corridor_wall_00.bmp", 720, 720, false, RGB(255, 0, 255));
	MG_IMAGE->addImage("ruins_wall3", "images/ruins/crypts_corridor_wall_02.bmp", 720, 720, false, RGB(255, 0, 255));
	MG_IMAGE->addImage("ruins_wall6", "images/ruins/crypts_corridor_wall_03.bmp", 720, 720, false, RGB(255, 0, 255));
	MG_IMAGE->addImage("ruins_wall_basic", "images/ruins/crypts_corridor_wall_06.bmp", 720, 720, false, RGB(255, 0, 255));
	//뚫린 벽
	MG_IMAGE->addImage("ruins_wall1", "images/ruins/transperant/crypts_corridor_wall_01.bmp", 1920, 720, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("ruins_wall4", "images/ruins/transperant/crypts.corridor_wall_04.bmp", 1920, 720, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("ruins_wall5", "images/ruins/transperant/crypts_corridor_wall_05.bmp", 1920, 720, true, RGB(255, 0, 255));

	//방
	MG_IMAGE->addImage("ruins_room1", "images/ruins/crypts_room_wall_empty.bmp", 1920, 720, false, RGB(255, 0, 255));
	MG_IMAGE->addImage("ruins_room2", "images/ruins/crypts_room_wall_library.bmp", 1920, 720, false, RGB(255, 0, 255));
	MG_IMAGE->addImage("ruins_room3", "images/ruins/crypts_room_wall_entrance.bmp", 1920, 720, false, RGB(255, 0, 255));
	MG_IMAGE->addImage("ruins_room4", "images/ruins/crypts_room_wall_drain.bmp", 1920, 720, false, RGB(255, 0, 255));
	MG_IMAGE->addImage("ruins_room5", "images/ruins/crypts_room_wall_barrels.bmp", 1920, 720, false, RGB(255, 0, 255));
	MG_IMAGE->addImage("ruins_room6", "images/ruins/crypts_room_wall_arch.bmp", 1920, 720, false, RGB(255, 0, 255));
	MG_IMAGE->addImage("ruins_room7", "images/ruins/crypts_room_wall_altar.bmp", 1920, 720, false, RGB(255, 0, 255));
	MG_IMAGE->addImage("ruins_room8", "images/ruins/crypts_entrance_room_wall.bmp", 1920, 720, false, RGB(255, 0, 255));
	MG_IMAGE->addImage("ruins_room9", "images/ruins/crypts_room_wall_torture.bmp", 1920, 720, false, RGB(255, 0, 255));

	//기타
	MG_IMAGE->addImage("ruins_endhall", "images/ruins/transperant/crypts_endhall_01.bmp", 720, 720, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("ruins_mid", "images/ruins/transperant/crypts_corridor_mid.bmp", 720, 720, true, RGB(255, 0, 255));

	//제일 앞 배경
	MG_IMAGE->addImage("ruins_bottom", "images/ruins/transperant/crypts_foreground_bottom_01.bmp", 720, 101, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("ruins_top", "images/ruins/transperant/crypts_foreground_top_01.bmp", 720, 330, true, RGB(255, 0, 255));


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
	MG_IMAGE->addFrameImage("bg", "images/임시/임시 배경.bmp", WORLDSIZEX, WORLDSIZEY, 1, 1, true, RGB(255, 0, 255));

	return S_OK;
}