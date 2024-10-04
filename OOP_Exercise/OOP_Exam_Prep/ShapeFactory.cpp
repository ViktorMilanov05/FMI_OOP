#include "ShapeFactory.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "Circle.h"

Shape* shapeFactory()
{
	int choice;
	std::cin >> choice;
	switch (choice)
	{
	case 1:
		int x1, x2, x3, y1, y2, y3;
		std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
		return new Triangle(x1, y1, x2, y2, x3, y3);
	case 2:
		x1, x2, x3, y1, y2, y3;
		int x4,y4;
		std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
		return new Rectangle(x1, y1, x2, y2, x3, y3, x4, y4);
	case 3:
		x1, x2;
		double d;
		std::cin >> x1 >> y1 >> d;
		return new Circle(x1, y1, d);
	default:
		return nullptr;
		break;
	}
}
