#pragma once
#include "MyString.h"
#include <iostream>
class FileReader {
protected:
	MyString path;
public:
	FileReader(const MyString& filePath);
	virtual int* read(size_t& size) const = 0;
	virtual ~FileReader() = default;
};
