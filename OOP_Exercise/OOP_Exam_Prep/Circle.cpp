#include "Circle.h"

Circle::Circle(int x1, int y1, double r) : Shape(1)
{
	setPoint(0, x1, y1);
	this->r = r;
}

double Circle::getPer() const
{
	return 3.14 * r * 2;
}

double Circle::getArea() const
{
	return 3.14 * r * r;
}

Shape* Circle::clone() const
{
	return new Circle(*this);
}
bool Circle::intersectWith(const Shape* other) const
{
	return other->intersectCircle(other);
}

bool Circle::intersectTriangle(const Shape* other) const
{
	std::cout << "Circle and triangle";
	return true;
}

bool Circle::intersectRectangle(const Shape* other) const
{
	std::cout << "Circle and rectangle";
	return true;
}

bool Circle::intersectCircle(const Shape* other) const
{
	std::cout << "Circle and circle";
	return true;
}
