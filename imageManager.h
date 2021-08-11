#pragma once
#include"singleton.h"
#include"image.h"
#include "Enum.h"

//class image;
//class IMAGE;
class imageManager : public Singleton<imageManager>
{
private:
	//������ ���� �̹��� ���
	typedef map<string, Image*> mapImageList;
	typedef map<string, Image*>::iterator mapImageListIter;

	mapImageList _mImageList;

	typedef map<IMAGE, Image*> mapImage;
	typedef map<IMAGE, Image*>::iterator mapImageIter;

	mapImage m_ImageMap;

public:
	imageManager();
	~imageManager();

	HRESULT init();
	void release();

	//Ű������ �� ��Ʈ�� �ʱ�ȭ
	Image* addImage(string strKey, const int width, const int height);
	Image* addImage(string strKey, const char* fileName, const int width, const int height, bool trans, COLORREF transColor);
	Image* addImage(string strKey, const char* fileName, const float x, const float y, const int const width, const int height, bool trans, COLORREF transColor);

	//Ű������ ������ �̹��� �ʱ�ȭ
	Image* addFrameImage(string strKey, const char* fileName, const int width, const int height, const int frameX, const int frameY, bool trans, COLORREF transColor);
	Image* addFrameImage(string strKey, const char* fileName, const float x, const float y, const int width, const int height, const int frameX, const int frameY, bool trans, COLORREF transColor);

	//�̹����� ã�ƶ�
	Image* findImage(string strKey);
	//�̹��� Ű������ ����
	bool deleteImage(string strKey);

	//�̹��� ��ü����
	bool deleteAll();

	//����
	void render(string strKey, HDC hdc);
	void render(string strKey, HDC hdc, const int destX, const int destY);
	void render(string strKey, HDC hdc, const int destX, const int destY, const int sourX, const int sourY, const int sourWidth, const int sourHeight);
	

	//������
	void frameRender(string strKey, HDC hdc, const int destX, const int destY);
	void frameRender(string strKey, HDC hdc, const int destX, const int destY, const int currentFrameX, const int currentFrameY);

	//����
	void loopRender(string strKey, HDC hdc, const LPRECT drawArea, int offSetX, int offSetY);
	void loopAlphaRender(string strKey, HDC hdc, const LPRECT drawArea, int offSetX, int offSetY, BYTE alpha);

	//��


	//==================================
	//enum�� �Ű������� �޾� ���

	Image* addImage(IMAGE strKey, const int width, const int height);
	Image* addImage(IMAGE strKey, const char* fileName, const int width, const int height, bool trans, COLORREF transColor);
	Image* addImage(IMAGE strKey, const char* fileName, const float x, const float y, const int const width, const int height, bool trans, COLORREF transColor);

	//Ű������ ������ �̹��� �ʱ�ȭ
	Image* addFrameImage(IMAGE strKey, const char* fileName, const int width, const int height, const int frameX, const int frameY, bool trans, COLORREF transColor);
	Image* addFrameImage(IMAGE strKey, const char* fileName, const float x, const float y, const int width, const int height, const int frameX, const int frameY, bool trans, COLORREF transColor);

	//�̹����� ã�ƶ�
	Image* findImage(IMAGE strKey);
	//�̹��� Ű������ ����
	bool deleteImage(IMAGE strKey);

	//����
	void render(IMAGE strKey, HDC hdc);
	void render(IMAGE strKey, HDC hdc, const int destX, const int destY);
	void render(IMAGE strKey, HDC hdc, const int destX, const int destY, const int sourX, const int sourY, const int sourWidth, const int sourHeight);

	//������
	void frameRender(IMAGE strKey, HDC hdc, const int destX, const int destY);
	void frameRender(IMAGE strKey, HDC hdc, const int destX, const int destY, const int currentFrameX, const int currentFrameY);

	//����
	void loopRender(IMAGE strKey, HDC hdc, const LPRECT drawArea, int offSetX, int offSetY);
	void loopAlphaRender(IMAGE strKey, HDC hdc, const LPRECT drawArea, int offSetX, int offSetY, BYTE alpha);

};