#pragma once
struct A {
	int a = 3;
	int b = 4;
};
class DAOP {
	A** arr = nullptr;
	size_t size = 0;
	size_t cap = 0;

	void free();
	void copyFrom(const DAOP& other);
	void moveFrom(DAOP&& other);
	void resize(size_t newCap);
	int getFirstFree() const;

public:
	DAOP();

	void pushAtFirstFree(const A& other);
	void pushAtFirstFree(A&& other);
	void pop();
	void removeAt(size_t ind);
	void setAtIndex(const A& other,size_t ind);
	void setAtIndex(A&& other, size_t ind);
	bool contains(size_t ind) const;
	const A& operator[](size_t ind) const;
	A& operator[](size_t ind);
};