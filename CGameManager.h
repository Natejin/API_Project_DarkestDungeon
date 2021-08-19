#pragma once
#include"singleton.h"

class CHero;
class CParty;
class CGameManager : public Singleton<CGameManager>
{
private:
	//map<int,class GameObject*> objectMap;


public:

	class DungeonScene* m_dungeonScene;
	class TownScene* m_townScene;
	CGameManager();
	~CGameManager();

	int heroID;

	HRESULT Init();

	virtual void Update(float deltaTime, float worldTime);
	virtual void LateUpdate();

	virtual void BackRender(HDC _hdc);
	virtual void Render(HDC _hdc);
	virtual void FrontRender(HDC _hdc);

	virtual void Release();

	//==================================
	vector<CHero*> m_partyOrigin;
	vector<CHero*> m_ownHeroes;

	//CParty* m_party;
	CHero* m_CurSelHero;

	bool RegisterHeroToParty(CHero* hero);
	bool RegisterHeroToParty(int ownIndex);

	void RegisterHeroToOwnList(CHero* hero);
	bool RemoveHeroFromParty(CHero* hero);
	bool RemoveHeroFromOwnList(int heroId);
	vector<CHero*> GetHeroes();
	CHero* GetHero(int index);
	CHero* GetHeroFromParty(int index);

	//void setParty();
	CParty* GetParty();

	class CHero* CreateHero(string name, JOB job);
	CHero* GetCurSelHero();
	void SetCurSelHero(int i);
	int GetHeroPartySize() { return m_partyOrigin.size(); }
	//=======================================


};