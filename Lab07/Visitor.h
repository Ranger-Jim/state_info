#pragma once

#include "City.h"

class Visitor
{
public:
	Visitor();
	~Visitor();
	virtual void visit(City city) = 0;
};

Visitor::Visitor()
{

}

Visitor::~Visitor()
{

}
