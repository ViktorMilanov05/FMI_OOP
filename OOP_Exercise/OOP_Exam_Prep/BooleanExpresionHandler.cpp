#include "BooleanExpresionHandler.h"
#include "BooleanExpresion.h"
#include "StringView.h"
#include "Negation.h"
#include "Conjuction.h"
#include "Disjunction.h"
#include "Implies.h"
#include "Var.h"

BoolExpresion* expretionFactory(StringView str) {
	str = str.substr(1, str.length() - 2);
	unsigned len = str.length();
	if (len == 1)
		return new Var(str[0]);
	unsigned count = 0;

	for (size_t i = 0; i < len; i++)
	{
		if (str[i] == '(') {
			count++;
		}
		else if (str[i] == ')') {
			count--;
		}
		else if (count == 0) {
			switch (str[i])
			{
			case '!': return new Negation(expretionFactory(str.substr(i + 1, len - i - 1)));
			case '&': return new Conjuction(expretionFactory(str.substr(0, i)),expretionFactory(str.substr(i + 1, len - i - 1)));
			case '|': return new Disjunction(expretionFactory(str.substr(0, i)), expretionFactory(str.substr(i + 1, len - i - 1)));
			case '>': return new Implies(expretionFactory(str.substr(0, i)), expretionFactory(str.substr(i + 1, len - i - 1)));
			default:
				throw std::exception();
			}
		}
	}
}

void BooleanExpresionHandler::copyFrom(const BooleanExpresionHandler& other)
{
	expr = other.expr->clone();
}

void BooleanExpresionHandler::moveFrom(BooleanExpresionHandler&& other)
{
	expr = other.expr;
	other.expr = nullptr;
}

void BooleanExpresionHandler::free()
{
	delete expr;
}

bool BooleanExpresionHandler::checkAll(bool value) const
{
	unsigned varCount = vars.getTrueCount();
	unsigned mask = 1 << varCount;
	for (size_t i = 0; i < mask; i++)
	{
		BoolInterpret curr = vars;
		curr.reduceByMask(i);
		if (expr->eval(curr) != value)
			return false;
	}
	return true;
}

BooleanExpresionHandler::BooleanExpresionHandler(const MyString& str)
{
	expr = expretionFactory(str);
}

BooleanExpresionHandler::BooleanExpresionHandler(const BooleanExpresionHandler& other)
{
	copyFrom(other);
}

BooleanExpresionHandler::BooleanExpresionHandler(BooleanExpresionHandler&& other)
{
	moveFrom(std::move(other));
}

BooleanExpresionHandler& BooleanExpresionHandler::operator=(const BooleanExpresionHandler& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

BooleanExpresionHandler& BooleanExpresionHandler::operator=(BooleanExpresionHandler&& other)
{
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

BooleanExpresionHandler::~BooleanExpresionHandler()
{
	free();
}

bool BooleanExpresionHandler::eval(const BoolInterpret& bi) const
{
	return expr->eval(bi);
}

bool BooleanExpresionHandler::isTaftology() const
{
	return checkAll(true);
}

bool BooleanExpresionHandler::isAlwaysWrong() const
{
	return checkAll(false);
}
