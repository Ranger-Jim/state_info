#pragma once

#include "Visitor.h"
#include <vector>

class MinLandAreaFinder : public Visitor
{
public:
	MinLandAreaFinder(double area);
	~MinLandAreaFinder();

	void visit(City city);
	vector<City> getList();

private:
	double searchArea;
	vector<City> cityList;
};

MinLandAreaFinder::MinLandAreaFinder(double area)
{
	searchArea = area;
}

MinLandAreaFinder::~MinLandAreaFinder()
{

}

void MinLandAreaFinder::visit(City city)
{
	if (city.getArea() >= searchArea)
	{
		cityList.push_back(city);
	}
}

vector<City> MinLandAreaFinder::getList()
{
	return cityList;
}
