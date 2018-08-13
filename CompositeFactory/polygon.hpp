#pragma once
/********************************************************************************************
* File:			polygon.hpp
* Author:		Easa El Sirgany
*				easa.elsirgany@oit.edu
*
* Description:	Defines the ngon shape class
********************************************************************************************/
#include <vector>
#include "line.hpp"


// Polygons are quite complex; I am currently not doing any error checking here
class Polygon : public Line {
public:
	Polygon() = default;

	Polygon(struct Coordinates origin, std::vector<Line> edges)
	{
		// Need an array of edges for our JSON object
		json arr;
		for (auto e : edges) {
			arr.push_back(e.Jsonify());
		}
		edges_.swap(edges);
		origin_ = origin;

		name_ = std::to_string(edges_.size()) + "-gon";
		contents_ = {
			{ "Edges", arr },
			{ "Coordinates",{ origin_.x_, origin_.y_ } }
		};
	}

	Polygon(json contents)
	{
		if (!parseContents(contents)) {
			Polygon();
		}
	}

	void parseSubContents() override
	{
		//json e;
		//try {
		//	e = contents_["Edges"];
		//}
		//catch (...) {
		//	// No edges?
		//}

		//if (e.is_array()) {
		//	for (auto edge : e) {
		//		edges_.push_back(edge);
		//	}
		//}
	}

	void swapEdges(std::vector<Line> e)
	{
		edges_.swap(e);
	}

protected:
	std::vector<Line> edges_;
};