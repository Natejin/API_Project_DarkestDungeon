#pragma once
#include "Scene.h"
#include"CButton.h"
#include"CBG_Town.h"
#include"Abbey.h"
#include"BlackSmith.h"
#include"CampingTrainer.h"
#include"GraveYard.h"
#include"Guild.h"
#include"Sanitarium.h"
#include"Statue.h"
#include"StageCoach.h"
#include"NomadWagon.h"
#include"Tavern.h"

class TownScene : public Scene
{
protected:
	Abbey* m_abbey = new Abbey();
	BlackSmith* m_blacksmith = new BlackSmith();
	CampingTrainer* m_campingTrainer = new CampingTrainer();
	GraveYard* m_graveyard = new GraveYard();
	Guild* m_guild = new Guild();
	Sanitarium* m_sanitarium = new Sanitarium();
	StageCoach* m_stage_coach = new StageCoach();
	Statue* m_statue = new Statue();
	NomadWagon* m_nomad_wagon = new NomadWagon();
	Tavern* m_tavern = new Tavern();

public:
	CEst_UI* m_estui;

public:
	//껏켯을 할수있게하는 버튼 bool값
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
	//건물ui이미지 띄우는bool값
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
	//나가기버튼
	void Set_quick();


public:
	//버튼의 역활을 하는 bool값을 바꾸는 함수.
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