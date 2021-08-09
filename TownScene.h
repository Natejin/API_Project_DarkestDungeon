#pragma once
#include "Scene.h"
class TownScene : public Scene
{
protected:
	class Abbey* m_abbey;
	class BlackSmith* m_blacksmith ;
	class CampingTrainer* m_campingTrainer;
	class GraveYard* m_graveyard;
	class Guild* m_guild;
	class Sanitarium* m_sanitarium ;
	class StageCoach* m_stage_coach ;
	class Statue* m_statue ;
	class NomadWagon* m_nomad_wagon;
	class Tavern* m_tavern;
private:

	class CHero* m_hero;
	
public:
	class CEst_UI* m_estui;

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
	void SetUI();

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

	void Show_Activity_log();
	void SetHerolist();

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