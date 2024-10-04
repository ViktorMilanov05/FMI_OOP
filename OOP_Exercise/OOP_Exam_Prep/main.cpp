#include <iostream>
#include "Shape.h"
#include "BooleanExpresionHandler.h"
#include "BoolInterpretation.h"


int main()
{
	BooleanExpresionHandler be("((p)|((q)&(t)))");
	BoolInterpretation bi;
	bi.set('p', true);
	std::cout << be.eval(bi) << std::endl;
	BooleanExpresionHandler be2("((p)|(!(p)))");
	std::cout << be2.isTautology() << std::endl;
}