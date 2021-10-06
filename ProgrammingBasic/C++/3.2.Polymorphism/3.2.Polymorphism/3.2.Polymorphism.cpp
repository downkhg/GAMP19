#include <iostream>
#include "Shape.h"
#include "PolymrphismShape.h"

using namespace std;

void main()
{
	Inheritance::ShapeMain();
	Inheritance::RuntimeShapeDrawMain();
	Inheritance::PolymrphismShapeDrawMain();

	Polymrphism::ShapeMain();
	Polymrphism::RuntimeShapeDrawMain();
	Polymrphism::PolymrphismShapeDrawMain();
}