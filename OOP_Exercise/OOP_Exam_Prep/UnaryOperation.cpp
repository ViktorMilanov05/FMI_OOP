#include "UnaryOperation.h"

void UnaryOperation::populate(BoolInterpret& interpret) const
{
	expr->populate(interpret);
}

UnaryOperation::~UnaryOperation()
{
	delete expr;
}
