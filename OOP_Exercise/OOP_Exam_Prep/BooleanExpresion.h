#include "BoolInterpretation.h"

struct BoolExpresion {
	BoolExpresion() = default;
	BoolExpresion(const BoolExpresion& other) = delete;
	BoolExpresion& operator=(const BoolExpresion& other) = delete;

	virtual ~BoolExpresion() = default;
	virtual BoolExpresion* clone() const = 0;
	virtual bool eval(const BoolInterpret& interpret) const = 0;
	virtual void populate(BoolInterpret& interpret) const = 0;
};