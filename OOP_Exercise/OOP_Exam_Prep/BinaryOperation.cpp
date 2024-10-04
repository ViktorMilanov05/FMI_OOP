#include "BinaryOperation.h"

BinaryOperation::~BinaryOperation()
{
	delete left;
	delete right;
}

void BinaryOperation::populate(BoolInterpret& interpret) const
{
	left->populate(interpret);
	right->populate(interpret);
}
