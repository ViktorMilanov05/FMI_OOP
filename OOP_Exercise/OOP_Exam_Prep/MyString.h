#pragma once
#include <iostream>
class MyString {
	char* str = nullptr;
	size_t size = 0;
	size_t cap = 0;

	void resize(size_t newCap);
	void copyFrom(const MyString& other);
	void moveFrom(MyString&& other);
	void free();
	explicit MyString(size_t len);
public:
	MyString();
	MyString(const char* str);
	MyString(const MyString& other);
	MyString(MyString&& other);
	MyString& operator=(const MyString& other);
	MyString& operator=(MyString&& other);
	~MyString();

	const char* c_str() const;
	size_t getSize() const;
	size_t getCap() const;
	MyString& operator+=(const MyString& str);
	char& operator[](size_t ind);
	const char& operator[](size_t ind) const;

	friend std::ostream& operator<<(std::ostream& os, const MyString& str);
	friend std::istream& operator>>(std::istream& is, MyString& str);
	friend MyString operator+(const MyString& lhs, const MyString& rhs);
};