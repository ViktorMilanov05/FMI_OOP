#include "UnaryOperation.h"
struct Negation : public UnaryOperation {
	Negation(BoolExpresion* expr) : UnaryOperation(expr) {};
	BoolExpresion* clone() const override;
	bool eval(const BoolInterpret& interpret) const override;
};