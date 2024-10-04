#include "Var.h"

bool Var::eval(const BoolInterpret& interpret) const
{
	return interpret(ch);
}

void Var::populate(BoolInterpret& interpret) const
{
	interpret.set(ch, true);
}

BoolExpresion* Var::clone() const
{
	return new Var(ch);
}
