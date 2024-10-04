#include "ArrFileWriter.h"
#include <fstream>
ArrFileWriter::ArrFileWriter(const MyString& other) : FileWriter(other)
{
}

void ArrFileWriter::write(const int* arr, size_t size) const
{
	std::ofstream ofs(path.c_str());
	if (!ofs.is_open())
		throw std::exception();
	ofs << '[';
	for (size_t i = 0; i < size; i++)
	{
		ofs << arr[i];
		if (i < size - 1) {
			ofs << ' ';
		}
	}
	ofs << ']';
}
