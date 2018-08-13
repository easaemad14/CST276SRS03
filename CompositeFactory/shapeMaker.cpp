/********************************************************************************************
* File:			shapeMaker.cpp
* Author:		Easa El Sirgany
*				easa.elsirgany@oit.edu
*
* Description:	Implementation of the GoF Factory Method pattern.
*
*				There are two implementations listed in the book, I am utilizing the
*				parameterized factory method.
********************************************************************************************/
#include "stdafx.h"
#include "shapeMaker.hpp"
#include "line.hpp"
#include "circle.hpp"
#include "polygon.hpp"
#include "rectangle.hpp"
#include "compositeShape.hpp"

using namespace std;


// Generate a new shape from a JSON object
unique_ptr<Shape> ShapeMaker::makeShape(json j)
{
	auto name = j["Name"].get<string>();
	auto contents = j["Contents"];

	if (name.compare("Line") == 0) {
		return make_unique<Line>(contents);
	}
	else if (name.compare("Circle") == 0) {
		return make_unique<Circle>(contents);
	}
	else if (name.compare("Polygon") == 0) {
		return make_unique<Polygon>(contents);
	}
	else if (name.compare("Rectangle") == 0) {
		return make_unique<Rectangle>(contents);
	}
	else {
		return make_unique<Composite>(j); // Send full json object
	}
}

// Generate a new DEFAULT Shape from a type...
unique_ptr<Shape> ShapeMaker::makeShape(Shape::ShapeType type)
{
	switch (type) {
	case Shape::ShapeType::LINE:
		return make_unique<Line>();
	case Shape::ShapeType::CIRCLE:
		return make_unique<Circle>();
	case Shape::ShapeType::RECTANGLE:
		return make_unique<Rectangle>();
	case Shape::ShapeType::NGON:
		return make_unique<Polygon>();
	case Shape::ShapeType::COMPOSITE:
		return make_unique<Composite>();
	default: // This should never happen...
		return make_unique<Composite>();
	}
}