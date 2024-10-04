#pragma once
#include "FileReader.h"
class BinFileReader : public FileReader {
	static int getFileSize(std::istream& is);
public:
	BinFileReader(const MyString& str);
	int* read(size_t& size) const override;
};
