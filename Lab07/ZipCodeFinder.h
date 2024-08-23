#pragma once

#include "Visitor.h"
#include <vector>

class ZipCodeFinder : public Visitor
{
public:
	ZipCodeFinder(string zip);
	~ZipCodeFinder();

	void visit(City city);
	vector<City> getList();

private:
	string searchZip;
	vector<City> cityList;

};

ZipCodeFinder::ZipCodeFinder(string zip)
{
	searchZip = zip;
}

ZipCodeFinder::~ZipCodeFinder()
{

}

void ZipCodeFinder::visit(City city)
{
	if (city.getCountyZip() == searchZip)
	{
		cityList.push_back(city);
	}
}

vector<City> ZipCodeFinder::getList()
{
	return cityList;
}