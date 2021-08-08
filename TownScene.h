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
	//������ �Ҽ��ְ��ϴ� ��ư bool��
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
	//�ǹ�ui�̹��� ����bool��
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
	//��ư.
	void SetIMG_Est();
	//�������ư
	void Set_quick();


public:
	//��ư�� ��Ȱ�� �ϴ� bool���� �ٲٴ� �Լ�.
	void Show_abeey();//������
	void Show_blacksmith(); //���尣
	void Show_campingTrainer(); //������� ���°�
	void Show_graveyard(); //����
	void Show_guild(); //��� 
	void Show_nomad_wagon(); //����� ���� -> ����
	void Show_stage_coach(); //�뺴���
	void Show_town_statue(); //������Ȳ �����ִ� �ü�.
	void Show_sanitarium(); //����
	void Show_tavern(); //����
	
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