#include "GraduatedStudent.h"
#include <iostream>
#define _CRT_SECURE_NO_WARNINGS

void GraduatedStudent::copyFrom(const GraduatedStudent& other)
{
	name = new char[strlen(other.name) + 1];
	//strcpy(name, other.name);
	grades = new int[other.gradesCount];
	for (size_t i = 0; i < gradesCount; i++)
	{
		grades[i] = other.grades[i];
	}
	gradesCount = other.gradesCount;
	//strcpy(quote, other.quote);
}

void GraduatedStudent::moveFrom(GraduatedStudent&& other)
{
	name = other.name;
	other.name = nullptr;
	grades = other.grades;
	other.grades = nullptr;
	gradesCount = other.gradesCount;
	//strcpy(quote, other.quote);
}

void GraduatedStudent::free()
{
	delete[] name;
	delete[] grades;
	name = nullptr;
	grades = nullptr;
	//strcpy(quote, "");
	gradesCount = 0;
}

GraduatedStudent::GraduatedStudent(const char* name, const int* grades, size_t count, const char* quote)
{
	setName(name);
	setGrades(grades, count);
	setQuote(quote);
}

GraduatedStudent::GraduatedStudent(const GraduatedStudent& other)
{
	copyFrom(other);
}

GraduatedStudent::GraduatedStudent(GraduatedStudent&& other)
{
	moveFrom(std::move(other));
}

GraduatedStudent& GraduatedStudent::operator=(const GraduatedStudent& other)
{
	if (this != (&other)) {
		free();
		copyFrom(other);
	}
	return *this;
}

GraduatedStudent& GraduatedStudent::operator=(GraduatedStudent&& other)
{
	if (this != (&other)) {
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

GraduatedStudent::~GraduatedStudent()
{
	free();
}

const char* GraduatedStudent::getName() const
{
	return name;
}

const int* GraduatedStudent::getGrades() const
{
	return grades;
}

size_t GraduatedStudent::getGradesCount() const
{
	return gradesCount;
}

const char* GraduatedStudent::getQuote() const
{
	return quote;
}

void GraduatedStudent::setName(const char* name)
{
	if (!name || name == this->name)
		return;
	delete[] name;
	this->name = new char[strlen(name) + 1];
	//strcpy(this->name, name);
}

void GraduatedStudent::setGrades(const int* grades, size_t count)
{
	if (!grades || grades == this->grades)
		return;
	delete[] grades;
	this->grades = new int[count];
	for (size_t i = 0; i < count; i++)
	{
		this->grades[i] = grades[i];
	}
	gradesCount = count;
}

void GraduatedStudent::setQuote(const char* quote)
{
	//if (quote && strlen(quote) <= 30)
		//strcpy(this->quote, quote);
}
