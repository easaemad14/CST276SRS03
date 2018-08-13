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

	Line(json contents)
	{
		if (!parseContents(contents)) {
			// Use default values?
			Line();
			/*struct Coordinates defaultOrigin { 0, 0 };
			origin_ = defaultOrigin;

			name_ = "Line";
			contents_ = {
				{ "Length", length_ },
				{ "Degree", degree_ },
				{ "Coordinates",{ origin_.x_, origin_.y_ } }
			};*/
		}
	}

	// Get length and degree
	void parseSubContents() override
	{
		try {
			length_ = contents_["Length"].get<int>();
		}
		catch (json::out_of_range) {
			length_ = 0; // Lack of length == length of zero
		}
		catch (json::type_error) {
			length_ = 0;
		}
		catch (...) {
			length_ = 0;
		}

		try {
			degree_ = contents_["Degree"].get<double>();
		}
		catch (...) {
			degree_ = 0;
		}
	}

private:
	int length_;
	double degree_; // Orientation from x-axis (horizontal)
};