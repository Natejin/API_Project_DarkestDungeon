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

	class CSpriteRenderer* m_stunicon;
	class CSpriteRenderer* m_bleedicon;
	class CSpriteRenderer* m_moveicon;
	class CSpriteRenderer* m_blighicon;
	class CSpriteRenderer* m_debufficon;

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
	void drawResistancesImage(HDC _hdc);

	virtual void Disable();
	virtual void Enable();

};