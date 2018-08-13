#pragma once
/********************************************************************************************
* File:			compositeShape.hpp
* Author:		Easa El Sirgany
*				easa.elsirgany@oit.edu
*
* Description:	Defines the composite shape class
********************************************************************************************/
#include <vector>
#include <string>
#include "shape.hpp"


class Composite : public Shape {
public:
	Composite() = default; 

	Composite(struct Coordinates origin, json contents)
	{
		origin_ = origin;
		
		name_ = "Composite";
		contents_ = contents;
	}

	Composite(json full)
	{
		try {
			name_ = full["Name"].get<std::string>();
		}
		catch (...) {
			name_ = "Composite";
		}

		try {
			contents_ = full["Contents"];
		}
		catch (...) {
			contents_ = nullptr;
		}

		if (!parseContents(contents_)) {
			Composite();
		}
	}
};