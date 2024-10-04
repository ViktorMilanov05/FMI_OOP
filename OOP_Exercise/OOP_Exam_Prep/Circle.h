#pragma once
#include "Shape.h"
class Circle : public Shape {
	double r;
public:
	Circle(int x1, int y1, double r);
	double getPer() const override;
	double getArea() const override;
	Shape* clone() const override;
	bool intersectWith(const Shape* other) const override;
	bool intersectTriangle(const Shape* other) const override;
	bool intersectRectangle(const Shape* other) const override;
	bool intersectCircle(const Shape* other) const override;
};