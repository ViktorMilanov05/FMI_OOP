#include "StringPool.h"
#include <iostream>

void StringPool::free()
{
	for (size_t i = 0; i < count; i++)
	{
		delete[] strings[i].str;
	}
	delete[] strings;
}

void StringPool::copyFrom(const StringPool& other)
{
	strings = new StringRecords[other.cap];
	for (size_t i = 0; i < other.count; i++)
	{
		//strcpy(strings[i].str, other.strings[i].str);
		//strings[i].refCount = other.strings[i].refCount;
	}
	cap = other.cap;
	count = other.count;
}

void StringPool::moveFrom(StringPool& other)
{
	strings = other.strings;
	delete[] other.strings;
	count = other.count;
	cap = other.cap;
}

void StringPool::resize(unsigned newCap)
{
	StringRecords* temp = new StringRecords[newCap];
	for (size_t i = 0; i < count; i++)
	{
		temp[i] = strings[i];
	}
	delete[] strings;
	strings = temp;
	cap = newCap;
}

void StringPool::removeRecord(unsigned ind)
{
	std::swap(strings[ind], strings[count - 1]);
	delete[] strings[count - 1].str;
	strings[count - 1].str = nullptr;
	strings[count - 1].refCount = 0;
	count--;
}

void StringPool::allocateRecord(const char* str)
{
	if (count == cap)
		resize(cap * 2);
	unsigned ind = count++;
	strings[ind].str = new char[strlen(str) + 1];
	//strcpy(strings[ind].str, str);
	strings[ind].refCount = 0;
}

int StringPool::findRecordIndex(const char* str) const
{
	for (size_t i = 0; i < count; i++)
	{
		if (std::strcmp(str, strings[i].str) == 0)
			return i;
	}
	return -1;
}

StringPool::StringPool()
{
	cap = 8;
	count = 0;
	strings = new StringRecords[cap];
}

void StringPool::remove(const char* str)
{
	int ind = findRecordIndex(str);
	if (ind == -1)
		throw std::exception("error");
	strings[ind].refCount--;
	if (strings[ind].refCount == 0) {
		removeRecord(ind);
	}
}

const char* StringPool::add(const char* str)
{
	int ind = findRecordIndex(str);
	if (ind != -1) {
		strings[ind].refCount++;
		return strings[ind].str;
	}
	else {
		allocateRecord(str);
		strings[count - 1].refCount++;
		return strings[count - 1].str;
	}
}
