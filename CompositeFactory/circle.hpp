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
	Circle() = default;

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

	Circle(json contents)
	{
		if (!parseContents(contents)) {
			Circle();
		}
	}

	void parseSubContents() override
	{
		try {
			radius_ = contents_["Radius"].get<double>();
		}
		catch (...) {
			radius_ = 0;
		}
	}

private:
	double radius_;
};