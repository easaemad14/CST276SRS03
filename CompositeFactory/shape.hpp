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
		auto j = Jsonify();
		std::cout << j.dump(4) << std::endl;
	}

	// Equivalent to to_json
	json Jsonify() override
	{
		return {
			{ "Name", name_ },
			{ "Contents", contents_ }
		};
	}

protected:
	bool parseContents(json contents) // Type should be defined (from name)
	{
		// Ensure our Contents is a json object...
		if (!contents_ || !contents_.is_object()) { // Can be a nullptr
			return false;
		}

		// Parse the contets for the origin
		json point;
		try {
			point = contents_["Coordinates"];
		}
		catch (json::out_of_range) {
			// All shapes need coordinates to be drawable
			return false;
		}
		catch (...) {
			return false;
		}

		// Our coordinates should be an array
		if (!point.is_array()) {
			return false;
		}
		else {
			origin_.x_ = point.at(0);
			origin_.y_ = point.at(1);
		}

		if (!contents_.empty()) {
			parseSubContents();
		}
	}

	virtual void parseSubContents() {}

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