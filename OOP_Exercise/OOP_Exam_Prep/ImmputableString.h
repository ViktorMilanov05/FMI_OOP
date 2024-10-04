#pragma once
#include "StringPool.h"
class ImmutableString {
	static StringPool _pool;
	const char* str;
	unsigned count;

	void copyFrom(const ImmutableString& other);
	void free();
	void moveFrom(ImmutableString&& other);

public:
	ImmutableString() = default;
	ImmutableString(const char* name);

	const char& operator[](unsigned ind) const;
	char& operator[](unsigned ind);
};
