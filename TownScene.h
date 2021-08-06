#pragma once
#include "Scene.h"
#include"CButton.h"
#include"CBG_Town.h"
class TownScene : public Scene
{
public:

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

public:
	//��ư.
	void SetIMG_Est();
	void Set_EST_UI(); //�ǹ� UI

public:
	//�̹���.
	void Show_abbey();//������
	void Show_blacksmith(); //���尣
	void Show_campingTrainer(); //������� ���°�
	void Show_graveyard(); //����
	void Show_guild(); //��� 
	void Show_nomad_wagon(); //����� ���� -> ����
	void Show_stage_coach(); //�뺴���
	void Show_town_statue(); //������Ȳ �����ִ� �ü�.
	void Show_sanitarium(); //����
	void Show_tavern(); //����

	
	bool Isinput;

public:
	TownScene();
	virtual~TownScene();


public:
	virtual HRESULT Init();
	virtual HRESULT Init(bool managerInit);
	virtual void Release();
	virtual void Update();
	virtual void Render();

};