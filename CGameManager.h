#pragma once
#include"singleton.h"

class CHero;
class CGameManager : public Singleton<CGameManager>
{
private:
	//map<int,class GameObject*> objectMap;
	vector<CHero*> m_partyOrigin;
	vector<CHero*> m_ownHeroes;
	
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

	class Vestal* CreateVestal(string name);

	int GetHeroPartySize() {  return m_partyOrigin.size();}
	void HireHero(class CHero* _hero);
};