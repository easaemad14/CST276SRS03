#pragma once
/********************************************************************************************
* File:			rectangle.hpp
* Author:		Easa El Sirgany
*				easa.elsirgany@oit.edu
*
* Description:	Defines the rectangle shape class
********************************************************************************************/
#include "polygon.hpp"


// A rectangle is just a polygon (that gets drawn first)
// I am not doing any error checking yet...
class Rectangle final : public Polygon {
public:
	Rectangle() = default;

	Rectangle(struct Coordinates origin, std::vector<Line> edges)
	{
		// Need an array of edges for our JSON object
		json arr;
		for (auto e : edges) {
			arr.push_back(e.Jsonify());
		}
		swapEdges(edges);

		origin_.x_ = origin.x_;
		origin_.y_ = origin.y_;

		name_ = "Rectangle";
		contents_ = {
			{ "Edges", arr },
			{ "Coordinates",{ origin_.x_, origin_.y_ } }
		};
	}

	Rectangle(json contents)
	{
		if (!parseContents(contents)) {
			Rectangle();
		}
	}
};