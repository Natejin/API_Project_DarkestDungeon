#pragma once
#include "CItemEffect.h"
#include "CHero.h"
#include "CParty.h"

class TorchEffect : public CItemEffect
{
public:
	virtual bool ItemEffect()
	{
		if (MG_GAME->GetParty()->getBrightness() != 100)
		{
			if (MG_GAME->GetParty()->getBrightness() + 20 > 100)
			{
				MG_GAME->GetParty()->setBrightness(100);
			}
			else
			{
				MG_GAME->GetParty()->setBrightness(MG_GAME->GetParty()->getBrightness() + 20);
			}
			MG_GAME->GetParty()->setTorch(MG_GAME->GetParty()->getTorch() - 1);
			return true;
		}
		else
		{
			return false;
		}
	}
};

class BandageEffect : public CItemEffect
{
public:
	virtual bool ItemEffect()
	{
		//for (int i = 0; i < MG_GAME->GetHeroes().size(); i++)
		//{
		//	if (MG_GAME->GetHero(i)->isSelected)
		//	{
		//		bool attribute[8]; //stun, blight, bleed, debuff, buff, move, marked, death
		//		//index 2만 0으로 바꿀 수 있도록 setAttribute 수정
		//		//MG_GAME->GetHero(i)->setAttribute();
		//	}
		//}
		return true;
	}
};

class FoodEffect : public CItemEffect
{
public:
	//unable to use food if heroes on battleState
	virtual bool ItemEffect()
	{
		for (int i = 0; i < MG_GAME->GetHeroes().size(); i++)
		{
			if (MG_GAME->GetHero(i)->isSelected)
			{
				MG_GAME->GetHero(i)->setHP(MG_GAME->GetHero(i)->getHP() + MG_RND->getFromIntTo(1, 4));
				MG_GAME->GetParty()->setFood(MG_GAME->GetParty()->getFood() - 1);
				return true;
			}
		}
		return false;
	}
};