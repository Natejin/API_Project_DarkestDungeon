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
	bool isDrag; // 드래그중이냐.
	bool isHold; // 들고있냐.

public:
	void SetEst_ui(); //건물셋팅
	void SetEst_Img();//버튼.
	void SetRoster();
	void SetHeroPanel();

public:
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