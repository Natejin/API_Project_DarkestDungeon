#pragma once
#include "Scene.h"

class TestScene : public Scene
{
public:
	void Show_AllTownScene();

	void Show_abbey();//수도원
	void Show_blacksmith(); //대장간
	void Show_campingTrainer(); //생존기술 배우는곳
	void Show_graveyard(); //묘지
	void Show_guild(); //길드 
	void Show_nomad_wagon(); //유목민 마차 -> 상점
	void Show_stage_coach(); //용병고용
	void Show_town_statue(); //영지상황 보여주는 시설.
	void Show_sanitarium(); //요양원
	void Show_tavern(); //여관

public:
	TestScene();
	virtual~TestScene();

	virtual HRESULT Init();
	virtual HRESULT Init(bool managerInit);
	virtual void Release();
	virtual void Update();
	virtual void Render(HDC _hdc);

};