#include "DynamicArray.h"
#include <iostream>

static unsigned roundToPowerOfTwo(unsigned v) //static! -> will be discused in the next lecture
{
	v--;
	v |= v >> 1;
	v |= v >> 2;
	v |= v >> 4;
	v |= v >> 8;
	v |= v >> 16;
	v++;
	return v;
}

void DynamicArray::free()
{
	delete[] arr;
	arr = nullptr;
	size = cap =0;
}

void DynamicArray::copyFrom(const DynamicArray& other)
{
	arr = new A[other.cap];
	cap = other.cap;
	size = other.size;
	for (size_t i = 0; i < size; i++)
	{
		arr[i] = other.arr[i];
	}
}

void DynamicArray::moveFrom(DynamicArray&& other)
{
	arr = other.arr;
	other.arr = nullptr;
	cap = other.cap;
	size = other.size;
}

void DynamicArray::resize(size_t newCap)
{
	A* temp = arr;
	arr = new A[newCap];
	for (size_t i = 0; i < size; i++)
	{
		arr[i] = temp[i];
	}
	cap = newCap;
	delete[] temp;
}

DynamicArray::DynamicArray() : DynamicArray(8)
{
}

DynamicArray::DynamicArray(size_t len) : size(0)
{
	cap = roundToPowerOfTwo(len);
	arr = new A[cap];

}

void DynamicArray::pushBack(const A& el)
{
	if (size >= cap)
		resize(cap * 2);
	arr[size++] = el;
}

void DynamicArray::pushBack(A&& el)
{
	if (size >= cap)
		resize(cap * 2);
	arr[size++] = std::move(el);
}

void DynamicArray::pop()
{
	if (size) {
		size--;
	}
	else {
		throw std::exception("Empty");
	}
}

void DynamicArray::setAtIndex(const A& el, size_t ind)
{
	if (ind >= size)
		throw std::exception("Out of bounds");
	arr[ind] = el;
}

void DynamicArray::setAtIndex(A&& el, size_t ind)
{
	if (ind >= size)
		throw std::exception("Out of bounds");
	arr[ind] = std::move(el);
}

const A& DynamicArray::operator[](unsigned ind) const
{
	if (ind > size)
		throw std::exception("out of range");
	return arr[ind];
}

A& DynamicArray::operator[](unsigned ind)
{
	if (ind > size)
		throw std::exception("out of range");
	return arr[ind];
}
