// main.cpp : Implementation of a drawing backend using GoF Composite and Factory Method patterns
//

#include "stdafx.h"
#include <iostream>

#include "line.hpp"
#include "circle.hpp"
#include "polygon.hpp"
#include "rectangle.hpp"

using namespace std;

// Test cases
int main()
{
	vector<unique_ptr<Shape>> compositeShapeFactory;
	vector<unique_ptr<Shape>>::iterator it;
	struct Shape::Coordinates lineCoordinate{0,0};

	compositeShapeFactory.push_back(make_unique<Line>(lineCoordinate, 0, 0));

	for (it = compositeShapeFactory.begin(); it != compositeShapeFactory.end(); it++) {
		(*it)->Display();
	}

    return 0;
}

