#include "framework.h"
#include "Info_Hero.h"

Info_Hero::Info_Hero()
{

}

Info_Hero::~Info_Hero()
{
}

IMAGE Info_Hero::GetArmor(int i)
{
    return armor[i];
}

IMAGE Info_Hero::GetWeapon(int i)
{
    return weapon[i];
}

Image* Info_Hero::GetTrinketL()
{
    return MG_IMAGE->findImage(lTrinket);
}

Image* Info_Hero::GetTrinketR()
{
    return MG_IMAGE->findImage(rTrinket);
}

void Info_Hero::Release()
{
}
