#include "BinFileReader.h"
#include <fstream>

int BinFileReader::getFileSize(std::istream& is)
{
	int curr = is.tellg();
	is.seekg(0, std::ios::end);
	int res = is.tellg();
	is.seekg(curr);
	is.clear();
	return res;
}

BinFileReader::BinFileReader(const MyString& str) : FileReader(str) {

}

int* BinFileReader::read(size_t& size) const {
	std::ifstream ifs(path.c_str(), std::ios::binary);
	if (!ifs.is_open())
		throw std::exception();
	size = getFileSize(ifs) / sizeof(int);
	int* result = new int[size];
	ifs.read(reinterpret_cast<char*>(result), size * sizeof(int));
	return result;
}