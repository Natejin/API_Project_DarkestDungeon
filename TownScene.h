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
	//��ư.
	void SetIMG_Est();

public:
	//�̹���.
	
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