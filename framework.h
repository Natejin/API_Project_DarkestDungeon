// header.h: 표준 시스템 포함 파일
// 또는 프로젝트 특정 포함 파일이 들어 있는 포함 파일입니다.
//

#pragma once
#include "targetver.h"
#define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용을 Windows 헤더에서 제외합니다.
// Windows 헤더 파일
#include <windows.h>
// C 런타임 헤더 파일입니다.
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>

//#include <Windows.h>
#include <iostream>
#include <crtdbg.h>
#include <cassert>
#include <string>
#include <functional>
#include <conio.h>
#include <math.h>

//==========================================
//					STL
//==========================================
#include<vector>
#include<map>
#include<queue>
#include<string>
#include<unordered_map>





//==========================================
//				 내가만든 헤더파일
//==========================================

#include "Input.h"
#include "imageManager.h"
#include "timeManager.h"
#include "sceneManager.h"
#include "soundManager.h"
#include "animationManager.h"
#include "effectManager.h"
#include "randomFunction.h"
#include "CCameraManager.h"
#include "CObjectManager.h"
#include "CGameManager.h"
#include "InfomationManager.h"
#include "DB_Item.h"
#include "DB_Skill.h"
#include "DB_UnitInfo.h"
#include "utils.h"
#include "txtData.h"

//struct
#include "Vector2.h"
#include "ImageData.h"
#include "Rect.h"
#include "DungeonData.h"

//Component
#include "CTransform.h"
#include "CAnimator.h"
#include "CCollider.h"
#include "CSpriteRenderer.h"

#include "commonMacroFunction.h"


#include "Enum.h"


//======================================
//##			매니저들			  ##
//======================================
#define MG_INPUT		CInputManager::getSingleton()
#define MG_RND			RandomFunction::getSingleton()
#define MG_IMAGE		imageManager::getSingleton()
#define MG_TIME			timeManager::getSingleton()
#define MG_TXT			txtData::getSingleton()
#define MG_SCENE		SceneManager::getSingleton()
#define MG_SOUND		soundManager::getSingleton()
#define MG_ANIMATION	animationManager::getSingleton()
#define MG_EFFECT		effectManager::getSingleton()
#define MG_GMOBJ		CObjectManager::getSingleton()
#define MG_CAMERA		CCameraManager::getSingleton()
#define MG_GAME			CGameManager::getSingleton()
#define MG_INFO			CInfomationManager::getSingleton()

//======================================
//##			데이터베이스		  ##
//======================================
#define DB_ITEM			CDB_Item::getSingleton()
#define DB_SKILL		CDB_Skill::getSingleton()
#define DB_UNIT			DB_UnitInfo::getSingleton()
#define DB_SKILL		CDB_Skill::getSingleton()

//==========================================
//				 매크로 설정
//==========================================
#define WINNAME			(LPTSTR)(TEXT("지옥으로 떠나는 여행"))
#define WINSTARTX		0
#define WINSTARTY		0
#define WINSIZEX		1920
#define WINSIZEY		1080
#define WORLDSIZEX		4320
#define WORLDSIZEY		720
#define ROOMSIZE		720
#define MAPSIZE			25
#define	WINSTYLE		WS_CAPTION | WS_SYSMENU


//==========================================
//			메인게임 릴리즈에서 사용
//==========================================
#define SAFE_DELETE(p) {if(p) {delete(p);(p) = nullptr;}}


//========================================================
//		전역변수 아이들(인스턴스,윈도우 핸들, 마우스 좌표)
//========================================================

extern HINSTANCE m_hInstance;
extern HWND m_hWnd;
extern Vector2 g_ptMouse;