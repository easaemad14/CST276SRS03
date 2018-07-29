#pragma once
/********************************************************************************************
* File:			leaf.hpp
* Author:		Easa El Sirgany
*				easa.elsirgany@oit.edu
*
* Description:	Defines the Leaf Class from the GoF Composite Pattern. Operation should be
*				the only valid callable method.
********************************************************************************************/
#include "component.hpp"


class Leaf : public Component {
public:
	void Operation() override
	{
		// Do something here
	}

	// Need to override all pure virtual methods, but these should not be used
	// TODO: throw something?
	void Add() override {}
	void Remove() override {}
	void GetChild(int pos) override {}
};