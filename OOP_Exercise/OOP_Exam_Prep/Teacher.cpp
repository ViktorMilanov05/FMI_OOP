#include "Teacher.h"

static char** copySubjects(const char* const* subjects, size_t count) {
	char** result = new char* [count];
	for (size_t i = 0; i < count; i++)
	{
		result[i] = new char[strlen(subjects[i]) + 1];
		//strcpy(result[i], subjects[i]);
	}
	return result;
}

void Teacher::copyFrom(const Teacher& other)
{
	subjects = copySubjects(other.subjects, other.count);
	count = other.count;
}

void Teacher::moveFrom(Teacher&& other)
{
	subjects = other.subjects;
	other.subjects = nullptr;
	count = other.count;
}

void Teacher::free()
{
	for (size_t i = 0; i < count; i++)
	{
		delete[] subjects[i];
	}
	delete[] subjects;
}

Teacher::Teacher(const char* name, int age, const char* const* subjects, size_t count) : Person(name, age)
{
	this->subjects = copySubjects(subjects, count);
	this->count = count;
}

Teacher::Teacher(const Teacher& other) : Person(other)
{
	copyFrom(other);
}

Teacher::Teacher(Teacher&& other) : Person(std::move(other))
{
	moveFrom(std::move(other));
}

Teacher& Teacher::operator=(const Teacher& other)
{
	if (this != &other) {
		Person::operator=(other);
		free();
		copyFrom(other);
	}
	return *this;
}

Teacher& Teacher::operator=(Teacher&& other)
{
	if (this != &other) {
		Person::operator=(std::move(other));
		free();
		copyFrom(std::move(other));
	}
	return *this;
}

Teacher::~Teacher()
{
	free();
}
