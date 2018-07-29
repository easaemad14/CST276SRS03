#pragma once
/********************************************************************************************
* File:			ConcreteCreator.hpp
* Author:		Easa El Sirgany
*				easa.elsirgany@oit.edu
*
* Description:	Defines a derivation of the creator class from the GoF Factory Method Pattern
********************************************************************************************/
#include "creator.hpp"
#include "concreteProduct.hpp"


class ConcreteCreator : public Creator {
private:
	Product * FactoryMethod() override
	{
		return new ConcreteProduct;
	}
};