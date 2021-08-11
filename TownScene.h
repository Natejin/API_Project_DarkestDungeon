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
	vector<class CDragButton*> m_dragButton;

private:
	class CHeroList_button* dragButton;

public:
	int curDragHeroIndex;
	bool isDrag; // �巡�����̳�.
	bool isHold; // ����ֳ�.

public:
	void SetEst_ui(); //�ǹ�����
	void SetEst_Img();//��ư.
public:
	
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
	void Mouse();

public:
	TownScene();
	~TownScene();

public:
	virtual HRESULT Init();
	virtual HRESULT Init(bool managerInit);
	virtual void Release();
	virtual void Update();
	virtual void Render();
	virtual void Render(HDC _hdc);

};