#include "StringView.h"

StringView::StringView(const char* beg, const char* end) : begin(beg), end(end)
{
}

StringView::StringView(const MyString& other)
{
	begin = other.c_str();
	end = other.c_str() + other.getSize();
}

char StringView::operator[](unsigned ind) const
{
	return begin[ind];
}

StringView StringView::substr(unsigned from, unsigned len)
{
	if (begin + from + len > end)
		throw std::exception();
	return StringView(begin + from, begin + from + len);
}

size_t StringView::length() const
{
	return end - begin;
}

std::ostream& operator<<(std::ostream os, const StringView& str)
{
	const char* iter = str.begin;
	while (iter != str.end) {
		os << *iter;
		iter++;
	}
	return os;
}
