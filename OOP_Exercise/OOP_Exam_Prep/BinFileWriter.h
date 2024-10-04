#pragma once
#include "FileWriter.h"
class BinFileWriter : public FileWriter {
public:
	BinFileWriter(const MyString& str);
	void write(const int* arr, size_t size) const override;
};
