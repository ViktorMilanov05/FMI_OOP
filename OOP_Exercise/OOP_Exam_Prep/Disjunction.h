#include "BinaryOperation.h"
struct Disjunction : BinaryOperation {
	Disjunction(BoolExpresion* left, BoolExpresion* right) : BinaryOperation(left, right) {}
	BoolExpresion* clone() const override;
	bool eval(const BoolInterpret& interpret) const override;
};