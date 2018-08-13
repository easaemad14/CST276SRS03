#pragma once
/********************************************************************************************
* File:			line.hpp
* Author:		Easa El Sirgany
*				easa.elsirgany@oit.edu
*
* Description:	Defines the line shape class
********************************************************************************************/
#include "shape.hpp"


class Line : public Shape {
public:
	Line() = default;
	Line(struct Coordinates origin, int length, double degree) 
	{
		origin_ = origin;
		length_ = length;
		degree_ = degree;

		name_ = "Line";
		contents_ = {
			{ "Length", length_ },
			{ "Degree", degree_ },
			{ "Coordinates", { origin_.x_, origin_.y_ } }
		};
	}

private:
	int length_;
	double degree_; // Orientation from x-axis (horizontal)
};