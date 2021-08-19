#include "framework.h"
#include "image.h"
#include "CTransform.h"
#include "animation.h"
//알파블렌드를 사용하기 위해
#pragma comment(lib,"msimg32.lib")
Image::Image() : _imageInfo(NULL),
				 _fileName(NULL),
				 _isTrans(false),
				 _transColor(RGB(0, 0, 0))
{				 
}				
Image::~Image(){}

HRESULT Image::init(const int width, const int height)
{

	//이미지 정보가 있으면 해제해라
	if (_imageInfo != NULL)release();
	//DC가져오기(현재 윈도우에 대한 화면 DC를 임시로 가져옴)
	//CreateCompatibleDC: 비트맵을 출력하기 위해 메모리 DC를 만들어준다.
	// CreateCompatibleBitmap: 원본DC와 호환되는 비트맵 생성

	HDC hdc = GetDC(m_hWnd);

	//이미지 정보 생성
	_imageInfo = new IMAGE_INFO;
	_imageInfo->loadType = static_cast<BYTE>(IMAGE_LOAD_KIND::LOAD_EMPTY);
	_imageInfo->resID = 0;
	_imageInfo->hMemDC = CreateCompatibleDC(hdc);
	_imageInfo->hBit = (HBITMAP)CreateCompatibleBitmap(hdc, width, height);
	_imageInfo->hOBit = (HBITMAP)SelectObject(_imageInfo->hMemDC, _imageInfo->hBit);
	_imageInfo->width = width;
	_imageInfo->height = height;

	//파일이름
	_fileName = NULL;


	//알파 블렌드 옵션
	_blendFunc.BlendFlags = 0;
	_blendFunc.AlphaFormat = 0;
	_blendFunc.BlendOp = AC_SRC_OVER;//블렌딩 연산자


	//알파 블렌드 사용하기 위한 이미지 초기화
	_blendImage = new IMAGE_INFO;
	_blendImage->loadType = static_cast<BYTE>(IMAGE_LOAD_KIND::LOAD_EMPTY);
	_blendImage->resID = 0;
	_blendImage->hMemDC = CreateCompatibleDC(hdc);
	_blendImage->hBit = (HBITMAP)CreateCompatibleBitmap(hdc, _imageInfo->width, _imageInfo->height);
	_blendImage->hOBit = (HBITMAP)SelectObject(_blendImage->hMemDC, _blendImage->hBit);
	_blendImage->width = WINSIZEX;
	_blendImage->height = WINSIZEY;

	//투명키 셋팅
	_isTrans = false;
	_transColor = RGB(0, 0, 0);

	//리소스를 얻어오는데 실패하면
	if (_imageInfo->hBit == NULL)
	{
		release();
		return E_FAIL;
	}

	ReleaseDC(m_hWnd, hdc);

	return S_OK;
}

HRESULT Image::init(const char* fileName, const int width, const int height, bool isTrans, COLORREF transColor)
{

	if (fileName == NULL)return E_FAIL;
	if (_imageInfo != NULL)release();


	HDC hdc = GetDC(m_hWnd);

	_imageInfo = new IMAGE_INFO;
	_imageInfo->loadType = static_cast<BYTE>(IMAGE_LOAD_KIND::LOAD_FILE);
	_imageInfo->resID = 0;
	_imageInfo->hMemDC = CreateCompatibleDC(hdc);
	_imageInfo->hBit = (HBITMAP)LoadImage(m_hInstance,
									      fileName,
										  IMAGE_BITMAP,
										  width, height, 
										  LR_LOADFROMFILE);
	_imageInfo->hOBit = (HBITMAP)SelectObject(_imageInfo->hMemDC, _imageInfo->hBit);
	_imageInfo->width = width;
	_imageInfo->height = height;



	//알파 블렌드 옵션
	_blendFunc.BlendFlags = 0;
	_blendFunc.AlphaFormat = 0;
	_blendFunc.BlendOp = AC_SRC_OVER;//블렌딩 연산자


	//알파 블렌드 사용하기 위한 이미지 초기화
	_blendImage = new IMAGE_INFO;
	_blendImage->loadType = static_cast<BYTE>(IMAGE_LOAD_KIND::LOAD_EMPTY);
	_blendImage->resID = 0;
	_blendImage->hMemDC = CreateCompatibleDC(hdc);
	_blendImage->hBit = (HBITMAP)CreateCompatibleBitmap(hdc, _imageInfo->width, _imageInfo->height);
	_blendImage->hOBit = (HBITMAP)SelectObject(_blendImage->hMemDC, _blendImage->hBit);
	_blendImage->width = WINSIZEX;
	_blendImage->height = WINSIZEY;



	//파일이름
	int len = _tcslen(fileName);
	_fileName = new char[len + 1];
	strcpy_s(_fileName, len + 1, fileName);

	_isTrans = isTrans;
	_transColor = transColor;

	//리소스를 얻어오는데 실패하면
	if (_imageInfo->hBit == NULL)
	{
		release();
		return E_FAIL;
	}

	ReleaseDC(m_hWnd, hdc);
	


	return S_OK;
}

HRESULT Image::init(const char* fileName, const float x, const float y, const int width, const int height, bool isTrans, COLORREF transColor)
{
	if (fileName == NULL) return E_FAIL;

	//이미지 정보가 널이 아니라면(이미지가 들어있다면) 해제해라
	if (_imageInfo != NULL) release();

	HDC hdc = GetDC(m_hWnd);

	_imageInfo = new IMAGE_INFO;
	_imageInfo->loadType = static_cast<BYTE>(IMAGE_LOAD_KIND::LOAD_FILE);
	_imageInfo->resID = 0;
	_imageInfo->resID = 0;
	_imageInfo->hMemDC = CreateCompatibleDC(hdc);	//빈 DC영역을 생성
	_imageInfo->hBit = (HBITMAP)LoadImage(m_hInstance, fileName, IMAGE_BITMAP, width, height, LR_LOADFROMFILE);
	_imageInfo->hOBit = (HBITMAP)SelectObject(_imageInfo->hMemDC, _imageInfo->hBit);
	_imageInfo->x = x;
	_imageInfo->y = y;
	_imageInfo->width = width;
	_imageInfo->height = height;

	int len = strlen(fileName);

	_fileName = new CHAR[len + 1];
	strcpy_s(_fileName, len + 1, fileName);

	_isTrans = isTrans;
	_transColor = transColor;

	//알파 블렌드 옵션

	_blendFunc.BlendFlags = 0;
	_blendFunc.AlphaFormat = 0;	//32비트인경우 AC_SRC_APLHA를 지정하고 그 외에는 0으로 지정함(그렇지 않으면 알파블렌딩 함수 사용 불가)
	_blendFunc.BlendOp = AC_SRC_OVER;	//블렌딩 연산자


										//알파블렌드 사용하기 위한 이미지 초기화
	_blendImage = new IMAGE_INFO;
	_blendImage->loadType = static_cast<BYTE>(IMAGE_LOAD_KIND::LOAD_EMPTY);
	_blendImage->resID = 0;
	_blendImage->hMemDC = CreateCompatibleDC(hdc);
	_blendImage->hBit = (HBITMAP)CreateCompatibleBitmap(hdc, _imageInfo->width, _imageInfo->height);
	_blendImage->hOBit = (HBITMAP)SelectObject(_blendImage->hMemDC, _blendImage->hBit);
	_blendImage->width = WINSIZEX;
	_blendImage->height = WINSIZEY;


	if (_imageInfo->hBit == NULL)
	{
		release();

		return E_FAIL;
	}

	ReleaseDC(m_hWnd, hdc);
}

HRESULT Image::init(const char* fileName, const int width, const int height, const int frameX, const int frameY, bool isTrans, COLORREF transColor)
{
	if (fileName == NULL)return E_FAIL;
	if (_imageInfo != NULL)release();


	HDC hdc = GetDC(m_hWnd);

	_imageInfo = new IMAGE_INFO;
	_imageInfo->loadType = static_cast<BYTE>(IMAGE_LOAD_KIND::LOAD_FILE);
	_imageInfo->resID = 0;
	_imageInfo->hMemDC = CreateCompatibleDC(hdc);
	_imageInfo->hBit = (HBITMAP)LoadImage(m_hInstance,
		fileName,
		IMAGE_BITMAP,
		width, height,
		LR_LOADFROMFILE);
	_imageInfo->hOBit = (HBITMAP)SelectObject(_imageInfo->hMemDC, _imageInfo->hBit);
	_imageInfo->width = width;
	_imageInfo->height = height;
	_imageInfo->maxFrameX = frameX - 1;
	_imageInfo->maxFrameY = frameY - 1;
	_imageInfo->frameWidth = width/frameX;
	_imageInfo->frameHeight = height/frameY;


	//알파 블렌드 옵션
	_blendFunc.BlendFlags = 0;
	_blendFunc.AlphaFormat = 0;
	_blendFunc.BlendOp = AC_SRC_OVER;//블렌딩 연산자


	//알파 블렌드 사용하기 위한 이미지 초기화
	_blendImage = new IMAGE_INFO;
	_blendImage->loadType = static_cast<BYTE>(IMAGE_LOAD_KIND::LOAD_EMPTY);
	_blendImage->resID = 0;
	_blendImage->hMemDC = CreateCompatibleDC(hdc);
	_blendImage->hBit = (HBITMAP)CreateCompatibleBitmap(hdc, _imageInfo->width, _imageInfo->height);
	_blendImage->hOBit = (HBITMAP)SelectObject(_blendImage->hMemDC, _blendImage->hBit);
	_blendImage->width = WINSIZEX;
	_blendImage->height = WINSIZEY;



	//파일이름
	int len = _tcslen(fileName);
	_fileName = new char[len + 1];
	strcpy_s(_fileName, len + 1, fileName);

	_isTrans = isTrans;
	_transColor = transColor;

	//리소스를 얻어오는데 실패하면
	if (_imageInfo->hBit == NULL)
	{
		release();
		return E_FAIL;
	}

	ReleaseDC(m_hWnd, hdc);
	return S_OK;
}

HRESULT Image::init(const char* fileName, const int x, const int y, const int width, const int height, const int frameX, const int frameY, bool isTrans, COLORREF transColor)
{

	if (fileName == NULL)return E_FAIL;
	if (_imageInfo != NULL)release();


	HDC hdc = GetDC(m_hWnd);

	_imageInfo = new IMAGE_INFO;
	_imageInfo->loadType = static_cast<BYTE>(IMAGE_LOAD_KIND::LOAD_FILE);
	_imageInfo->resID = 0;
	_imageInfo->hMemDC = CreateCompatibleDC(hdc);
	_imageInfo->hBit = (HBITMAP)LoadImage(m_hInstance,
		fileName,
		IMAGE_BITMAP,
		width, height,
		LR_LOADFROMFILE);
	_imageInfo->hOBit = (HBITMAP)SelectObject(_imageInfo->hMemDC, _imageInfo->hBit);

	_imageInfo->x = x;
	_imageInfo->y = y;
	_imageInfo->width = width;
	_imageInfo->height = height;
	_imageInfo->maxFrameX = frameX - 1;
	_imageInfo->maxFrameY = frameY - 1;
	_imageInfo->frameWidth = width / frameX;
	_imageInfo->frameHeight = height / frameY;

	//파일이름
	int len = _tcslen(fileName);
	_fileName = new char[len + 1];
	strcpy_s(_fileName, len + 1, fileName);

	_isTrans = isTrans;
	_transColor = transColor;

	//리소스를 얻어오는데 실패하면
	if (_imageInfo->hBit == NULL)
	{
		release();
		return E_FAIL;
	}

	ReleaseDC(m_hWnd, hdc);
	return S_OK;
}

HRESULT Image::initForRotate()
{
	HDC hdc = GetDC(m_hWnd);

	int size;
	(_imageInfo->width > _imageInfo->height ? size = _imageInfo->width : size = _imageInfo->height);
	_rotateImage = new IMAGE_INFO;
	_imageInfo->loadType = static_cast<BYTE>(IMAGE_LOAD_KIND::LOAD_FILE);
	_imageInfo->resID = 0;
	_rotateImage->hMemDC = CreateCompatibleDC(hdc);
	_rotateImage->hBit = (HBITMAP)CreateCompatibleBitmap(hdc, size, size);
	_rotateImage->hOBit = (HBITMAP)SelectObject(_rotateImage->hMemDC, _rotateImage->hBit);
	_rotateImage->width = size;
	_rotateImage->height = size;
	_rotateImage->frameWidth = _imageInfo->frameWidth;
	_rotateImage->frameHeight = _imageInfo->frameHeight;

	ReleaseDC(m_hWnd, hdc);
	return S_OK;
}

void Image::setTransColor(bool isTrans, COLORREF transColor)
{
	_isTrans = isTrans;
	_transColor = transColor;
}

void Image::release()
{
	if (_imageInfo)
	{
		SelectObject(_imageInfo->hMemDC, _imageInfo->hBit);
		DeleteObject(_imageInfo->hBit);
		DeleteDC(_imageInfo->hMemDC);

		SAFE_DELETE(_imageInfo);
		SAFE_DELETE(_fileName);

		_isTrans = false;
		_transColor = RGB(0, 0, 0);

	}
}

void Image::render(HDC hdc)
{
	if (_isTrans)
	{
		//비트맵을 불러올때 특정 색상을 제외하고 복사해주는 함수
		GdiTransparentBlt(
			hdc,						//복삳될 장소의 DC
			0,							//복사될 좌표의 시작점X
			0,							//복사될 좌표의 시작점Y
			_imageInfo->width,			//복사될 이미지 가로크기
			_imageInfo->height,			//복사될 이미지 세로크기
			_imageInfo->hMemDC,			//복사될 대상DC
			0,							//복사시작 지점 X
			0,							//복사시작 지점 Y
			_imageInfo->width,			//복사영역 가로크기
			_imageInfo->height,			//복사영역 세로크기
			_transColor);
	}
	else {
		//BitBlt : DC영역끼리 고속복사
		BitBlt(hdc, 0, 0, _imageInfo->width, _imageInfo->height,
			_imageInfo->hMemDC, 0, 0, SRCCOPY);
	}
}

void Image::render(HDC hdc, const int destX, const int destY)
{
	if (_isTrans)
	{
		//비트맵을 불러올때 특정 색상을 제외하고 복사해주는 함수
		GdiTransparentBlt(
			hdc,						//복삳될 장소의 DC
			destX,							//복사될 좌표의 시작점X
			destY,							//복사될 좌표의 시작점Y
			_imageInfo->width,			//복사될 이미지 가로크기
			_imageInfo->height,			//복사될 이미지 세로크기
			_imageInfo->hMemDC,			//복사될 대상DC
			0,							//복사시작 지점 X
			0,							//복사시작 지점 Y
			_imageInfo->width,			//복사영역 가로크기
			_imageInfo->height,			//복사영역 세로크기
			_transColor);
	}
	else {
		//BitBlt : DC영역끼리 고속복사
		BitBlt(hdc, destX, destY, _imageInfo->width, _imageInfo->height,
			_imageInfo->hMemDC, 0, 0, SRCCOPY);
	}

}

void Image::render(HDC hdc, const CTransform* transform)
{
	Vector2 pos = transform->m_pos - transform->m_scale * transform->m_pivot - MG_CAMERA->GetPos();
	if (_isTrans)
	{
		//비트맵을 불러올때 특정 색상을 제외하고 복사해주는 함수
		GdiTransparentBlt(
			hdc,						//복삳될 장소의 DC
			pos.x,						//복사될 좌표의 시작점X
			pos.y,						//복사될 좌표의 시작점Y
			_imageInfo->width,			//복사될 이미지 가로크기
			_imageInfo->height,			//복사될 이미지 세로크기
			_imageInfo->hMemDC,			//복사될 대상DC
			0,							//복사시작 지점 X
			0,							//복사시작 지점 Y
			_imageInfo->width,			//복사영역 가로크기
			_imageInfo->height,			//복사영역 세로크기
			_transColor);
	}
	else {
		//BitBlt : DC영역끼리 고속복사
		BitBlt(hdc, 
			pos.x, 
			pos.y, _imageInfo->width, _imageInfo->height,
			_imageInfo->hMemDC, 0, 0, SRCCOPY);
	}
}

void Image::render(HDC hdc, const CTransform* transform, Vector2 _imageScale)
{
	Vector2 pos = transform->m_pos - _imageScale * transform->m_pivot * transform->m_scale - MG_CAMERA->GetPos();
	if (_isTrans)
	{
		//비트맵을 불러올때 특정 색상을 제외하고 복사해주는 함수
		GdiTransparentBlt(
			hdc,						//복삳될 장소의 DC
			pos.x,						//복사될 좌표의 시작점X
			pos.y,						//복사될 좌표의 시작점Y
			_imageInfo->width * transform->m_scale.x,			//복사될 이미지 가로크기
			_imageInfo->height * transform->m_scale.y,			//복사될 이미지 세로크기
			_imageInfo->hMemDC,			//복사될 대상DC
			0,							//복사시작 지점 X
			0,							//복사시작 지점 Y
			_imageInfo->width,			//복사영역 가로크기
			_imageInfo->height,			//복사영역 세로크기
			_transColor);
	}
	else {
		//BitBlt : DC영역끼리 고속복사
		BitBlt(hdc,
			pos.x,
			pos.y, _imageInfo->width, _imageInfo->height,
			_imageInfo->hMemDC, 0, 0, SRCCOPY);
	}
}

void Image::render(HDC hdc, const CTransform* transform, Vector2 _imageScale, Vector2 customPos)
{

	Vector2 pos = transform->m_pos + customPos - _imageScale * transform->m_pivot * transform->m_scale - MG_CAMERA->GetPos();
	if (_isTrans)
	{
		//비트맵을 불러올때 특정 색상을 제외하고 복사해주는 함수
		GdiTransparentBlt(
			hdc,						//복삳될 장소의 DC
			pos.x,						//복사될 좌표의 시작점X
			pos.y,						//복사될 좌표의 시작점Y
			_imageInfo->width  * transform->m_scale.x,			//복사될 이미지 가로크기
			_imageInfo->height * transform->m_scale.y,			//복사될 이미지 세로크기
			_imageInfo->hMemDC,			//복사될 대상DC
			0,							//복사시작 지점 X
			0,							//복사시작 지점 Y
			_imageInfo->width,			//복사영역 가로크기
			_imageInfo->height,			//복사영역 세로크기
			_transColor);
	}
	else {
		//BitBlt : DC영역끼리 고속복사
		BitBlt(hdc,
			pos.x,
			pos.y, _imageInfo->width, _imageInfo->height,
			_imageInfo->hMemDC, 0, 0, SRCCOPY);
	}
}

void Image::render(HDC hdc, const CTransform* transform, Vector2 _imageScale, Vector2 customPos, Vector2 customSize)
{
	Vector2 pos = transform->m_pos + customPos - _imageScale * transform->m_pivot * transform->m_scale * customSize - MG_CAMERA->GetPos();
	if (_isTrans)
	{
		//비트맵을 불러올때 특정 색상을 제외하고 복사해주는 함수
		GdiTransparentBlt(
			hdc,						//복삳될 장소의 DC
			pos.x,						//복사될 좌표의 시작점X
			pos.y,						//복사될 좌표의 시작점Y
			_imageInfo->width * customSize.x,			//복사될 이미지 가로크기
			_imageInfo->height * customSize.y,			//복사될 이미지 세로크기
			_imageInfo->hMemDC,			//복사될 대상DC
			0,							//복사시작 지점 X
			0,							//복사시작 지점 Y
			_imageInfo->width,			//복사영역 가로크기
			_imageInfo->height,			//복사영역 세로크기
			_transColor);
	}
	else {
		//BitBlt : DC영역끼리 고속복사
		BitBlt(hdc,
			pos.x,
			pos.y, _imageInfo->width, _imageInfo->height,
			_imageInfo->hMemDC, 0, 0, SRCCOPY);
	}
}

void Image::AlphaRender(HDC hdc, const CTransform* transform, BYTE alpha)
{
	Vector2 _imageScale = Vector2(_imageInfo->width, _imageInfo->height);
	Vector2 pos = transform->m_pos - _imageScale * transform->m_pivot * transform->m_scale - MG_CAMERA->GetPos();
	_blendFunc.SourceConstantAlpha = alpha;

	if (_isTrans)
	{
		BitBlt(_blendImage->hMemDC, 
			0, 
			0, 
			_imageInfo->width, 
			_imageInfo->height,
			hdc, 
			pos.x,
			pos.y,
			SRCCOPY);

		GdiTransparentBlt(_blendImage->hMemDC, 0, 0, _imageInfo->width, _imageInfo->height,
			_imageInfo->hMemDC, 0, 0, _imageInfo->width, _imageInfo->height, _transColor);

		AlphaBlend(hdc, 
			pos.x,
			pos.y,
			_imageInfo->width, _imageInfo->height,
			_blendImage->hMemDC, 0, 0, _imageInfo->width, _imageInfo->height, _blendFunc);
	}
	else
	{
		AlphaBlend(hdc, 
			pos.x,
			pos.y,
			_imageInfo->width, _imageInfo->height,
			_imageInfo->hMemDC, 0, 0, _imageInfo->width, _imageInfo->height, _blendFunc);

	}
}

void Image::AlphaRenderUI(HDC hdc, const CTransform* transform, BYTE alpha)
{
	Vector2 _imageScale = Vector2(_imageInfo->width, _imageInfo->height);
	Vector2 pos = transform->m_pos - _imageScale * transform->m_pivot * transform->m_scale;
	_blendFunc.SourceConstantAlpha = alpha;

	if (_isTrans)
	{
		BitBlt(_blendImage->hMemDC,
			0,
			0,
			_imageInfo->width,
			_imageInfo->height,
			hdc,
			pos.x,
			pos.y,
			SRCCOPY);

		GdiTransparentBlt(_blendImage->hMemDC, 0, 0, _imageInfo->width, _imageInfo->height,
			_imageInfo->hMemDC, 0, 0, _imageInfo->width, _imageInfo->height, _transColor);

		AlphaBlend(hdc,
			pos.x,
			pos.y,
			_imageInfo->width, _imageInfo->height,
			_blendImage->hMemDC, 0, 0, _imageInfo->width, _imageInfo->height, _blendFunc);
	}
	else
	{
		AlphaBlend(hdc,
			pos.x,
			pos.y,
			_imageInfo->width, _imageInfo->height,
			_imageInfo->hMemDC, 0, 0, _imageInfo->width, _imageInfo->height, _blendFunc);

	}
}


void Image::renderUI(HDC hdc, const CTransform* transform)
{
	Vector2 _imageScale = Vector2(_imageInfo->width, _imageInfo->height);
	Vector2 pos = transform->m_pos - _imageScale * transform->m_pivot * transform->m_scale;
	if (_isTrans)
	{
		//비트맵을 불러올때 특정 색상을 제외하고 복사해주는 함수
		GdiTransparentBlt(
			hdc,						//복삳될 장소의 DC
			pos.x,							//복사될 좌표의 시작점X
			pos.y,							//복사될 좌표의 시작점Y
			_imageInfo->width * transform->m_scale.x,			//복사될 이미지 가로크기
			_imageInfo->height * transform->m_scale.y,			//복사될 이미지 세로크기
			_imageInfo->hMemDC,			//복사될 대상DC
			0,							//복사시작 지점 X
			0,							//복사시작 지점 Y
			_imageInfo->width,			//복사영역 가로크기
			_imageInfo->height,			//복사영역 세로크기
			_transColor);
	}
	else {
		//BitBlt : DC영역끼리 고속복사
		BitBlt(hdc,
			pos.x,
			pos.y, _imageInfo->width, _imageInfo->height,
			_imageInfo->hMemDC, 0, 0, SRCCOPY);
	}
}

void Image::renderUI(HDC hdc, const CTransform* transform, Vector2 customPos)
{
	Vector2 _imageScale = Vector2(_imageInfo->width, _imageInfo->height);
	Vector2 pos = transform->m_pos + customPos - _imageScale * transform->m_pivot * transform->m_scale;
	if (_isTrans)
	{
		//비트맵을 불러올때 특정 색상을 제외하고 복사해주는 함수
		GdiTransparentBlt(
			hdc,						//복삳될 장소의 DC
			pos.x,							//복사될 좌표의 시작점X
			pos.y,							//복사될 좌표의 시작점Y
			_imageInfo->width * transform->m_scale.x,			//복사될 이미지 가로크기
			_imageInfo->height * transform->m_scale.y,			//복사될 이미지 세로크기
			_imageInfo->hMemDC,			//복사될 대상DC
			0,							//복사시작 지점 X
			0,							//복사시작 지점 Y
			_imageInfo->width,			//복사영역 가로크기
			_imageInfo->height,			//복사영역 세로크기
			_transColor);
	}
	else {
		//BitBlt : DC영역끼리 고속복사
		BitBlt(hdc,
			pos.x,
			pos.y, _imageInfo->width, _imageInfo->height,
			_imageInfo->hMemDC, 0, 0, SRCCOPY);
	}
}

void Image::renderUI(HDC hdc, const CTransform* transform, Vector2 customPos, Vector2 customSize)
{
	Vector2 _imageScale = Vector2(_imageInfo->width, _imageInfo->height);
	Vector2 pos = transform->m_pos + customPos - _imageScale * transform->m_pivot * transform->m_scale;
	if (_isTrans)
	{
		//비트맵을 불러올때 특정 색상을 제외하고 복사해주는 함수
		GdiTransparentBlt(
			hdc,						//복삳될 장소의 DC
			pos.x,							//복사될 좌표의 시작점X
			pos.y,							//복사될 좌표의 시작점Y
			_imageInfo->width * customSize.x,			//복사될 이미지 가로크기
			_imageInfo->height * customSize.y,			//복사될 이미지 세로크기
			_imageInfo->hMemDC,			//복사될 대상DC
			0,							//복사시작 지점 X
			0,							//복사시작 지점 Y
			_imageInfo->width,			//복사영역 가로크기
			_imageInfo->height,			//복사영역 세로크기
			_transColor);
	}
	else {
		//BitBlt : DC영역끼리 고속복사
		BitBlt(hdc,
			pos.x,
			pos.y, _imageInfo->width, _imageInfo->height,
			_imageInfo->hMemDC, 0, 0, SRCCOPY);
	}
}

void Image::mapRender(HDC hdc, Vector2 pos)
{
	if (_isTrans)
	{
		//비트맵을 불러올때 특정 색상을 제외하고 복사해주는 함수
		GdiTransparentBlt(
			hdc,                        //복삳될 장소의 DC
			pos.x,                            //복사될 좌표의 시작점X
			pos.y,                            //복사될 좌표의 시작점Y
			_imageInfo->width,            //복사될 이미지 가로크기
			_imageInfo->height,            //복사될 이미지 세로크기
			_imageInfo->hMemDC,            //복사될 대상DC
			0,                            //복사시작 지점 X
			0,                            //복사시작 지점 Y
			_imageInfo->width,            //복사영역 가로크기
			_imageInfo->height,            //복사영역 세로크기
			_transColor);
	}
	else {
		//이미지의 크기를 조절하여 화면에 출력해주는 함수
		SetStretchBltMode(hdc, COLORONCOLOR);
		StretchBlt(hdc, pos.x, pos.y, _imageInfo->width / 10, _imageInfo->height / 10,
			_imageInfo->hMemDC, 0, 0, _imageInfo->width, _imageInfo->height, SRCCOPY);
	}
}

void Image::render(HDC hdc, const int destX, const int destY, const int sourX, const int sourY, const int sourWidth, const int sourheight)
{
	if (_isTrans)
	{
		//비트맵을 불러올때 특정 색상을 제외하고 복사해주는 함수
		GdiTransparentBlt(
			hdc,						//복삳될 장소의 DC
			destX,							//복사될 좌표의 시작점X
			destY,							//복사될 좌표의 시작점Y
			sourWidth,					//복사될 이미지 가로크기
			sourheight,			//복사될 이미지 세로크기
			_imageInfo->hMemDC,			//복사될 대상DC
			sourX,							//복사시작 지점 X
			sourY,							//복사시작 지점 Y
			sourWidth,			//복사영역 가로크기
			sourheight,			//복사영역 세로크기
			_transColor);
	}
	else {
		//BitBlt : DC영역끼리 고속복사
		BitBlt(hdc, destX, destY, sourWidth, sourheight,
			_imageInfo->hMemDC, sourX, sourY, SRCCOPY);
	}
}

void Image::frameRender(HDC hdc, const int destX, const int destY)
{
	

	if (_isTrans)
	{
		//비트맵을 불러올때 특정 색상을 제외하고 복사해주는 함수
		GdiTransparentBlt(
			hdc,													//복삳될 장소의 DC
			destX,													//복사될 좌표의 시작점X
			destY,													//복사될 좌표의 시작점Y
			_imageInfo->frameWidth,									//복사될 이미지 가로크기
			_imageInfo->frameHeight,								//복사될 이미지 세로크기
			_imageInfo->hMemDC,										//복사될 대상DC
			_imageInfo->currentFrameX* _imageInfo->frameWidth,		//복사시작 지점 X
			_imageInfo->currentFrameY * _imageInfo->frameHeight,	//복사시작 지점 Y
			_imageInfo->frameWidth,									//복사영역 가로크기
			_imageInfo->frameHeight,								//복사영역 세로크기
			_transColor);
	}
	else {
		//BitBlt : DC영역끼리 고속복사
		BitBlt(hdc, destX, destY, _imageInfo->frameWidth, _imageInfo->frameHeight,
			_imageInfo->hMemDC, 
			_imageInfo->currentFrameX * _imageInfo->frameWidth, 
			_imageInfo->currentFrameY * _imageInfo->frameHeight, SRCCOPY);
	}
}

void Image::frameRender(HDC hdc, const CTransform* transform)
{
	Vector2 pos = transform->m_pos - transform->m_pivot * transform->m_scale - MG_CAMERA->GetPos();
	if (_isTrans)
	{
		//비트맵을 불러올때 특정 색상을 제외하고 복사해주는 함수
		GdiTransparentBlt(
			hdc,													//복삳될 장소의 DC
			pos.x,													//복사될 좌표의 시작점X
			pos.y,													//복사될 좌표의 시작점Y
			_imageInfo->frameWidth,									//복사될 이미지 가로크기
			_imageInfo->frameHeight,								//복사될 이미지 세로크기
			_imageInfo->hMemDC,										//복사될 대상DC
			_imageInfo->currentFrameX * _imageInfo->frameWidth,		//복사시작 지점 X
			_imageInfo->currentFrameY * _imageInfo->frameHeight,	//복사시작 지점 Y
			_imageInfo->frameWidth,									//복사영역 가로크기
			_imageInfo->frameHeight,								//복사영역 세로크기
			_transColor);
	}
	else {
		//BitBlt : DC영역끼리 고속복사
		BitBlt(hdc, 
			pos.x, 
			pos.y, _imageInfo->frameWidth, _imageInfo->frameHeight,
			_imageInfo->hMemDC,
			_imageInfo->currentFrameX * _imageInfo->frameWidth,
			_imageInfo->currentFrameY * _imageInfo->frameHeight, SRCCOPY);
	}
}

void Image::frameRender(HDC hdc, const CTransform* transform, const int destX, const int destY)
{
	Vector2 pos = transform->m_pos - transform->m_pivot * transform->m_scale - MG_CAMERA->GetPos();
	if (_isTrans)
	{
		//비트맵을 불러올때 특정 색상을 제외하고 복사해주는 함수
		GdiTransparentBlt(
			hdc,													//복삳될 장소의 DC
			pos.x,													//복사될 좌표의 시작점X
			pos.y,													//복사될 좌표의 시작점Y
			_imageInfo->frameWidth,									//복사될 이미지 가로크기
			_imageInfo->frameHeight,								//복사될 이미지 세로크기
			_imageInfo->hMemDC,										//복사될 대상DC
			destX * _imageInfo->frameWidth,							//복사시작 지점 X
			destY * _imageInfo->frameHeight,						//복사시작 지점 Y
			_imageInfo->frameWidth,									//복사영역 가로크기
			_imageInfo->frameHeight,								//복사영역 세로크기
			_transColor);
	}
	else {
		//BitBlt : DC영역끼리 고속복사
		BitBlt(hdc,
			pos.x,
			pos.y, _imageInfo->frameWidth, _imageInfo->frameHeight,
			_imageInfo->hMemDC,
			destX * _imageInfo->frameWidth,
			destY * _imageInfo->frameHeight, SRCCOPY);
	}
}

void Image::frameRender(HDC hdc, const CTransform* transform, Vector2 scale, const int destX, const int destY)
{
	Vector2 pos = transform->m_pos - scale * transform->m_pivot * transform->m_scale - MG_CAMERA->GetPos();
	if (_isTrans)
	{
		//비트맵을 불러올때 특정 색상을 제외하고 복사해주는 함수
		GdiTransparentBlt(
			hdc,													//복삳될 장소의 DC
			pos.x,													//복사될 좌표의 시작점X
			pos.y,													//복사될 좌표의 시작점Y
			_imageInfo->frameWidth * transform->m_scale.x,									//복사될 이미지 가로크기
			_imageInfo->frameHeight * transform->m_scale.y,								//복사될 이미지 세로크기
			_imageInfo->hMemDC,										//복사될 대상DC
			destX * _imageInfo->frameWidth,							//복사시작 지점 X
			destY * _imageInfo->frameHeight,						//복사시작 지점 Y
			_imageInfo->frameWidth,									//복사영역 가로크기
			_imageInfo->frameHeight,								//복사영역 세로크기
			_transColor);
	}
	else {
		//BitBlt : DC영역끼리 고속복사
		BitBlt(hdc,
			pos.x,
			pos.y, _imageInfo->frameWidth, _imageInfo->frameHeight,
			_imageInfo->hMemDC,
			destX * _imageInfo->frameWidth,
			destY * _imageInfo->frameHeight, SRCCOPY);
	}
}

void Image::frameRender(HDC hdc, const CTransform* transform, Vector2 scale, Vector2 customPos, const int destX, const int destY)
{
	Vector2 pos = transform->m_pos + customPos - scale * transform->m_pivot * transform->m_scale - MG_CAMERA->GetPos();
	if (_isTrans)
	{
		//비트맵을 불러올때 특정 색상을 제외하고 복사해주는 함수
		GdiTransparentBlt(
			hdc,													//복삳될 장소의 DC
			pos.x,													//복사될 좌표의 시작점X
			pos.y,													//복사될 좌표의 시작점Y
			_imageInfo->frameWidth * transform->m_scale.x,									//복사될 이미지 가로크기
			_imageInfo->frameHeight * transform->m_scale.y,								//복사될 이미지 세로크기
			_imageInfo->hMemDC,										//복사될 대상DC
			destX * _imageInfo->frameWidth,							//복사시작 지점 X
			destY * _imageInfo->frameHeight,						//복사시작 지점 Y
			_imageInfo->frameWidth,									//복사영역 가로크기
			_imageInfo->frameHeight,								//복사영역 세로크기
			_transColor);
	}
	else {
		//BitBlt : DC영역끼리 고속복사
		BitBlt(hdc,
			pos.x,
			pos.y, _imageInfo->frameWidth, _imageInfo->frameHeight,
			_imageInfo->hMemDC,
			destX * _imageInfo->frameWidth,
			destY * _imageInfo->frameHeight, SRCCOPY);
	}
}

void Image::frameRenderUI(HDC hdc, const CTransform* transform)
{
	Vector2 pos = transform->m_pos - transform->m_pivot * transform->m_scale;
	if (_isTrans)
	{
		//비트맵을 불러올때 특정 색상을 제외하고 복사해주는 함수
		GdiTransparentBlt(
			hdc,													//복삳될 장소의 DC
			pos.x,													//복사될 좌표의 시작점X
			pos.y,													//복사될 좌표의 시작점Y
			_imageInfo->frameWidth,									//복사될 이미지 가로크기
			_imageInfo->frameHeight,								//복사될 이미지 세로크기
			_imageInfo->hMemDC,										//복사될 대상DC
			_imageInfo->currentFrameX * _imageInfo->frameWidth,		//복사시작 지점 X
			_imageInfo->currentFrameY * _imageInfo->frameHeight,	//복사시작 지점 Y
			_imageInfo->frameWidth,									//복사영역 가로크기
			_imageInfo->frameHeight,								//복사영역 세로크기
			_transColor);
	}
	else {
		//BitBlt : DC영역끼리 고속복사
		BitBlt(hdc,
			pos.x,
			pos.y, _imageInfo->frameWidth, _imageInfo->frameHeight,
			_imageInfo->hMemDC,
			_imageInfo->currentFrameX * _imageInfo->frameWidth,
			_imageInfo->currentFrameY * _imageInfo->frameHeight, SRCCOPY);
	}
}

void Image::frameRenderUI(HDC hdc, const CTransform* transform, const int destX, const int destY)
{
	Vector2 pos = transform->m_pos - transform->m_pivot * transform->m_scale;
	if (_isTrans)
	{
		//비트맵을 불러올때 특정 색상을 제외하고 복사해주는 함수
		GdiTransparentBlt(
			hdc,													//복삳될 장소의 DC
			pos.x,													//복사될 좌표의 시작점X
			pos.y,													//복사될 좌표의 시작점Y
			_imageInfo->frameWidth,									//복사될 이미지 가로크기
			_imageInfo->frameHeight,								//복사될 이미지 세로크기
			_imageInfo->hMemDC,										//복사될 대상DC
			destX * _imageInfo->frameWidth,							//복사시작 지점 X
			destY * _imageInfo->frameHeight,						//복사시작 지점 Y
			_imageInfo->frameWidth,									//복사영역 가로크기
			_imageInfo->frameHeight,								//복사영역 세로크기
			_transColor);
	}
	else {
		//BitBlt : DC영역끼리 고속복사
		BitBlt(hdc,
			pos.x,
			pos.y, _imageInfo->frameWidth, _imageInfo->frameHeight,
			_imageInfo->hMemDC,
			destX * _imageInfo->frameWidth,
			destY * _imageInfo->frameHeight, SRCCOPY);
	}
}

void Image::frameRenderUI(HDC hdc, const CTransform* transform, Vector2 scale, const int destX, const int destY)
{
	Vector2 pos = transform->m_pos - scale * transform->m_pivot * transform->m_scale;
	if (_isTrans)
	{
		//비트맵을 불러올때 특정 색상을 제외하고 복사해주는 함수
		GdiTransparentBlt(
			hdc,													//복삳될 장소의 DC
			pos.x,													//복사될 좌표의 시작점X
			pos.y,													//복사될 좌표의 시작점Y
			_imageInfo->frameWidth * transform->m_scale.x,									//복사될 이미지 가로크기
			_imageInfo->frameHeight * transform->m_scale.y,								//복사될 이미지 세로크기
			_imageInfo->hMemDC,										//복사될 대상DC
			destX * _imageInfo->frameWidth,							//복사시작 지점 X
			destY * _imageInfo->frameHeight,						//복사시작 지점 Y
			_imageInfo->frameWidth,									//복사영역 가로크기
			_imageInfo->frameHeight,								//복사영역 세로크기
			_transColor);
	}
	else {
		//BitBlt : DC영역끼리 고속복사
		BitBlt(hdc,
			pos.x,
			pos.y, _imageInfo->frameWidth, _imageInfo->frameHeight,
			_imageInfo->hMemDC,
			destX * _imageInfo->frameWidth,
			destY * _imageInfo->frameHeight, SRCCOPY);
	}
}

void Image::frameRenderUI(HDC hdc, const CTransform* transform, Vector2 scale, Vector2 customPos, const int destX, const int destY)
{
	Vector2 pos = transform->m_pos + customPos - scale * transform->m_pivot * transform->m_scale;
	if (_isTrans)
	{
		//비트맵을 불러올때 특정 색상을 제외하고 복사해주는 함수
		GdiTransparentBlt(
			hdc,													//복삳될 장소의 DC
			pos.x,													//복사될 좌표의 시작점X
			pos.y,													//복사될 좌표의 시작점Y
			_imageInfo->frameWidth * transform->m_scale.x,									//복사될 이미지 가로크기
			_imageInfo->frameHeight * transform->m_scale.y,								//복사될 이미지 세로크기
			_imageInfo->hMemDC,										//복사될 대상DC
			destX * _imageInfo->frameWidth,							//복사시작 지점 X
			destY * _imageInfo->frameHeight,						//복사시작 지점 Y
			_imageInfo->frameWidth,									//복사영역 가로크기
			_imageInfo->frameHeight,								//복사영역 세로크기
			_transColor);
	}
	else {
		//BitBlt : DC영역끼리 고속복사
		BitBlt(hdc,
			pos.x,
			pos.y, _imageInfo->frameWidth, _imageInfo->frameHeight,
			_imageInfo->hMemDC,
			destX * _imageInfo->frameWidth,
			destY * _imageInfo->frameHeight, SRCCOPY);
	}
}

void Image::AlphaFrameRender(HDC hdc, const CTransform* transform, Vector2 scale, const int destX, const int destY, BYTE alpha)
{
	Vector2 pos = transform->m_pos - scale * transform->m_pivot * transform->m_scale - MG_CAMERA->GetPos();

	_blendFunc.SourceConstantAlpha = alpha;

	if (_isTrans)
	{
		BitBlt(_blendImage->hMemDC,
			0,
			0,
			_imageInfo->frameWidth,
			_imageInfo->frameHeight,
			hdc,
			pos.x,
			pos.y,
			SRCCOPY);

		GdiTransparentBlt(_blendImage->hMemDC,
			0,
			0,
			_imageInfo->frameWidth * transform->m_scale.x,
			_imageInfo->frameHeight * transform->m_scale.y,
			_imageInfo->hMemDC,
			_imageInfo->frameWidth * destX,
			_imageInfo->frameHeight * destY,
			_imageInfo->frameWidth,
			_imageInfo->frameHeight,
			_transColor);

		AlphaBlend(hdc,
			pos.x,
			pos.y,
			_imageInfo->frameWidth * transform->m_scale.x,
			_imageInfo->frameHeight * transform->m_scale.y,
			_blendImage->hMemDC,
			0,
			0,
			_imageInfo->frameWidth,
			_imageInfo->frameHeight,
			_blendFunc);
	}
	else
	{
		AlphaBlend(hdc,
			pos.x,
			pos.y,
			_imageInfo->frameWidth, _imageInfo->frameHeight,
			_imageInfo->hMemDC, 0, 0, _imageInfo->frameWidth * destX, _imageInfo->frameHeight * destY, _blendFunc);

	}
}

void Image::AlphaFrameRender(HDC hdc, const CTransform* transform, Vector2 scale, Vector2 customPos, const int destX, const int destY, BYTE alpha)
{
	Vector2 pos = transform->m_pos + customPos - scale * transform->m_pivot * transform->m_scale - MG_CAMERA->GetPos();

	_blendFunc.SourceConstantAlpha = alpha;

	if (_isTrans)
	{
		BitBlt(_blendImage->hMemDC,
			0,
			0,
			_imageInfo->frameWidth,
			_imageInfo->frameHeight,
			hdc,
			pos.x,
			pos.y,
			SRCCOPY);

		GdiTransparentBlt(_blendImage->hMemDC,
			0,
			0,
			_imageInfo->frameWidth * transform->m_scale.x,
			_imageInfo->frameHeight * transform->m_scale.y,
			_imageInfo->hMemDC,
			_imageInfo->frameWidth * destX,
			_imageInfo->frameHeight * destY,
			_imageInfo->frameWidth,
			_imageInfo->frameHeight,
			_transColor);

		AlphaBlend(hdc,
			pos.x,
			pos.y,
			_imageInfo->frameWidth * transform->m_scale.x,
			_imageInfo->frameHeight * transform->m_scale.y,
			_blendImage->hMemDC,
			0,
			0,
			_imageInfo->frameWidth,
			_imageInfo->frameHeight,
			_blendFunc);
	}
	else
	{
		AlphaBlend(hdc,
			pos.x,
			pos.y,
			_imageInfo->frameWidth, _imageInfo->frameHeight,
			_imageInfo->hMemDC, 0, 0, _imageInfo->frameWidth* destX, _imageInfo->frameHeight * destY, _blendFunc);

	}
}

void Image::frameRender(HDC hdc, const int destX, const int destY, const int currentFrameX, const int currentFrameY)
{

	_imageInfo->currentFrameX = currentFrameX;
	_imageInfo->currentFrameY = currentFrameY;

	if (_isTrans)
	{
		//비트맵을 불러올때 특정 색상을 제외하고 복사해주는 함수
		GdiTransparentBlt(
			hdc,													//복삳될 장소의 DC
			destX,													//복사될 좌표의 시작점X
			destY,													//복사될 좌표의 시작점Y
			_imageInfo->frameWidth,									//복사될 이미지 가로크기
			_imageInfo->frameHeight,								//복사될 이미지 세로크기
			_imageInfo->hMemDC,										//복사될 대상DC
			_imageInfo->currentFrameX * _imageInfo->frameWidth,		//복사시작 지점 X
			_imageInfo->currentFrameY * _imageInfo->frameHeight,	//복사시작 지점 Y
			_imageInfo->frameWidth,									//복사영역 가로크기
			_imageInfo->frameHeight,								//복사영역 세로크기
			_transColor);
	}
	else {
		//BitBlt : DC영역끼리 고속복사
		BitBlt(hdc, destX, destY, _imageInfo->frameWidth, _imageInfo->frameHeight,
			_imageInfo->hMemDC,
			_imageInfo->currentFrameX * _imageInfo->frameWidth,
			_imageInfo->currentFrameY * _imageInfo->frameHeight, SRCCOPY);
	}
}


void Image::RotateRender(HDC hdc, const CTransform* transform, Vector2 scale)
{
	if (!_rotateImage) this->initForRotate();
	POINT rPoint[3];
	int dist = sqrt((_imageInfo->width / 2) * (_imageInfo->width / 2) + (_imageInfo->height / 2) * (_imageInfo->height / 2));
	float baseAngle[3];
	baseAngle[0] = PI - atanf(((float)_imageInfo->height / 2) / ((float)_imageInfo->width / 2));
	baseAngle[1] = atanf(((float)_imageInfo->height / 2) / ((float)_imageInfo->width / 2));
	baseAngle[2] = PI + atanf(((float)_imageInfo->height / 2) / ((float)_imageInfo->width / 2));

	for (int i = 0; i < 3; i++)
	{
		rPoint[i].x = (_rotateImage->width / 2 + cosf(baseAngle[i] + transform->angle) * dist);
		rPoint[i].y = (_rotateImage->height / 2 + -sinf(baseAngle[i] + transform->angle) * dist);
	}

	Vector2 pos = transform->m_pos - scale * transform->m_pivot - MG_CAMERA->GetPos();
	if (_isTrans)
	{
		BitBlt(_rotateImage->hMemDC, 0, 0, _rotateImage->width, _rotateImage->height, hdc, 0, 0, BLACKNESS);
		HBRUSH hBrush = CreateSolidBrush(_transColor);
		HBRUSH oBrush = (HBRUSH)SelectObject(_rotateImage->hMemDC, hBrush);
		ExtFloodFill(_rotateImage->hMemDC, 1, 1, RGB(0, 0, 0), FLOODFILLSURFACE);
		DeleteObject(hBrush);

		PlgBlt(_rotateImage->hMemDC, rPoint, _imageInfo->hMemDC,
			0, 0,
			_imageInfo->width,
			_imageInfo->height,
			NULL, 0, 0);
		GdiTransparentBlt(hdc,
			pos.x - _rotateImage->width / 2,
			pos.y - _rotateImage->height / 2,
			_rotateImage->width * transform->m_scale.x,
			_rotateImage->height * transform->m_scale.y,
			_rotateImage->hMemDC,
			0, 0,
			_rotateImage->width,
			_rotateImage->height,
			_transColor);
	}
	else
	{
		PlgBlt(hdc, rPoint, _imageInfo->hMemDC, 0, 0, _imageInfo->width, _imageInfo->height, NULL, 0, 0);
	}
}

void Image::RotateFrameRender(HDC hdc, const CTransform* transform, Vector2 scale, const int destX, const int destY)
{
	if (!_rotateImage) this->initForRotate();
	POINT rPoint[3];
	int dist = sqrt((_imageInfo->frameWidth / 2) * (_imageInfo->frameWidth / 2) + (_imageInfo->frameHeight / 2) * (_imageInfo->frameHeight / 2));
	float baseAngle[3];
	baseAngle[0] = PI - atanf(((float)_imageInfo->frameHeight / 2) / ((float)_imageInfo->frameWidth / 2));
	baseAngle[1] = atanf(((float)_imageInfo->frameHeight / 2) / ((float)_imageInfo->frameWidth / 2));
	baseAngle[2] = PI + atanf(((float)_imageInfo->frameHeight / 2) / ((float)_imageInfo->frameWidth / 2));

	for (int i = 0; i < 3; i++)
	{
		rPoint[i].x = (_rotateImage->frameWidth / 2 + cosf(baseAngle[i] + transform->angle) * dist);
		rPoint[i].y = (_rotateImage->frameHeight / 2 + -sinf(baseAngle[i] + transform->angle) * dist);
	}
	Vector2 pos = transform->m_pos - scale * transform->m_pivot * transform->m_scale - MG_CAMERA->GetPos();
	//Vector2 pos = transform->m_pos - scale * transform->m_pivot - MG_CAMERA->GetPos();
	if (_isTrans)
	{
		BitBlt(_rotateImage->hMemDC, 
			0, 
			0, 
			_rotateImage->frameWidth, 
			_rotateImage->frameHeight, 
			hdc, 
			destX* _rotateImage->frameWidth,							//복사시작 지점 X
			destY* _rotateImage->frameHeight,						//복사시작 지점 Y
			BLACKNESS);
		HBRUSH hBrush = CreateSolidBrush(_transColor);
		HBRUSH oBrush = (HBRUSH)SelectObject(_rotateImage->hMemDC, hBrush);
		ExtFloodFill(_rotateImage->hMemDC, 1, 1, RGB(0, 0, 0), FLOODFILLSURFACE);
		DeleteObject(hBrush);

		PlgBlt(_rotateImage->hMemDC, rPoint, _imageInfo->hMemDC,
			0, 0,
			_imageInfo->frameWidth,
			_imageInfo->frameHeight,
			NULL, 0, 0);
		GdiTransparentBlt(hdc,
			pos.x - _rotateImage->frameWidth / 2,
			pos.y - _rotateImage->frameHeight / 2,
			_rotateImage->frameWidth * transform->m_scale.x,
			_rotateImage->frameHeight * transform->m_scale.y,
			_rotateImage->hMemDC,
			destX * _imageInfo->frameWidth,							//복사시작 지점 X
			destY * _imageInfo->frameHeight,						//복사시작 지점 Y
			_rotateImage->frameWidth,
			_rotateImage->frameHeight,
			_transColor);
	
	}
	else
	{
		PlgBlt(hdc, rPoint, _imageInfo->hMemDC, 
			destX * _imageInfo->frameWidth,							//복사시작 지점 X
			destY * _imageInfo->frameHeight,						//복사시작 지점 Y	
			_imageInfo->width, _imageInfo->height, NULL, 0, 0);
	}
}


void Image::loopRender(HDC hdc, const LPRECT drawArea, int offsetX, int offsetY)
{
	//보정하기
	if (offsetX < 0)offsetX = _imageInfo->width + (offsetX % _imageInfo->width);
	if (offsetY < 0)offsetY = _imageInfo->height + (offsetY % _imageInfo->height);


	//그려지는(복사되어오는 이미지 영역)
	RECT rcSour;


	int sourWidth;
	int sourHeight;

	//그려지는 DC영역
	RECT rcDest;

	int drawAreaX = drawArea->left;
	int drawAreaY = drawArea->top;
	int drawAreaW = drawArea->right - drawArea->left;
	int drawAreaH = drawArea->bottom - drawArea->top;


	//세로 루프영역
	for (size_t y = 0; y < drawAreaH; y+=sourHeight)
	{
		//영역의  높이 계산하자
		rcSour.top = (y + offsetY) % _imageInfo->height;
		rcSour.bottom = _imageInfo->height;
		sourHeight = rcSour.bottom - rcSour.top;

		//영역이 그리는 화면을 넘어갔다면(화면밖으로 나갔을때)
		if (y + sourHeight > drawAreaH)
		{
			//넘어간 그림의 값만큼 바텀을 값을 올려줌
			rcSour.bottom -= (y + sourHeight) - drawAreaH;
			sourHeight = rcSour.bottom - rcSour.top;
		}
		rcDest.top = y + drawAreaY;
		rcDest.bottom = rcDest.top + sourHeight;
		
		for (size_t x = 0; x < drawAreaW; x+=sourWidth)
		{
			//영역계산
			rcSour.left = (x + offsetX) % _imageInfo->width;
			rcSour.right = _imageInfo->width;
			sourWidth = rcSour.right - rcSour.left;

			//화면밖으로 넘어 갔다면
			if (x + sourWidth > drawAreaW)
			{
				rcSour.right -= (x + sourWidth) - drawAreaW;
				sourWidth = rcSour.right - rcSour.left;
			}
			rcDest.left = x + drawAreaX;
			rcDest.right = rcDest.left+sourWidth;


			//그리자
			render(hdc, rcDest.left, rcDest.top,
				rcSour.left, rcSour.top,
				rcSour.right - rcSour.left,
				rcSour.bottom - rcSour.top);
		}
	}
}

void Image::loopAlphaRender(HDC hdc, const LPRECT drawArea, int offsetX, int offsetY, BYTE alpha)
{
	//보정하기
	if (offsetX < 0)offsetX = _imageInfo->width + (offsetX % _imageInfo->width);
	if (offsetY < 0)offsetY = _imageInfo->height + (offsetY % _imageInfo->height);


	//그려지는(복사되어오는 이미지 영역)
	RECT rcSour;


	int sourWidth;
	int sourHeight;

	//그려지는 DC영역
	RECT rcDest;

	int drawAreaX = drawArea->left;
	int drawAreaY = drawArea->top;
	int drawAreaW = drawArea->right - drawArea->left;
	int drawAreaH = drawArea->bottom - drawArea->top;

	//세로 루프영역
	for (size_t y = 0; y < drawAreaH; y += sourHeight)
	{
		//영역의  높이 계산하자
		rcSour.top = (y + offsetY) % _imageInfo->height;
		rcSour.bottom = _imageInfo->height;
		sourHeight = rcSour.bottom - rcSour.top;

		//영역이 그리는 화면을 넘어갔다면(화면밖으로 나갔을때)
		if (y + sourHeight > drawAreaH)
		{
			//넘어간 그림의 값만큼 바텀을 값을 올려줌
			rcSour.bottom -= (y + sourHeight) - drawAreaH;
			sourHeight = rcSour.bottom - rcSour.top;
		}
		rcDest.top = y + drawAreaY;
		rcDest.bottom = rcDest.top + sourHeight;

		for (size_t x = 0; x < drawAreaW; x += sourWidth)
		{
			//영역계산
			rcSour.left = (x + offsetX) % _imageInfo->width;
			rcSour.right = _imageInfo->width;
			sourWidth = rcSour.right - rcSour.left;

			//화면밖으로 넘어 갔다면
			if (x + sourWidth > drawAreaW)
			{
				rcSour.right -= (x + sourWidth) - drawAreaW;
				sourWidth = rcSour.right - rcSour.left;
			}
			rcDest.left = x + drawAreaX;
			rcDest.right = rcDest.left + sourWidth;


			//그리자
			alphaRender(hdc, rcDest.left, rcDest.top,
				rcSour.left, rcSour.top,
				rcSour.right - rcSour.left,
				rcSour.bottom - rcSour.top, alpha);
		
		}
	}
}

void Image::alphaRender(HDC hdc, BYTE alpha)
{
	//알파값 초기화
	_blendFunc.SourceConstantAlpha = alpha;

	if (_isTrans)
	{
		BitBlt(_blendImage->hMemDC, 
			0, 
			0, 
			_imageInfo->width, _imageInfo->height,
			hdc, _imageInfo->x, _imageInfo->y, SRCCOPY);
		
		GdiTransparentBlt(_blendImage->hMemDC, 0, 0, _imageInfo->width, _imageInfo->height,
			_imageInfo->hMemDC, 0, 0, _imageInfo->width, _imageInfo->height, _transColor);

		AlphaBlend(hdc, _imageInfo->x, _imageInfo->y, _imageInfo->width, _imageInfo->height,
			_blendImage->hMemDC, 0, 0, _imageInfo->width, _imageInfo->height, _blendFunc);
	}
	else 
	{
		AlphaBlend(hdc, _imageInfo->x, _imageInfo->y, _imageInfo->width, _imageInfo->height,
			_imageInfo->hMemDC, 0, 0, _imageInfo->width, _imageInfo->height, _blendFunc);

	}

}

void Image::alphaRender(HDC hdc, const int destX, const int destY, BYTE alpha)
{

	//알파값 초기화
	_blendFunc.SourceConstantAlpha = alpha;

	if (_isTrans)
	{
		BitBlt(_blendImage->hMemDC, 0, 0, _imageInfo->width, _imageInfo->height,
			hdc, destX, destY, SRCCOPY);

		GdiTransparentBlt(_blendImage->hMemDC, 0, 0, _imageInfo->width, _imageInfo->height,
			_imageInfo->hMemDC, 0, 0, _imageInfo->width, _imageInfo->height, _transColor);

		AlphaBlend(hdc, destX, destY, _imageInfo->width, _imageInfo->height,
			_blendImage->hMemDC, 0, 0, _imageInfo->width, _imageInfo->height, _blendFunc);
	}
	else
	{
		AlphaBlend(hdc, destX, destY, _imageInfo->width, _imageInfo->height,
			_imageInfo->hMemDC, 0, 0, _imageInfo->width, _imageInfo->height, _blendFunc);

	}
}

void Image::alphaRender(HDC hdc, const int destX, const int destY, const int sourX, const int sourY, const int sourWidth, const int sourHeight, BYTE alpha)
{

	//알파값 초기화
	_blendFunc.SourceConstantAlpha = alpha;

	if (_isTrans)
	{
		BitBlt(_blendImage->hMemDC, 0, 0, _imageInfo->width, _imageInfo->height,
			hdc, destX, destY, SRCCOPY);

		GdiTransparentBlt(_blendImage->hMemDC, 0, 0, sourWidth, sourHeight,
			_imageInfo->hMemDC, sourX, sourY, sourWidth, sourHeight, _transColor);

		AlphaBlend(hdc, destX, destY, sourWidth, sourHeight,_blendImage->hMemDC, 0, 0, sourWidth, sourHeight, _blendFunc);
	}
	else
	{
		AlphaBlend(hdc, destX, destY, sourWidth, sourHeight,_imageInfo->hMemDC, sourX, sourY, sourWidth, sourHeight, _blendFunc);

	}
}

void Image::aniRender(HDC hdc, const int destX, const int destY, animation* ani)
{
	render(hdc, destX, destY, ani->getFramePos().x, ani->getFramePos().y, ani->getFrameWidth(), ani->getFrameHeight());
}
