#pragma once
/********************************************************************************************
* File:			shape.hpp
* Author:		Easa El Sirgany
*				easa.elsirgany@oit.edu
*
* Description:	Defines the base class for any shape object
********************************************************************************************/
#include <iostream>
#include "iShape.hpp"


// Implements the GoF Composite Pattern
/**
 * NOTE: Requirements are not fully defined!
 * 
 * I need more information on what a shape needs (for the front end) in order to draw (e.g.
 * coordinates, etc.). Also, SRS states that rectangles must be drawn first, but I am not
 * doing any drawing; pushing this back onto the front end guys :)
 */
class Shape : public IShape {
public:
	void Display() override
	{
		json j = {
			{"Name", name_},
			{"Contents", contents_}
		};

		std::cout << j.dump(4) << std::endl;
	}

public:
	enum class ShapeType {
		// Generic shapes to be chosen from for making shapes
		LINE,
		CIRCLE,
		RECTANGLE,
		NGON,
		COMPOSITE // N number of shapes or user defined shape
	};

	struct Coordinates {
		int x_, y_;
	};

protected:
	std::string name_;
	json contents_;
	struct Coordinates origin_;
};