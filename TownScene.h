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
	void SetUI();

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