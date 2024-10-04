#include "BooleanExpresion.h"
struct BinaryOperation : public BoolExpresion {
	BinaryOperation(BoolExpresion* left, BoolExpresion* right) : left(left), right(right) {};
	~BinaryOperation();
	void populate(BoolInterpret& interpret) const override;
protected:
	BoolExpresion* left;
	BoolExpresion* right;
};