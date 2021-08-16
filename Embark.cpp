#include "framework.h"
#include "Embark.h"
#include "CButton.h"

Embark::Embark() {}
Embark::~Embark() {}

HRESULT Embark::Init()
{
	m_transform->m_pivot = Vector2(0, 0);
	m_transform->m_pos = Vector2(0, 0);

	AddSpriteRenderer();
	setEmbarkBt();

	m_layer = LAYER::UI;
	return S_OK;
}

void Embark::Update(float deltaTime, float worldTime)
{
}

void Embark::LateUpdate()
{
}

void Embark::BackRender(HDC _hdc)
{
}

void Embark::Render(HDC _hdc)
{
}

void Embark::FrontRender(HDC _hdc)
{
	for (int i = 0; i < m_images.size(); i++)
	{
		m_images[i]->Render(_hdc);
	}
}

void Embark::Release()
{
	GameObject::Release();
	MG_GMOBJ->RemoveObj(bt_embark);
	MG_GMOBJ->RemoveObj(bt_selDungeon);

	for (int i = 0; i < m_images.size(); i++)
	{
		SAFE_DELETE(m_images[i]);
	}
	for (int i = 0; i < m_slots.size(); i++)
	{
		MG_GMOBJ->RemoveObj(m_slots[i]);
	};
}

void Embark::embarkBg()
{
	if (MG_INPUT->isOnceKeyDown('P'))
	{
		isEmbark = true;
	}
}

void Embark::setImg()
{
	class CSpriteRenderer* r_embarkBg = new CSpriteRenderer("selDungeonBg", m_transform);
	m_images.push_back(r_embarkBg);

	CTransform* temp = new CTransform;
	temp->m_pos = Vector2(WINSIZEX / 2, WINSIZEY - 300);
	temp->m_pivot = Vector2(0.5, 0.5);

	class CSpriteRenderer* r_heroSlot = new CSpriteRenderer("partySlot_", temp);
	m_images.push_back(r_heroSlot);
}


//==================================


void Embark::setEmbarkBt()
{
	bt_embark = new CButton;
	bt_embark->m_transform->m_pivot = Vector2(0.5, 0.5);
	bt_embark->m_transform->m_pos = Vector2(WINSIZEX / 2, WINSIZEY - 200);
	bt_embark->AddColliderBox(100, 65);
	bt_embark->AddSpriteRenderer("embark");
	bt_embark->SetTriggerWhenDown(this, &Embark::setEmbark);
	bt_embark->Enable();
	MG_GMOBJ->RegisterObj("townUI_embarkBt", bt_embark);

	bt_selDungeon = new CButton;
	bt_selDungeon->m_transform->m_pivot = Vector2(0.5, 0.5);
	bt_selDungeon->m_transform->m_pos = Vector2(1000, 400);
	bt_selDungeon->AddColliderBox(100, 100);
	bt_selDungeon->AddSpriteRenderer("embark_dungeon");
	bt_selDungeon->SetTriggerWhenDown(this, &Embark::enterDungeon);
	bt_selDungeon->Disable();
	MG_GMOBJ->RegisterObj("townUI_embarkBt", bt_selDungeon);
}

void Embark::setEmbarkPartySlot()
{
}

void Embark::setDungeonBt()
{

}

void Embark::setEmbark()
{
	m_townScene->DeactivateBuildings();
	bt_selDungeon->Enable();
	setPartySlot();
	setImg();
	Enable();
}

void Embark::setPartySlot()
{
	for (int i = 0; i < 4; i++)
	{
		class EmbarkPartySlot* slot = new EmbarkPartySlot;
		slot->Init();
		slot->m_transform->m_pos = Vector2(1000 + i * 100, 780);
		slot->m_townScene = this->m_townScene;
		m_slots.push_back(slot);
		MG_GMOBJ->RegisterObj("partySlot", slot);
	}
}

void Embark::enterDungeon()
{
	if (MG_GAME->GetHeroPartySize() == 4)
	{
		MG_SCENE->changeScene(SCENETYPE::Dungeon);
	}
	
}
