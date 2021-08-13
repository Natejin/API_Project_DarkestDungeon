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
