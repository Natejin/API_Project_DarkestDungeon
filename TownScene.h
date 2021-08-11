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
	bool isDrag; // 드래그중이냐.
	bool isHold; // 들고있냐.

public:
	void SetEst_ui(); //건물셋팅
	void SetEst_Img();//버튼.
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