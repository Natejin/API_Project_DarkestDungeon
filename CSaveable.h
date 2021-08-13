#pragma once
#include "singleton.h"

template <typename T>
class CSaveable : public Singleton<T>
{
public:
	virtual void Save();
	virtual void Load();
};

template<typename T>
inline void CSaveable<T>::Save()
{
}

template<typename T>
inline void CSaveable<T>::Load()
{
}
