#pragma once
#include "Shape.h"
class ShapeCollection {
	Shape** arr = nullptr;
	size_t cap = 0;
	size_t size = 0;

	void copyFrom(const ShapeCollection& other);
	void moveFrom(ShapeCollection&& other);
	void free();
	void resize(size_t newCap);
public:
	ShapeCollection();
	ShapeCollection(const ShapeCollection& other);
	ShapeCollection(ShapeCollection&& other);
	ShapeCollection& operator=(const ShapeCollection& other);
	ShapeCollection& operator=(ShapeCollection&& other);
	~ShapeCollection();

	void add(Shape* shape);
	void add(const Shape& shape);
	double getAreaByInd(size_t ind);
	double getPerByInd(size_t ind);

	const Shape* operator[](size_t ind) const;
};
