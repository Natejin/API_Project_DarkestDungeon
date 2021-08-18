#pragma once

class COwnHeroListPanel : public GameObject
{
public :
	class TownScene* m_townScene;

	HRESULT Init();

	virtual void Update(float deltaTime, float worldTime);
	virtual void LateUpdate();

	virtual void BackRender(HDC _hdc);
	virtual void Render(HDC _hdc);
	virtual void FrontRender(HDC _hdc);

	virtual void Release();

	virtual void Disable();
	virtual void Enable();



};