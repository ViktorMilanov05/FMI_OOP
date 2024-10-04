#include "BinaryOperation.h"
struct Implies : BinaryOperation {
	Implies(BoolExpresion* left, BoolExpresion* right) : BinaryOperation(left, right) {}
	BoolExpresion* clone() const override;
	bool eval(const BoolInterpret& interpret) const override;
};