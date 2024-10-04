#include "FibCache.h"
#include <exception>

FibCache::FibCache(unsigned nullValue)
{
	for (size_t i = 0; i < N; i++)
	{
		values[i] = nullValue;
	}
	this->nullValue = nullValue;
}

void FibCache::add(unsigned key, unsigned value)
{
	if (value == nullValue)
		return;
	values[key] = value;
}

bool FibCache::contains(unsigned key)
{
	return values[key] != nullValue;
}

unsigned FibCache::getValue(unsigned key)
{
	if (!contains(key))
		throw std::exception("This do not have value");
	return values[key];
}
