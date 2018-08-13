#pragma once
/********************************************************************************************
* File:			circle.hpp
* Author:		Easa El Sirgany
*				easa.elsirgany@oit.edu
*
* Description:	Defines the circle shape class
********************************************************************************************/
#include "shape.hpp"


class Circle final : public Shape {
public:
	Circle(struct Coordinates origin, double radius)
	{
		origin_ = origin;
		radius_ = radius;

		name_ = "Circle";
		contents_ = {
			{ "Radius", radius_ },
			{ "Coordinates",{ origin_.x_, origin_.y_ } }
		};
	}

private:
	double radius_;
};