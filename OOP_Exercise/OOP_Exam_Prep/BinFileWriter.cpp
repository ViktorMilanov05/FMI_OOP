#include "BinFileWriter.h"
#include <fstream>
BinFileWriter::BinFileWriter(const MyString& str) : FileWriter(str)
{
}

void BinFileWriter::write(const int* arr, size_t size) const
{
	std::ofstream ofs(path.c_str(), std::ios::binary);
	if (!ofs.is_open())
		throw std::exception();
	ofs.write(reinterpret_cast<const char*>(arr), size * sizeof(int));
}
