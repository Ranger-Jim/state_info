#pragma once

#include <iostream>
#include <string>

using namespace std;

class City
{
public:
	City();
	City(string line);
	void setCity(const string newCity);
	void setStateID(const string newID);
	void setState(const string newState);
	void setCountyZip(const string zip);
	void setCountyName(const string newName);
	void setPopulation(const int pop);
	void setArea(const double newArea);
	void setTimeZone(const string newTZ);
	string getCity() const;
	string getStateID() const;
	string getState() const;
	string getCountyZip() const;
	string getCountyName() const;
	int getPopulation() const;
	double getArea() const;
	string getTimeZone() const;
	void displayInfo();
	//overloaded operators
	bool operator==(const City& rhs) const;
	bool operator!=(const City& rhs) const;
	bool operator<(const City& rhs) const;
	bool operator>(const City& rhs) const;
	void operator+=(int popIncrease);

	friend ostream& operator<<(ostream& os, const City& obj);
	friend istream& operator>>(istream& is, City& obj);

private:
	string city;
	string stateID;
	string state;
	string countyZip;
	string countyName;
	int population;
	double area;
	string timeZone;

};
