#pragma once
#include "FileReader.h"
class CSVFileReader :public FileReader {
	static int getCharCount(std::istream& is, char ch);
public:
	CSVFileReader(const MyString& str);
	int* read(size_t& size) const override;
};
