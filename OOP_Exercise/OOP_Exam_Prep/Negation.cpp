#include "Negation.h"

BoolExpresion* Negation::clone() const
{
	return new Negation(this->expr);
}

bool Negation::eval(const BoolInterpret& interpret) const
{
	return !expr->eval(interpret);
}
