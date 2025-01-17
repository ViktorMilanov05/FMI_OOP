#include "CSVFileWriter.h"
#include <fstream>

CSVFileWriter::CSVFileWriter(const MyString& str) : FileWriter(str)
{
}

void CSVFileWriter::write(const int* arr, size_t size) const
{
	std::ofstream ofs(path.c_str());
	if (!ofs.is_open())
		throw std::exception();
	for (size_t i = 0; i < size; i++)
	{
		ofs << arr[i];
		if (i < size - 1)
			ofs << ", ";
	}
}
