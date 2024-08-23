#pragma once

#include "Visitor.h"
#include <vector>

class GenTimeZone : public Visitor
{
public:
	GenTimeZone(string timeZone);
	~GenTimeZone();

	void visit(City city);
	vector<City> getList();

private:
	string timeZone;
	vector<City> cityList;
};

GenTimeZone::GenTimeZone(string timeZone)
{
	this->timeZone = timeZone;
}

GenTimeZone::~GenTimeZone()
{

}

void GenTimeZone::visit(City city)
{
	if (city.getTimeZone() == timeZone)
	{
		cityList.push_back(city);
	}
}

vector<City> GenTimeZone::getList()
{
	return cityList;
}
