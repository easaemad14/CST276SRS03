// main.cpp : Implementation of a drawing backend using GoF Composite and Factory Method patterns
//

#include "stdafx.h"
#include <iostream>
#include <fstream>

#include "line.hpp"
#include "circle.hpp"
#include "polygon.hpp"
#include "rectangle.hpp"
#include "compositeShape.hpp"
#include "shapeMaker.hpp"


using namespace std;

// Test cases
int main()
{
	vector<unique_ptr<Shape>> compositeShapeFactory;
	vector<unique_ptr<Shape>>::iterator it;

	// Create a Line
	struct Shape::Coordinates lineCoordinate {0,0};
	compositeShapeFactory.push_back(make_unique<Line>(lineCoordinate, 0, 0));

	// Create a Rectangle
	vector<Line> rectEdges;
	struct Shape::Coordinates rectCoordinates { 0, 0 };
	struct Shape::Coordinates rectVert1 { 0, 0 };
	struct Shape::Coordinates rectVert2 { 0, 1 };
	struct Shape::Coordinates rectVert3 { 1, 1 };
	struct Shape::Coordinates rectVert4 { 1, 0 };

	Line rectEdge1{ rectVert1, 1, 0 };
	Line rectEdge2{ rectVert2, 1, 90 }; 
	Line rectEdge3{ rectVert3, 1, 180 };
	Line rectEdge4{ rectVert4, 1, 270 };

	rectEdges.push_back(rectEdge1);
	rectEdges.push_back(rectEdge2);
	rectEdges.push_back(rectEdge3);
	rectEdges.push_back(rectEdge4);

	compositeShapeFactory.push_back(make_unique<Rectangle>(rectCoordinates, rectEdges));

	// Create a Polygon (triangle)
	//json t;
	//t = Shape::Read("3gon.txt"s);
	//unique_ptr<ShapeMaker> sFact = make_unique<ShapeMaker>();
	//compositeShapeFactory.push_back(sFact->makeShape(t));
	

	for (it = compositeShapeFactory.begin(); it != compositeShapeFactory.end(); it++) {
		(*it)->Display();
	}

    return 0;
}

