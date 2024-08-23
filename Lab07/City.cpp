

#include "City.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

City::City()
{
	city = "";
	stateID = "";
	state = "";
	countyZip = "";
	countyName = "";
	population = 0;
	area = 0.0;
	timeZone = "";
}

City::City(string line)
{
	istringstream inSS(line);
	string pop;
	string sArea;

	getline(inSS, city, ',');
	getline(inSS, stateID, ',');
	getline(inSS, state, ',');
	getline(inSS, countyZip, ',');
	getline(inSS, countyName, ',');
	getline(inSS, pop, ',');
	population = stol(pop);
	getline(inSS, sArea, ',');
	area = stod(sArea);
	getline(inSS, timeZone, ',');

}

void City::setCity(const string newCity)
{
	city = newCity;
}

void City::setStateID(const string newID)
{
	stateID = newID;
}

void City::setState(const string newState)
{
	state = newState;
}

void City::setCountyZip(const string zip)
{
	countyZip = zip;
}

void City::setCountyName(const string newName)
{
	countyName = newName;
}

void City::setPopulation(const int pop)
{
	population = pop;
}

void City::setArea(const double newArea)
{
	area = newArea;
}

void City::setTimeZone(const string newTZ)
{
	timeZone = newTZ;
}

string City::getCity() const
{
	return city;
}

string City::getStateID() const
{
	return stateID;
}

string City::getState() const 
{
	return state;
}

string City::getCountyZip() const
{
	return countyZip;
}

string City::getCountyName() const
{
	return countyName;
}

int City::getPopulation() const
{
	return population;
}

double City::getArea() const
{
	return area;
}

string City::getTimeZone() const
{
	return timeZone;
}

void City::displayInfo()
{
	cout << "City: " << getCity() << endl;
	cout << "ID: " << getStateID() << endl;
	cout << "State: " << getState() << endl;
	cout << "ZIP: " << getCountyZip() << endl;
	cout << "County: " << getCountyName() << endl;
	cout << "Population: " << getPopulation() << endl;
	cout << "Area (Sq. miles): " << getArea() << endl;
	cout << "Time Zone: " << getTimeZone() << endl;
}

bool City::operator==(const City& rhs) const
{
	return (this->city == rhs.city && this->stateID == rhs.stateID
		&& this->state == rhs.state && this->countyZip == rhs.countyZip
		&& this->countyName == rhs.countyName && this->population == rhs.population
		&& this->area == rhs.area && this->timeZone == rhs.timeZone);
}

bool City::operator!=(const City& rhs) const
{
	return (this->city != rhs.city || this->stateID != rhs.stateID
		|| this->state != rhs.state || this->countyZip != rhs.countyZip
		|| this->countyName != rhs.countyName || this->population != rhs.population
		|| this->area != rhs.area || this->timeZone != rhs.timeZone);
}

bool City::operator<(const City& rhs) const
{
	return (this->population < rhs.population);
}

bool City::operator>(const City& rhs) const
{
	return (this->population > rhs.population);
}

void City::operator+=(int popIncrease)
{
	this->population += popIncrease;
}

ostream& operator<<(ostream& os, const City& obj)
{
	os << setfill(' ');

	os << setw(20) << left;
	os << obj.city;
	os << setw(10);
	os << obj.stateID;
	os << setw(25);
	os << obj.state;
	os << setw(10);
	os << obj.countyZip;
	os << setw(25);
	os << obj.countyName;

	//putting commas in the population number
	os << setw(12);
	int x = obj.population;
	string str = to_string(x);
	int n2 = str.length() - 3;
	int end2 = (x >= 0) ? 0 : 1;

	while (n2 > end2)
	{
		str.insert(n2, ",");
		n2 -= 3;
	}
	os << str;

	os << setw(8);
	os << obj.area;
	os << setw(5);
	os << obj.timeZone << endl;

	os << setfill('_') << setw(130) << " " << endl;



	return os;
}

istream& operator>>(istream& is, City& obj)
{
	cout << "ENTER A CITY NAME: ";
	is >> obj.city;

	return is;
}
