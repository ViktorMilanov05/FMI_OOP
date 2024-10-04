#include "MyString.h"
static unsigned roundToPowerOfTwo(unsigned v) //static! -> will be discused in the next lecture
{
    v--;
    v |= v >> 1;
    v |= v >> 2;
    v |= v >> 4;
    v |= v >> 8;
    v |= v >> 16;
    v++;
    return v;
}

static unsigned getNeededCap(unsigned size) {
    return std::max(roundToPowerOfTwo(size + 1), 16u);
}

void MyString::resize(size_t newCap)
{
    char* temp = new char[newCap + 1];
    strcpy(temp, str);
    delete[] str;
    str = temp;
    cap = newCap;
}

void MyString::copyFrom(const MyString& other)
{
    cap = other.cap;
    size = other.size;
    str = new char[other.cap];
    strcpy(str, other.str);
}

void MyString::moveFrom(MyString&& other)
{
    str = other.str;
    other.str = nullptr;
    cap = other.cap;
    size = other.size;
}

void MyString::free()
{
    delete[] str;
    cap = size = 0;
}

MyString::MyString(size_t len) {
    size = 0;
    cap = getNeededCap(size);
    str = new char[cap];
    str[0] = '\n';
}

MyString::MyString() : MyString("")
{
}

MyString::MyString(const char* str)
{
    size = strlen(str);
    cap = getNeededCap(size);
    str = new char[cap];
    strcpy(this->str, str);
}

MyString::MyString(const MyString& other)
{
    copyFrom(other);
}

MyString::MyString(MyString&& other)
{
    moveFrom(std::move(other));
}

MyString& MyString::operator=(const MyString& other)
{
    if (this != &other) {
        free();
        copyFrom(other);
    }
    return *this;
}

MyString& MyString::operator=(MyString&& other)
{
    if (this != &other) {
        free();
        moveFrom(std::move(other));
    }
    return *this;
}

MyString::~MyString()
{
    free();
}

MyString& MyString::operator+=(const MyString& str)
{
    if (size + str.size + 1 > cap)
        resize(getNeededCap(size + str.size));
    strncat(this->str, str.str,str.size);
    size += str.size;
    return *this;
}

char& MyString::operator[](size_t ind)
{
    return str[ind];
}

const char& MyString::operator[](size_t ind) const
{
    return str[ind];
}

std::ostream& operator<<(std::ostream& os, const MyString& str)
{
    return os << str.str;
}

std::istream& operator>>(std::istream& is, MyString& str)
{
    char buff[1024];
    is >> buff;
    size_t len = strlen(buff);
    if (len > str.cap)
        str.resize(len);
    strcpy(str.str, buff);
    str.size = len;
    return is;
}

MyString operator+(const MyString& lhs, const MyString& rhs)
{
    MyString res = MyString(lhs.size + rhs.size);
    res += lhs;
    res += rhs;
    return res;
}
size_t MyString::getCap() const
{
    return cap - 1;
}

size_t MyString::getSize() const
{
    return size;
}

const char* MyString::c_str() const
{
    return str;
}
