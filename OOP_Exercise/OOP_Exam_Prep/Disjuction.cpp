#include "Disjunction.h"

BoolExpresion* Disjunction::clone() const
{
	return new Disjunction(left->clone(), right->clone());
}

bool Disjunction::eval(const BoolInterpret& interpret) const
{
	return left->eval(interpret) || right->eval(interpret);
}
