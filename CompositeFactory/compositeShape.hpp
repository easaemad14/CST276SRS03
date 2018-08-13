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
	Composite(struct Coordinates origin, json contents)
	{
		origin_ = origin;
		
		name_ = "Composite";
		contents_ = contents;
	}
};