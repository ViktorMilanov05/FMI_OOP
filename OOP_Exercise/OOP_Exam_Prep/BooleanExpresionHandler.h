#pragma once
#include "BooleanExpresion.h"
#include "BoolInterpretation.h"
#include "MyString.h"

class BooleanExpresionHandler {
	BoolExpresion* expr;
	BoolInterpret vars;

	void copyFrom(const BooleanExpresionHandler& other);
	void moveFrom(BooleanExpresionHandler&& other);
	void free();
	bool checkAll(bool value) const;

public:
	BooleanExpresionHandler() = default;
	BooleanExpresionHandler(const MyString& str);
	BooleanExpresionHandler(const BooleanExpresionHandler& other);
	BooleanExpresionHandler(BooleanExpresionHandler&& other);
	BooleanExpresionHandler& operator=(const BooleanExpresionHandler& other);
	BooleanExpresionHandler& operator=(BooleanExpresionHandler&& other);
	~BooleanExpresionHandler();

	bool eval(const BoolInterpret& bi) const;
	bool isTaftology() const;
	bool isAlwaysWrong() const;
};