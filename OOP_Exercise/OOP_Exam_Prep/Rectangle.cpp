#include "Rectangle.h"

Rectangle::Rectangle(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) : Shape(4)
{
	setPoint(0,x1, y1);
	setPoint(1,x2, y2);
	setPoint(2,x3, y3);
	setPoint(3,x4, y4);
}

double Rectangle::getArea() const
{
	const Shape::point& p1 = getPoint(0);
	const Shape::point& p2 = getPoint(0);
	const Shape::point& p3 = getPoint(0);
	return p1.getDist(p2) * p1.getDist(p3);
}

Shape* Rectangle::clone() const
{
	return new Rectangle (*this);
}
bool Rectangle::intersectWith(const Shape* other) const
{
	return other->intersectRectangle(other);
}

bool Rectangle::intersectTriangle(const Shape* other) const
{
	std::cout << "Rectangle and triangle";
	return true;
}

bool Rectangle::intersectRectangle(const Shape* other) const
{
	std::cout << "Rectangle and rectangle";
	return true;
}

bool Rectangle::intersectCircle(const Shape* other) const
{
	std::cout << "Rectangle and circle";
	return true;
}
