#pragma once
#include "FileReader.h"
class ArrFileReader : public FileReader {
	static int getCharCount(std::istream& is, char ch);
public:
	ArrFileReader(const MyString& other);
	int* read(size_t& size) const override;
};