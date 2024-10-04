#include "ImmputableString.h"
#include <string.h>

StringPool ImmutableString::_pool;

void ImmutableString::copyFrom(const ImmutableString& other)
{
	str = _pool.add(other.str);
	count = other.count;
}

void ImmutableString::free()
{
	_pool.remove(str);
	str = nullptr;
}

void ImmutableString::moveFrom(ImmutableString&& other)
{
	str = other.str;
	other.str = nullptr;
	count = other.count;
}

ImmutableString::ImmutableString(const char* name)
{
	str = _pool.add(name);
	count = strlen(str);
}

const char& ImmutableString::operator[](unsigned ind) const
{
	return str[ind];
}
