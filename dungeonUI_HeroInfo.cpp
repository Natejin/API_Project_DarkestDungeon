#include  "framework.h"
#include "dungeonUI_HeroInfo.h"
#include "CHero.h"
#include "CParty.h"
#include "CBTN_Skill.h"
#include "DungeonScene.h"

CDungeonUI_HeroInfo::CDungeonUI_HeroInfo() {}
CDungeonUI_HeroInfo::~CDungeonUI_HeroInfo() {}

HRESULT CDungeonUI_HeroInfo::Init()
{
    m_layer = LAYER::UI;

    selectedHeroIndex = 0; 

    setInfoImage();
    setButton();

    return S_OK;
}

void CDungeonUI_HeroInfo::Update(float deltaTime, float worldTime)
{
    //setInfoImage();
}

void CDungeonUI_HeroInfo::LateUpdate()
{
}

void CDungeonUI_HeroInfo::BackRender(HDC _hdc)
{
}

void CDungeonUI_HeroInfo::Render(HDC _hdc)
{
}

void CDungeonUI_HeroInfo::FrontRender(HDC _hdc)
{
    showHeroSkill(_hdc);
    showHeroEquip(_hdc);
    ShowHeroState(_hdc);
}

void CDungeonUI_HeroInfo::Release()
{
}


//==================================


void CDungeonUI_HeroInfo::setInfoImage()
{
    //portrait and skill
    portrait.m_img = MG_IMAGE->findImage(IMAGE::NONE);
    portrait.m_trans.m_pos = Vector2(364, 732);

 

 //   switch (MG_GAME->GetHero(selectedHeroIndex)->job)
 //   {
 //   case JOB::Crusader:
 //       portrait.m_img = MG_IMAGE->findImage("crusader_portrait");
 //       portrait.m_trans.m_pos = Vector2(364, 732);

 //       //skill1.m_img = MG_IMAGE->findImage("crusader_skill1");
 //       //skill1.m_trans.m_pos = Vector2(585, 732);

 //       //skill2.m_img = MG_IMAGE->findImage("crusader_skill2");
 //       //skill2.m_trans.m_pos = Vector2(655, 732);

 //       //skill3.m_img = MG_IMAGE->findImage("crusader_skill3");
 //       //skill3.m_trans.m_pos = Vector2(725, 732);

 //       //skill4.m_img = MG_IMAGE->findImage("crusader_skill4");
 //       //skill4.m_trans.m_pos = Vector2(795, 732);
 //       break;

 //   case JOB::Highwayman:
 //       break;

 //   case JOB::PlagueDoctor:
 //       break;

	//case JOB::Vestal:
 //       portrait.m_img = MG_IMAGE->findImage("vestal_portrait");
 //       portrait.m_trans.m_pos = Vector2(364, 732);

 //       /*skill1.m_img = MG_IMAGE->findImage("vestal_skill1");
 //       skill1.m_trans.m_pos = Vector2(585, 732);

	//	skill2.m_img = MG_IMAGE->findImage("vestal_skill2");
	//	skill2.m_trans.m_pos = Vector2(655, 732);

	//	skill3.m_img = MG_IMAGE->findImage("vestal_skill3");
	//	skill3.m_trans.m_pos = Vector2(725, 732);

	//	skill4.m_img = MG_IMAGE->findImage("vestal_skill4");
	//	skill4.m_trans.m_pos = Vector2(795, 732);*/
	//	break;
 //   }

 //   ImageData temp;
 //   temp.m_img = MG_IMAGE->findImage("ability_move");
 //   temp.m_trans.m_pos = Vector2(865, 732);
 //   m_heroInfoImage.push_back(temp);

 //   //pass
 //   temp.m_img = MG_IMAGE->findImage("ability_pass");
 //   temp.m_trans.m_pos = Vector2(935, 732);
 //   m_heroInfoImage.push_back(temp);

    //equip
    // switch (MG_GAME->GetHero(selectedHeroIndex)->GetJob())
    // {
    // case JOB::Crusader:
    //     m_weapon.m_img = MG_IMAGE->findImage(IMAGE::NONE);
    //     m_weapon.m_trans.m_pos = Vector2(575, 868);
    //     m_armor.m_img = MG_IMAGE->findImage(IMAGE::NONE);
    //     m_armor.m_trans.m_pos = Vector2(658, 868);
    //     break;

    m_weapon.m_img = MG_IMAGE->findImage(IMAGE::NONE);

    m_armor.m_img = MG_IMAGE->findImage(IMAGE::NONE);
    m_weapon.m_trans.m_pos = Vector2(575, 868);
    m_armor.m_trans.m_pos = Vector2(658, 868);

  //  //equip
  //  switch (MG_GAME->GetHero(selectedHeroIndex)->GetJob())
  //  {
  //  case JOB::Crusader:
  //      m_weapon.m_img = MG_IMAGE->findImage(IMAGE::enemy);
  //     
  //      m_armor.m_img = MG_IMAGE->findImage(IMAGE::enemy);
 
  //      break;

  //  case JOB::Highwayman:
  //      break;

  //  case JOB::PlagueDoctor:
  //      break;

  //  case JOB::Vestal:
  //      m_weapon.m_img = MG_IMAGE->findImage(IMAGE::enemy);
  //      m_weapon.m_trans.m_pos = Vector2(575, 868);
		//m_armor.m_img = MG_IMAGE->findImage(IMAGE::enemy);
  //      m_armor.m_trans.m_pos = Vector2(658, 868);
  //      break;
  //  }

}

void CDungeonUI_HeroInfo::setButton()
{
    for (size_t i = 0; i < MG_GAME->GetHeroPartySize(); i++)
    {
        MG_GAME->GetHero(i)->SetTriggerWhenClick(this, &CDungeonUI_HeroInfo::SelectHero);
    }
}

void CDungeonUI_HeroInfo::ShowHeroState(HDC _hdc)
{
    char str[256];
    string strFrame;
    SetBkMode(_hdc, TRANSPARENT);

    for (int i = 0; i < MG_GAME->GetHeroes().size(); i++)
    {
        if (MG_GAME->GetHero(i)->isSelected == true)
        {
            selectedHeroIndex = i;
        }
    }

    SetTextColor(_hdc, RGB(202, 201, 155));
    sprintf_s(str, "%s", "Name");
    TextOut(_hdc, 450, 740, str, strlen(str));

    SetTextColor(_hdc, RGB(255, 0, 0));
    switch (MG_GAME->GetHero(selectedHeroIndex)->GetJob())
    {
    case JOB::Crusader:
        
        sprintf_s(str, "33 / %d", MG_GAME->GetHero(selectedHeroIndex)->getHP());
        TextOut(_hdc, 400, 835, str, strlen(str));
        SetTextColor(_hdc, RGB(48, 48, 50));
        sprintf_s(str, "Crusader");
        break;

    case JOB::Highwayman:
        sprintf_s(str, "23 / %d", MG_GAME->GetHero(selectedHeroIndex)->getHP());
        TextOut(_hdc, 400, 835, str, strlen(str));
        SetTextColor(_hdc, RGB(48, 48, 50));
        sprintf_s(str, "Highwayman");
        break;

    case JOB::PlagueDoctor:
        sprintf_s(str, "22 / %d", MG_GAME->GetHero(selectedHeroIndex)->getHP());
        TextOut(_hdc, 400, 835, str, strlen(str));
        SetTextColor(_hdc, RGB(48, 48, 50));
        sprintf_s(str, "PlagueDoctor");
        break;

    case JOB::Vestal:
        sprintf_s(str, "%d / 24", MG_GAME->GetHero(selectedHeroIndex)->getHP());
        TextOut(_hdc, 400, 835, str, strlen(str));
        SetTextColor(_hdc, RGB(48, 48, 50));
        sprintf_s(str, "Vestal");
        break;
    }
    TextOut(_hdc, 450, 780, str, strlen(str));

    SetTextColor(_hdc, RGB(255, 255, 255));
    sprintf_s(str, "%d / 200", MG_GAME->GetHero(selectedHeroIndex)->getStress());
    TextOut(_hdc, 400, 860, str, strlen(str));

    sprintf_s(str, "ACC         %d", MG_GAME->GetHero(selectedHeroIndex)->GetAcry());
    TextOut(_hdc, 380, 885, str, strlen(str));
    sprintf_s(str, "CRIT        %d", MG_GAME->GetHero(selectedHeroIndex)->GetCri());
    TextOut(_hdc, 380, 905, str, strlen(str));
    sprintf_s(str, "DMG       %d", MG_GAME->GetHero(selectedHeroIndex)->GetDmg());
    TextOut(_hdc, 380, 925, str, strlen(str));
    sprintf_s(str, "DODGE   %d", MG_GAME->GetHero(selectedHeroIndex)->GetDodge());
    TextOut(_hdc, 380, 945, str, strlen(str));
    sprintf_s(str, "PROT      %d", MG_GAME->GetHero(selectedHeroIndex)->GetDef());
    TextOut(_hdc, 380, 965, str, strlen(str));
    sprintf_s(str, "SPD        %d", MG_GAME->GetHero(selectedHeroIndex)->getSPD());
    TextOut(_hdc, 380, 985, str, strlen(str));
}

void CDungeonUI_HeroInfo::showHeroSkill(HDC _hdc)
{
    portrait.m_img->renderUI(_hdc, &portrait.m_trans);
}

void CDungeonUI_HeroInfo::showHeroEquip(HDC _hdc)
{
    m_weapon.m_img->renderUI(_hdc, &m_weapon.m_trans);
    m_armor.m_img->renderUI(_hdc, &m_armor.m_trans);
}

void CDungeonUI_HeroInfo::SelectHero(int index)
{
    if (scene->m_dungeonMode == DUNGEONMODE::WALK)
    {
        MG_GAME->SetCurSelHero(index);
    }
   
}

void CDungeonUI_HeroInfo::SetPortrait(IMAGE _image)
{
    portrait.m_img = MG_IMAGE->findImage(_image);
}

void CDungeonUI_HeroInfo::SetWeapon(IMAGE _image)
{
    m_weapon.m_img = MG_IMAGE->findImage(_image);

}

void CDungeonUI_HeroInfo::SetArmor(IMAGE _image)
{
    m_armor.m_img = MG_IMAGE->findImage(_image);
}