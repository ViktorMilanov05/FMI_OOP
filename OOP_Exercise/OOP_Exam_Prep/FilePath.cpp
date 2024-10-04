#include "FilePath.h"
#include <iostream>

FilePath::FilePath(const MyString& str)
{
	const char* begin = str.c_str();
	const char* end = str.c_str() + std::strlen(str.c_str());
	const char* iter = end;
	while (iter != begin && *iter != '.') {
		iter--;
	}
	//name = str.substr(0, iter - begin);
	//extention = str.substr(iter-begin, end - iter);
}

const char* FilePath::getName() const
{
	return name.c_str();
}

const char* FilePath::getExt() const
{
	return extention.c_str();
}
