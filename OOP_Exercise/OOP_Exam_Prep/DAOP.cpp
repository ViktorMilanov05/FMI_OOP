#include "DAOP.h"
#include <iostream>
void DAOP::free()
{
	for (size_t i = 0; i < size; i++)
	{
		delete arr[i];
	}
	delete[] arr;
}

void DAOP::copyFrom(const DAOP& other)
{
	arr = new A * [other.cap];
	cap = other.cap;
	size = other.size;
	for (size_t i = 0; i < cap; i++)
	{
		if (other.arr[i] == nullptr) {
			arr[i] = nullptr;
		}
		else {
			arr[i] = new A(*other.arr[i]);
		}
	}
}

void DAOP::moveFrom(DAOP&& other)
{
	arr = other.arr;
	other.arr = nullptr;
	cap = other.cap;
	size = other.size;
}

void DAOP::resize(size_t newCap)
{
	A** temp = new A * [newCap] {nullptr};
	for (size_t i = 0; i < cap; i++)
	{
		temp[i] = arr[i];
	}
	delete[] arr;
	arr = temp;
	cap = newCap;
}

int DAOP::getFirstFree() const
{
	for (size_t i = 0; i < cap; i++)
	{
		if (arr[i] == nullptr)
			return i;
	}
	return -1;
}

DAOP::DAOP()
{
	cap = 8;
	size = 0;
	arr = new A * [cap] {nullptr};
}

void DAOP::pushAtFirstFree(const A& other)
{
	if (size >= cap)
		resize(cap * 2);
	int firstFree = getFirstFree();
	if (firstFree == -1)
		return;
	arr[firstFree] = new A(other);
	size++;
}

void DAOP::pushAtFirstFree(A&& other)
{
	if (size >= cap)
		resize(cap * 2);
	int firstFree = getFirstFree();
	if (firstFree == -1)
		return;
	arr[firstFree] = new A(std::move(other));
	size++;
}

void DAOP::pop()
{
	if (size == 0)
		return;
	delete arr[size - 1];
	arr[size - 1] = nullptr;
	size--;
}

void DAOP::removeAt(size_t ind)
{
	if (ind >= cap)
		return;
	delete arr[ind];
	arr[ind] = nullptr;
	size--;
}

void DAOP::setAtIndex(const A& other, size_t ind)
{
	if (ind >= cap)
		resize(cap * 2);
	if (arr[ind] == nullptr) {
		arr[ind] = new A(other);
		size++;
	}
	else {
		*arr[ind] = other;
	}
}

void DAOP::setAtIndex(A&& other, size_t ind)
{
	if (ind >= cap)
		resize(cap * 2);
	if (arr[ind] == nullptr) {
		arr[ind] = new A(std::move(other));
		size++;
	}
	else {
		*arr[ind] = std::move(other);
	}
}

bool DAOP::contains(size_t ind) const
{
	return ind < cap && arr[ind] != nullptr;
}

const A& DAOP::operator[](size_t ind) const
{
	return *arr[ind];
}

A& DAOP::operator[](size_t ind)
{
	return *arr[ind];
}
