#pragma once
#include "Scene.h"

class TownScene : public Scene
{
public:

	class CBackground* m_townBG;

	void Show_AllTownScene(HDC _hdc);

	void Show_Estate(HDC _hdc);

	Rect abbey_rc;
	Rect blacksmith_rc;
	Rect campingTrainer_rc;
	Rect graveyard_rc;
	Rect guild_rc;
	Rect nomad_wagon_rc;
	Rect stage_coach_rc;
	Rect town_statue_rc;
	Rect sanitarium_rc;
	Rect tavern_rc;

	void Show_abbey(HDC _hdc);//수도원
	void Show_blacksmith(HDC _hdc); //대장간
	void Show_campingTrainer(HDC _hdc); //생존기술 배우는곳
	void Show_graveyard(HDC _hdc); //묘지
	void Show_guild(HDC _hdc); //길드 
	void Show_nomad_wagon(HDC _hdc); //유목민 마차 -> 상점
	void Show_stage_coach(HDC _hdc); //용병고용
	void Show_town_statue(HDC _hdc); //영지상황 보여주는 시설.
	void Show_sanitarium(HDC _hdc); //요양원
	void Show_tavern(HDC _hdc); //여관

	vector<Image*> vtown;
	vector<CTransform> ts_vtown;
public:
	TownScene();
	virtual~TownScene();



public:
	virtual HRESULT Init();
	virtual HRESULT Init(bool managerInit);
	virtual void Release();
	virtual void Update();
	virtual void Update(HDC _hdc);

	virtual void Render(HDC _hdc);

};