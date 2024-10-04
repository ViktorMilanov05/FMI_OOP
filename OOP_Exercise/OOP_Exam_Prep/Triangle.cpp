#include "Triangle.h"
#include <iostream>
Triangle::Triangle(int x1, int y1, int x2, int y2, int x3, int y3):Shape(3)
{
	setPoint(0,x1, y1);
	setPoint(1,x2, y2);
	setPoint(2,x3, y3);
}

double Triangle::getArea() const
{
	const Shape::point& p1 = getPoint(0);
	const Shape::point& p2 = getPoint(1);
	const Shape::point& p3 = getPoint(2);
	int p = (p1.getDist(p2) + p1.getDist(p3) + p2.getDist(p3)) / 2;
	return sqrt(p * (p- p1.getDist(p2)) * (p - p1.getDist(p3)) * (p - p2.getDist(p3)));
}

Shape* Triangle::clone() const
{
	return new Triangle(*this);
}

bool Triangle::intersectWith(const Shape* other) const
{
	return other->intersectTriangle(other);
}

bool Triangle::intersectTriangle(const Shape* other) const
{
	std::cout << "Triangle and triangle";
	return true;
}

bool Triangle::intersectRectangle(const Shape* other) const
{
	std::cout << "Triangle and rectangle";
	return true;
}

bool Triangle::intersectCircle(const Shape* other) const
{
	std::cout << "Triangle and circle";
	return true;
}
