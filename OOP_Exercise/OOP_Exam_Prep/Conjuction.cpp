#include "Conjuction.h"

BoolExpresion* Conjuction::clone() const
{
	return new Conjuction(left->clone(), right->clone());
}

bool Conjuction::eval(const BoolInterpret& interpret) const
{
	return left->eval(interpret) && right->eval(interpret);
}
