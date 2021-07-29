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

	MG_IMAGE->addImage("ruins_backmost_bg", "images/crypts_corridor_bg.bmp", 720, 720, true, RGB(255, 0, 255));

	MG_IMAGE->addFrameImage("록맨", "images/록맨.bmp", 960, 200, 10, 2, true, RGB(255, 0, 255));
	MG_IMAGE->addFrameImage(IMAGE::Vestal_Idle, "images/Heroes/Vestal_Idle_Frame.bmp", 2400, 300, 12, 1, true, RGB(255, 0, 255));
	return S_OK;
}

void imageManager::release()
{
	deleteAll();
}

image* imageManager::addImage(string strKey, const int width, const int height)
{
	//추가하려는 키값으로 이미지 존재하는지 확인
	image* img = findImage(strKey);
	//추가하려는 이미지가 이미 있으면 리턴
	if (img)return img;

	img = new image;

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

image* imageManager::addImage(string strKey, const char* fileName, const int width, const int height, bool trans, COLORREF transColor)
{
	//추가하려는 키값으로 이미지 존재하는지 확인
	image* img = findImage(strKey);
	//추가하려는 이미지가 이미 있으면 리턴
	if (img)return img;

	img = new image;

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

image* imageManager::addImage(string strKey, const char* fileName, const float x, const float y, const int const width, const int height, bool trans, COLORREF transColor)
{
	//추가하려는 키값으로 이미지 존재하는지 확인
	image* img = findImage(strKey);
	//추가하려는 이미지가 이미 있으면 리턴
	if (img)return img;

	img = new image;

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

image* imageManager::addFrameImage(string strKey, const char* fileName, const int width, const int height, const int frameX, const int frameY, bool trans, COLORREF transColor)
{
	//추가하려는 키값으로 이미지 존재하는지 확인
	image* img = findImage(strKey);
	//추가하려는 이미지가 이미 있으면 리턴
	if (img)return img;

	img = new image;

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

image* imageManager::addFrameImage(string strKey, const char* fileName, const float x, const float y, const int width, const int height, const int frameX, const int frameY, bool trans, COLORREF transColor)
{
	//추가하려는 키값으로 이미지 존재하는지 확인
	image* img = findImage(strKey);
	//추가하려는 이미지가 이미 있으면 리턴
	if (img)return img;

	img = new image;

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

image* imageManager::findImage(string strKey)
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
	image* img = findImage(strKey);
	if (img) img->render(hdc);
}

void imageManager::render(string strKey, HDC hdc, const int destX, const int destY)
{
	image* img = findImage(strKey);
	if (img) img->render(hdc, destX, destY);
}

void imageManager::render(string strKey, HDC hdc, const int destX, const int destY, const int sourX, const int sourY, const int sourWidth, const int sourHeight)
{
	image* img = findImage(strKey);
	if (img) img->render(hdc, destX, destY, sourX, sourY, sourWidth, sourHeight);
}

void imageManager::frameRender(string strKey, HDC hdc, const int destX, const int destY)
{
	image* img = findImage(strKey);
	if (img) img->frameRender(hdc, destX, destY);
}

void imageManager::frameRender(string strKey, HDC hdc, const int destX, const int destY, const int currentFrameX, const int currentFrameY)
{
	image* img = findImage(strKey);
	if (img) img->frameRender(hdc, destX, destY, currentFrameX, currentFrameY);
}

void imageManager::loopRender(string strKey, HDC hdc, const LPRECT drawArea,int offSetX, int offSetY)
{
	image* img = findImage(strKey);
	if (img) img->loopRender(hdc, drawArea, offSetX, offSetY);
}

void imageManager::loopAlphaRender(string strKey, HDC hdc, const LPRECT drawArea, int offSetX, int offSetY, BYTE alpha)
{
	image* img = findImage(strKey);
	if (img) img->loopAlphaRender(hdc, drawArea, offSetX, offSetY, alpha);
}






//
//
image* imageManager::addImage(IMAGE strKey, const int width, const int height)
{
	//추가하려는 키값으로 이미지 존재하는지 확인
	image* img = findImage(strKey);
	//추가하려는 이미지가 이미 있으면 리턴
	if (img)return img;

	img = new image;

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

image* imageManager::addImage(IMAGE strKey, const char* fileName, const int width, const int height, bool trans, COLORREF transColor)
{
	//추가하려는 키값으로 이미지 존재하는지 확인
	image* img = findImage(strKey);
	//추가하려는 이미지가 이미 있으면 리턴
	if (img)return img;

	img = new image;

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

image* imageManager::addImage(IMAGE strKey, const char* fileName, const float x, const float y, const int const width, const int height, bool trans, COLORREF transColor)
{
	//추가하려는 키값으로 이미지 존재하는지 확인
	image* img = findImage(strKey);
	//추가하려는 이미지가 이미 있으면 리턴
	if (img)return img;

	img = new image;

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

image* imageManager::addFrameImage(IMAGE strKey, const char* fileName, const int width, const int height, const int frameX, const int frameY, bool trans, COLORREF transColor)
{
	//추가하려는 키값으로 이미지 존재하는지 확인
	image* img = findImage(strKey);
	//추가하려는 이미지가 이미 있으면 리턴
	if (img)return img;

	img = new image;

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

image* imageManager::addFrameImage(IMAGE strKey, const char* fileName, const float x, const float y, const int width, const int height, const int frameX, const int frameY, bool trans, COLORREF transColor)
{
	//추가하려는 키값으로 이미지 존재하는지 확인
	image* img = findImage(strKey);
	//추가하려는 이미지가 이미 있으면 리턴
	if (img)return img;

	img = new image;

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

image* imageManager::findImage(IMAGE strKey)
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
	image* img = findImage(strKey);
	if (img) img->render(hdc);
}

void imageManager::render(IMAGE strKey, HDC hdc, const int destX, const int destY)
{
	image* img = findImage(strKey);
	if (img) img->render(hdc, destX, destY);
}

void imageManager::render(IMAGE strKey, HDC hdc, const int destX, const int destY, const int sourX, const int sourY, const int sourWidth, const int sourHeight)
{
	image* img = findImage(strKey);
	if (img) img->render(hdc, destX, destY, sourX, sourY, sourWidth, sourHeight);
}

void imageManager::frameRender(IMAGE strKey, HDC hdc, const int destX, const int destY)
{
	image* img = findImage(strKey);
	if (img) img->frameRender(hdc, destX, destY);
}

void imageManager::frameRender(IMAGE strKey, HDC hdc, const int destX, const int destY, const int currentFrameX, const int currentFrameY)
{
	image* img = findImage(strKey);
	if (img) img->frameRender(hdc, destX, destY, currentFrameX, currentFrameY);
}

void imageManager::loopRender(IMAGE strKey, HDC hdc, const LPRECT drawArea, int offSetX, int offSetY)
{
	image* img = findImage(strKey);
	if (img) img->loopRender(hdc, drawArea, offSetX, offSetY);
}

void imageManager::loopAlphaRender(IMAGE strKey, HDC hdc, const LPRECT drawArea, int offSetX, int offSetY, BYTE alpha)
{
	image* img = findImage(strKey);
	if (img) img->loopAlphaRender(hdc, drawArea, offSetX, offSetY, alpha);
}