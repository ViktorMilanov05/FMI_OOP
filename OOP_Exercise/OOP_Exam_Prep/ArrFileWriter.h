#pragma once
#include "FileWriter.h"
class ArrFileWriter : public FileWriter {
public:
	ArrFileWriter(const MyString& other);
	void write(const int* arr, size_t size) const;
};
