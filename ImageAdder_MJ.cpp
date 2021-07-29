#include "framework.h"
#include "ImageAdder_MJ.h"

HRESULT ImageAdder_MJ::Init()
{
	//ruins-map
	//제일 뒷 배경
	//MG_IMAGE->addImage("ruins_backmost_bg", "images/ruins_bmp/crypts.corridor_bg.bmp", 720, 720, false, RGB(255, 0, 255)); //수정
	
	//통로 벽
	//MG_IMAGE->addImage("ruins_door", "images/ruins_bmp/crypts.corridor_door.basic.bmp", 720, 720, false, RGB(255, 0, 255)); //수정
	MG_IMAGE->addImage("ruins_wall0", "images/ruins_bmp/crypts.corridor_wall.00.bmp", 720, 720, false, RGB(255, 0, 255));
	MG_IMAGE->addImage("ruins_wall2", "images/ruins_bmp/crypts.corridor_wall.02.bmp", 720, 720, false, RGB(255, 0, 255));
	MG_IMAGE->addImage("ruins_wall3", "images/ruins_bmp/crypts.corridor_wall.03.bmp", 720, 720, false, RGB(255, 0, 255));
	MG_IMAGE->addImage("ruins_wall6", "images/ruins_bmp/crypts.corridor_wall.06.bmp", 720, 720, false, RGB(255, 0, 255));
	//뚫린 벽
	MG_IMAGE->addImage("ruins_wall1", "images/ruins_bmp/-/crypts.corridor_wall.00.bmp", 720, 720, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("ruins_wall4", "images/ruins_bmp/-/crypts.corridor_wall.02.bmp", 720, 720, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("ruins_wall5", "images/ruins_bmp/-/crypts.corridor_wall.03.bmp", 720, 720, true, RGB(255, 0, 255));

	//방
	MG_IMAGE->addImage("ruins_room1", "images/ruins_bmp/crypts.entrance_room_wall.bmp", 1920, 720, false, RGB(255, 0, 255));
	MG_IMAGE->addImage("ruins_room2", "images/ruins_bmp/crypts.room_wall.altar.bmp", 1920, 720, false, RGB(255, 0, 255));
	MG_IMAGE->addImage("ruins_room3", "images/ruins_bmp/crypts.room_wall.arch.bmp", 1920, 720, false, RGB(255, 0, 255));
	MG_IMAGE->addImage("ruins_room4", "images/ruins_bmp/crypts.room_wall.barrels.bmp", 1920, 720, false, RGB(255, 0, 255));
	MG_IMAGE->addImage("ruins_room5", "images/ruins_bmp/crypts.room_wall.drain.bmp", 1920, 720, false, RGB(255, 0, 255));
	MG_IMAGE->addImage("ruins_room6", "images/ruins_bmp/crypts.room_wall.empty.bmp", 1920, 720, false, RGB(255, 0, 255));
	MG_IMAGE->addImage("ruins_room7", "images/ruins_bmp/crypts.room_wall.entrance.bmp", 1920, 720, false, RGB(255, 0, 255));
	MG_IMAGE->addImage("ruins_room8", "images/ruins_bmp/crypts.room_wall.library.bmp", 1920, 720, false, RGB(255, 0, 255));
	MG_IMAGE->addImage("ruins_room9", "images/ruins_bmp/crypts.room_wall.torture.bmp", 1920, 720, false, RGB(255, 0, 255));

	//기타
	MG_IMAGE->addImage("ruins_mid", "images/ruins/-/crypts.corridor_mid.bmp", 720, 720, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("ruins_endhall", "images/ruins/-/crypts.endhall.01.bmp", 720, 720, true, RGB(255, 0, 255));

	//제일 앞 배경
	MG_IMAGE->addImage("ruins_bottom", "images/ruins/-/crypts.corridor_mid.bmp", 720, 101, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("ruins_top", "images/ruins/-/crypts.endhall.01.bmp", 720, 330, true, RGB(255, 0, 255));


	return E_NOTIMPL;
}