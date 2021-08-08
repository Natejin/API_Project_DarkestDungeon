#pragma once
#include "Scene.h"
#include"CButton.h"
#include"CBG_Town.h"
#include"CEst_UI.h"
class TownScene : public Scene
{
public:
	CEst_UI* m_estui;
public:

	bool abbey_b;
	bool blacksmith_b;
	bool campingTrainer_b;
	bool graveyard_b;
	bool guild_b;
	bool nomad_wagon_b;
	bool stage_coach_b;
	bool town_statue_b;
	bool sanitarium_b;
	bool tavern_b;
//================================
	bool abbey_ui;
	bool blacksmith_ui;
	bool campingTrainer_ui;
	bool graveyard_ui;
	bool guild_ui;
	bool nomad_wagon_ui;
	bool stage_coach_ui;
	bool town_statue_ui;
	bool sanitarium_ui;
	bool tavern_ui;

public:
	//버튼.
	void SetIMG_Est();

public:
	//이미지.
	
	void Show_abeey();//수도원
	void Show_blacksmith(); //대장간
	void Show_campingTrainer(); //생존기술 배우는곳
	void Show_graveyard(); //묘지
	void Show_guild(); //길드 
	void Show_nomad_wagon(); //유목민 마차 -> 상점
	void Show_stage_coach(); //용병고용
	void Show_town_statue(); //영지상황 보여주는 시설.
	void Show_sanitarium(); //요양원
	void Show_tavern(); //여관
	void Set_quick();

public:
	TownScene();
	virtual~TownScene();

public:
	virtual HRESULT Init();
	virtual HRESULT Init(bool managerInit);
	virtual void Release();
	virtual void Update();
	virtual void Render();
	virtual void Render(HDC _hdc);

};