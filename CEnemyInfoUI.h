#pragma once

class CEnemy;
class CBattleSystem;
class CEnemyInfoUI : public GameObject
{
public:
	CSpriteRenderer* m_enemyInfoPanel;
	int enemyIndex;

	CBattleSystem* m_battleSys;
	CEnemy* temp;

public:
	CEnemyInfoUI();
	~CEnemyInfoUI();

	HRESULT Init();

	virtual void Update(float deltaTime, float worldTime);
	virtual void LateUpdate();

	virtual void BackRender(HDC _hdc);
	virtual void Render(HDC _hdc);
	virtual void FrontRender(HDC _hdc);

	virtual void Release();

	//==================================

	void setUIIMG();
	void isMouseOnEnemy();

	void showEnemyInfo(HDC _hdc);

	virtual void Disable();
	virtual void Enable();

};