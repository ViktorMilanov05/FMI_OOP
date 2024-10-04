#include "BooleanExpresion.h"

struct UnaryOperation : public BoolExpresion {
	UnaryOperation(BoolExpresion* expr) : expr(expr) {};
	void populate(BoolInterpret& interpret) const override;
	~UnaryOperation();
protected:
	BoolExpresion* expr;
};