#include "ShapeCollection.h"

void ShapeCollection::copyFrom(const ShapeCollection& other)
{
	arr = new Shape * [other.cap];
	for (size_t i = 0; i < other.size; i++)
	{
		arr[i] = other.arr[i]->clone();
	}
	cap = other.cap;
	size = other.size;
}

void ShapeCollection::moveFrom(ShapeCollection&& other)
{
	arr = other.arr;
	other.arr = nullptr;
	cap = other.cap;
	size = other.size;
}

void ShapeCollection::free()
{
	for (size_t i = 0; i < cap; i++)
	{
		delete arr[i];
	}
	delete[] arr;
}

void ShapeCollection::resize(size_t newCap)
{
	Shape** temp = new Shape * [newCap];
	for (size_t i = 0; i < size; i++)
	{
		temp[i] = arr[i];
	}
	delete[] arr;
	arr = temp;
	cap = newCap;
}

ShapeCollection::ShapeCollection()
{
	cap = 8;
	arr = new Shape * [cap] {nullptr};
	size = 0;
}

ShapeCollection::ShapeCollection(const ShapeCollection& other)
{
	copyFrom(other);
}

ShapeCollection::ShapeCollection(ShapeCollection&& other)
{
	moveFrom(std::move(other));
}

ShapeCollection& ShapeCollection::operator=(const ShapeCollection& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

ShapeCollection& ShapeCollection::operator=(ShapeCollection&& other)
{
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

ShapeCollection::~ShapeCollection()
{
	free();
}

void ShapeCollection::add(Shape* shape)
{
	if (size >= cap)
		resize(cap * 2);
	arr[size++] = shape;
	shape = nullptr;
}

void ShapeCollection::add(const Shape& shape)
{
	Shape* cloned = shape.clone();
	add(cloned);
}

double ShapeCollection::getAreaByInd(size_t ind)
{
	return arr[ind]->getArea();
}

double ShapeCollection::getPerByInd(size_t ind)
{
	return arr[ind]->getPer();
}

const Shape* ShapeCollection::operator[](size_t ind) const
{
	return arr[ind];
}
