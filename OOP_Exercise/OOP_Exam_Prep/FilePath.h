#pragma once
#include "MyString.h"
class FilePath {
	MyString name;
	MyString extention;
public:
	FilePath(const MyString& str);
	const char* getName() const;
	const char* getExt() const;
};
