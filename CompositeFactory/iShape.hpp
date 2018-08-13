#pragma once
/********************************************************************************************
* File:			iShape.hpp
* Author:		Easa El Sirgany
*				easa.elsirgany@oit.edu
*
* Description:	Defines the shape interface
********************************************************************************************/
#include "json.h" // Thanks Neils!


class IShape {
public:
	virtual void Display() = 0;
	virtual json Jsonify() = 0;
};