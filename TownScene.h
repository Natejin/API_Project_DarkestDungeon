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
	vector<class CDragButton*> m_dragButton;

private:
	class CHeroList_button* dragButton;
	vector<class CBuilding*> buildingVec;
	
public:
	int curDragHeroIndex;
	bool isDrag; // �巡�����̳�.
	bool isHold; // ����ֳ�.

public:
	void SetEst_ui(); //�ǹ�����
	void SetEst_Img();//��ư.

public:
	void SetDeactiveWhenClick(GameObject* object);
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


	void DeactivateBuildings();
	void ActivateBuildings();
};