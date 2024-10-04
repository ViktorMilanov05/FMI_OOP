#include "Implies.h"

BoolExpresion* Implies::clone() const
{
	return new Implies(left->clone(), right->clone());
}

bool Implies::eval(const BoolInterpret& interpret) const
{
	return !left->eval(interpret) || right->eval(interpret);
}
