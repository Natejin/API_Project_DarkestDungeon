#include "framework.h"
#include "CHeroOnStage_coach.h"

CHeroOnStage_coach::CHeroOnStage_coach()
{
}

CHeroOnStage_coach::~CHeroOnStage_coach()
{
}

HRESULT CHeroOnStage_coach::Init()
{
	return S_OK;
}

void CHeroOnStage_coach::Update(float deltaTime, float worldTime)
{
}

void CHeroOnStage_coach::LateUpdate()
{
}

void CHeroOnStage_coach::BackRender(HDC _hdc)
{
}

void CHeroOnStage_coach::Render(HDC _hdc)
{
}

void CHeroOnStage_coach::FrontRender(HDC _hdc)
{
}

void CHeroOnStage_coach::Release()
{
}

void CHeroOnStage_coach::SetHero()
{

}

CHero* CHeroOnStage_coach::CreateHero(string name, JOB job)
{
	CHero* hero = new CHero();

	int resist[5] = { 30, 30, 30, 30, 30 };
	//stun, blight, bleed, debuff, move
	hero->heroID = heroID++;
	switch (job)
	{
	case JOB::Crusader:
		resist[0] = 40;
		resist[4] = 40;
		hero->Init(JOB::Crusader, resist, 33, 1, 1, 9, 0, 3, 0, 5);
		hero->AddAnimator(IMAGE::Crusader_Idle);
		hero->m_animator->SetAnimeSpeed(5);
		hero->m_animator->AddImageFrame(IMAGE::Crusader_Walk);
		hero->m_animator->AddImageFrame(IMAGE::Crusader_Combat);
		hero->ownSkill.push_back(SKILL::Crusader_Combat_Smite);
		hero->ownSkill.push_back(SKILL::Crusader_Combat_ZealousAccusation);
		hero->ownSkill.push_back(SKILL::Crusader_Combat_StunningBlow);
		hero->ownSkill.push_back(SKILL::Crusader_Heal_BattleHeal);
		break;
	case JOB::Vestal:
		hero->Init(JOB::Vestal, resist, 24, 4, 1, 6, 0, 1, 0, 0);
		hero->AddAnimator(IMAGE::Vestal_Idle);
		hero->m_animator->SetAnimeSpeed(5);
		hero->m_animator->AddImageFrame(IMAGE::Vestal_Idle);
		hero->m_animator->AddImageFrame(IMAGE::Vestal_Idle);
		hero->ownSkill.push_back(SKILL::Vestal_Combat_MaceBash);
		hero->ownSkill.push_back(SKILL::Vestal_Combat_Judgement);
		hero->ownSkill.push_back(SKILL::Vestal_Combat_DazzlingLight);
		hero->ownSkill.push_back(SKILL::Vestal_Heal_DivineComfort);
		break;
	case JOB::PlagueDoctor:
		hero->Init(JOB::PlagueDoctor, resist, 24, 4, 1, 6, 0, 1, 0, 0);
		break;
	case JOB::Highwayman:
		hero->Init(JOB::Highwayman, resist, 24, 4, 1, 6, 0, 1, 0, 0);
		break;
	default:
		break;
	}

	hero->Unable();
	MG_GMOBJ->RegisterObj(hero->GetName(), hero);
	return hero;
}
