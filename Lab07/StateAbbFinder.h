#pragma once

#include "Visitor.h"
#include <vector>

class StateAbbFinder : public Visitor
{
public:
	StateAbbFinder(string state);
	~StateAbbFinder();

	void visit(City city);
	vector<City> getList();

private:
	string searchState;
	vector<City> cityList;

};

StateAbbFinder::StateAbbFinder(string state)
{
	searchState = state;
}

StateAbbFinder::~StateAbbFinder()
{

}

void StateAbbFinder::visit(City city)
{
	if (city.getStateID() == searchState)
	{
		cityList.push_back(city);
	}
}

vector<City> StateAbbFinder::getList()
{
	return cityList;
}