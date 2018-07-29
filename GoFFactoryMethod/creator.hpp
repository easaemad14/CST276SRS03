#pragma once
/********************************************************************************************
* File:			creator.hpp
* Author:		Easa El Sirgany
*				easa.elsirgany@oit.edu
*
* Description:	Defines the Creator Class from the GoF Factory Method Pattern
********************************************************************************************/
#include "product.hpp"


class Creator {
private:
	virtual Product * FactoryMethod() = 0;

public:
	void AnOperation()
	{
		// ...
		mProduct = FactoryMethod();
		// ...
	}

private:
	Product * mProduct;
};