#pragma once
#include "Scene.h"

class TownScene : public Scene
{
protected:
	class CUIPanel_Abbey* m_abbey;
	class CUIPanel_BlackSmith* m_blacksmith ;
	class CUIPanel_CampingTrainer* m_campingTrainer;
	class CUIPanel_GraveYard* m_graveyard;
	class CUIPanel_Guild* m_guild;
	class CUIPanel_Sanitarium* m_sanitarium ;
	class CUIPanel_StageCoach* m_stage_coach ;
	class CUIPanel_Statue* m_statue ;
	class CUIPanel_NomadWagon* m_nomad_wagon;
	class CUIPanel_Tavern* m_tavern;
	class CBG_Town* m_town;
	vector<class CBuilding*> buildingVec;
	
	class CUI_Panel_Hero* m_hero_panel;

	class COwnHeroListPanel* addMemberCollider;

public:
	class Hero_Roster* m_DummyRosterButton;
	vector<class CHeroList_button*> m_heroListButtonVec;

	vector<class CHeroList_button*> m_coachHero;

	int curDragHeroIndex;
	bool isDrag; // �巡�����̳�.
	bool isHold; // ����ֳ�.

public:
	void SetEst_ui(); //�ǹ�����
	void SetEst_Img();//��ư.
	void SetRoster();
	void SetHeroPanel();

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
	void SetHerolist();

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

	void DeactivateBuildings();
	void ActivateBuildings();

	void ShowDummyHeroList(HeroListBtType type, int index);
	void ShowHeroPanel();
	void ShowCoachHeroPanel();

	class CUI_Panel_Hero* GetHeroPanel();
	class CHeroList_ui* m_heroListUI;

	//==================================
public:
	class Embark* m_embark;
	bool isEmbark;

	void setEmbark();

	void addOwnHero();
	void addMember(HeroListBtType type, int index);

};