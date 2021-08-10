#pragma once
#include"singleton.h"

class CHero;
class CParty;
class CGameManager : public Singleton<CGameManager>
{
public:
	//map<int,class GameObject*> objectMap;
	vector<CHero*> m_partyOrigin;
	vector<CHero*> m_ownHeroes;

	CParty* m_party;
public:
	CGameManager();
	~CGameManager();

	HRESULT Init();

	virtual void Update(float deltaTime, float worldTime);
	virtual void LateUpdate();

	virtual void BackRender(HDC _hdc);
	virtual void Render(HDC _hdc);
	virtual void FrontRender(HDC _hdc);

	virtual void Release();

	//==================================

	void RegisterHero(CHero* hero);
	void RemoveHero(int id);
	vector<CHero*> GetHeroes();
	CHero* GetHero(int index);




	

	void setParty();
	CParty* GetParty();

	class CHero* CreateHero(string name, JOB job);

	int GetHeroPartySize() { return m_partyOrigin.size(); }
};