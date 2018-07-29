#pragma once
/********************************************************************************************
* File:			composite.hpp
* Author:		Easa El Sirgany
*				easa.elsirgany@oit.edu
*
* Description:	Defines the Composite Class from the GoF Composite Pattern
********************************************************************************************/
#include <vector>
#include "component.hpp"


class Composite : public Component {
public:
	void Operation() override
	{
		for (auto g : children) {
			g->Operation();
		}
	}

	void Add() override
	{
	}

	void Remove() override
	{
	}

	void GetChild(int pos) override
	{
	}

private:
	std::vector<Component *> children;
};