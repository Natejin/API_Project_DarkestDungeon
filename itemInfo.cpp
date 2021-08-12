#include "framework.h"

bool CItemInfo::IsFull()
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
