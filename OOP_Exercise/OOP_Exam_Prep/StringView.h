#pragma once
#include "MyString.h"
class StringView {
	const char* begin;
	const char* end;

public:
	StringView(const char* beg, const char* end);
	StringView(const MyString& other);
	char operator[](unsigned ind) const;
	StringView substr(unsigned from, unsigned to);
	size_t length() const;

	friend std::ostream& operator<<(std::ostream os, const StringView& str);
};
