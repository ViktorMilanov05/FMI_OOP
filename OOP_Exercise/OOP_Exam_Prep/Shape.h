#pragma once
#include <iostream>
class Shape {
protected:
	struct point
	{
		point() :x(0), y(0) {}
		point(int x, int y) :x(x), y(y) {}
		int x;
		int y;
		double getDist(const point& other) const
		{
			int dx = x - other.x;
			int dy = y - other.y;

			return sqrt(dx * dx + dy * dy);
		}
	};
	const point& getPoint(size_t ind) const;
private:
	point* points;
	size_t count;

	void copyFrom(const Shape& other);
	void moveFrom(Shape&& other);
	void free();

public:
	Shape(size_t count);
	void setPoint(size_t ind, int x, int y);
	virtual ~Shape();
	virtual double getPer() const;
	virtual double getArea() const = 0;
	virtual Shape* clone() const = 0;
	virtual bool intersectWith(const Shape* other) const = 0;

	virtual bool intersectTriangle(const Shape* other) const = 0;
	virtual bool intersectRectangle(const Shape* other) const = 0;
	virtual bool intersectCircle(const Shape* other) const = 0;
};
