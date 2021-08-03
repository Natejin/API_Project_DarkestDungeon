#pragma once
#include "Scene.h"

class CParty;
class CEnemy;
class RoomScene : public Scene
{
public:
	int turn_number[8];
	int _Turn = 0;
	bool Behave;
	CParty* m_player;
	vector<CEnemy*> Enermy_arr;

	RoomScene();
	virtual~RoomScene();

	virtual HRESULT Init();
	virtual HRESULT Init(bool managerInit);
	virtual void Release();
	virtual void Update();
	virtual void Render(HDC _hdc);

	void Create_Player_Party();
	void Create_Enermy_Party();
	void Compare_P_E_Speed_ReArray();

	void Battle();
	void Battle_Start();
	void Battle_Finish();

	void CheckButton();

};