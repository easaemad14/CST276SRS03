#pragma once
/********************************************************************************************
* File:			component.hpp
* Author:		Easa El Sirgany
*				easa.elsirgany@oit.edu
*
* Description:	Defines the Component Class from the GoF Composite Pattern
********************************************************************************************/


class Component {
public:
	virtual void Operation() = 0;
	virtual void Add() = 0;
	virtual void Remove() = 0;
	virtual void GetChild(int pos) = 0;
};