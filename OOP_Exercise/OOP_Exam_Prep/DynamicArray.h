#pragma once
struct A {
	int a = 3;
	int b = 4;
};
class DynamicArray {
	A* arr;
	size_t size;
	size_t cap;

	void free();
	void copyFrom(const DynamicArray& other);
	void moveFrom(DynamicArray&& other);
	void resize(size_t newCap);

public:
	DynamicArray();
	DynamicArray(size_t len);

	void pushBack(const A& el);
	void pushBack(A&& el);
	void pop();
	void setAtIndex(const A& el, size_t ind);
	void setAtIndex(A&& el, size_t ind);

	const A& operator[](unsigned ind) const;
	A& operator[](unsigned ind);
};