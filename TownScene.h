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

	void Show_abbey(HDC _hdc);//������
	void Show_blacksmith(HDC _hdc); //���尣
	void Show_campingTrainer(HDC _hdc); //������� ���°�
	void Show_graveyard(HDC _hdc); //����
	void Show_guild(HDC _hdc); //��� 
	void Show_nomad_wagon(HDC _hdc); //����� ���� -> ����
	void Show_stage_coach(HDC _hdc); //�뺴���
	void Show_town_statue(HDC _hdc); //������Ȳ �����ִ� �ü�.
	void Show_sanitarium(HDC _hdc); //����
	void Show_tavern(HDC _hdc); //����

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