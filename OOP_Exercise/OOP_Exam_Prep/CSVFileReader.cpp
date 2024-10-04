#include "CSVFileReader.h"
#include <fstream>

int CSVFileReader::getCharCount(std::istream& is, char ch) {
	int curr = is.tellg();
	is.seekg(0, std::ios::beg);
	int count = 0;
	while (true) {
		char current = is.get();
		if (is.eof())
			break;
		if (current == ch)
			count++;
	}
	is.clear();
	is.seekg(curr);
	return count;
}

CSVFileReader::CSVFileReader(const MyString& str) : FileReader(str)
{
}

int* CSVFileReader::read(size_t& size) const
{
	std::ifstream ifs(path.c_str());
	if (!ifs.is_open())
		throw std::exception();
	size = getCharCount(ifs,',') + 1;
	int* result = new int[size];

	for (size_t i = 0; i < size; i++)
	{
		ifs >> result[i];
		ifs.ignore();
	}
	return result;
}
