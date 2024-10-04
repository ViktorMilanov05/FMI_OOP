#pragma once
#include "Shape.h"
class Triangle : public Shape {
public:
	Triangle(int x1, int y1, int x2, int y2, int x3, int y3);
	double getArea() const override;
	Shape* clone() const override;
	bool intersectWith(const Shape* other) const override;
	bool intersectTriangle(const Shape* other) const override;
	bool intersectRectangle(const Shape* other) const override;
	bool intersectCircle(const Shape* other) const override;
};