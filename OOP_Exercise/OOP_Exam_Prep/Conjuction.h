#include "BinaryOperation.h"
struct Conjuction : BinaryOperation {
	Conjuction(BoolExpresion* left, BoolExpresion* right) : BinaryOperation(left, right){}
	BoolExpresion* clone() const override;
	bool eval(const BoolInterpret& interpret) const override;
};