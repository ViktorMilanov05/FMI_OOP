#include "Shape.h"

const Shape::point& Shape::getPoint(size_t ind) const
{
	if (ind >= count)
		throw std::exception("f");
	return points[ind];
}

void Shape::copyFrom(const Shape& other)
{
	points = new Shape::point[other.count];
	for (size_t i = 0; i < other.count; i++)
	{
		points[i] = other.points[i];
	}
	count = other.count;
}

void Shape::moveFrom(Shape&& other)
{
	points = other.points;
	other.points = nullptr;
	count = other.count;
}

void Shape::free()
{
	delete[] points;
	points = nullptr;
}

Shape::Shape(size_t count)
{
	this->points = new Shape::point[count];
	this->count = count;
}

void Shape::setPoint(size_t ind, int x, int y)
{
	if (ind >= count)
		throw std::exception();
	points[ind].x = x;
	points[ind].y = y;
}

Shape::~Shape()
{
	free();
}

double Shape::getPer() const
{
	if (count < 3)
		return 0;
	double per = 0;
	for (size_t i = 0; i < count - 1; i++)
	{
		per += points[i].getDist(points[i + 1]);
	}
	return per + points[count-1].getDist(points[1]);
}
