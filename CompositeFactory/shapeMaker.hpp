#pragma once
/********************************************************************************************
* File:			shapeMaker.hpp
* Author:		Easa El Sirgany
*				easa.elsirgany@oit.edu
*
* Description:	Implementation of the GoF Factory Method pattern. 
*
*				There are two implementations listed in the book, I am utilizing the
*				parameterized factory method.
********************************************************************************************/
#include <memory>

#include "json.h"
#include "shape.hpp"


class ShapeMaker {
public:
	std::unique_ptr<Shape> makeShape(json j);
	std::unique_ptr<Shape> makeShape(Shape::ShapeType type);
};