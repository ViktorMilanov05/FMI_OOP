#include "BooleanExpresion.h"

struct Var :public BoolExpresion {
	Var(char ch) : ch(ch) {};
	bool eval(const BoolInterpret& interpret) const override;
	void populate(BoolInterpret& interpret) const override;
	BoolExpresion* clone() const override;
private:
	char ch;
};