#include "framework.h"
#include "Info_Item.h"

bool CInfo_Item::IsFull()
{
	if (m_count < maxCount)
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool CInfo_Item::useItem()
{
	if (isUsable)
	{
		return m_itemEffect->ItemEffect();
	}
	else return false;
}

void CInfo_Item::DumpItem(int dumpCount)
{
	m_itemEffect->DumpItem(dumpCount);
}
