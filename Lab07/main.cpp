

#include "City.h"
#include "BST.h"

#include "StateAbbFinder.h"
#include "ZipCodeFinder.h"
#include "MinLandAreaFinder.h"
#include "GenTimeZone.h"
#include "Visitor.h"
#include <string>

#include <algorithm>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>

using namespace std;

int mainMenu(BST<City>* myTree);
void searchMenu(BST<City>* myTree);
void genReportsMenu(BST<City>* myTree);
void maxMinMenu(BST<City>* myTree);
void editMenu(BST<City>* myTree);
void displayHeader();

void stateAbbSearch(BST<City>* myTree, string abb);
void zipSearch(BST<City>* myTree, string zip);
void minLandArea(BST<City>* myTree, double area);
void displayByTimeZone(BST<City>* myTree, string timeZone);



int main()
{
	BST<City>* myTree = new BST<City>();
	myTree = myTree->loadTreeData();

	mainMenu(myTree);
	
	return 0;
}

int mainMenu(BST<City>* myTree)
{
	int choice = 0;

	while (choice != 5)
	{
		cout << "\nMAIN MENU..." << endl;
		cout << "\nENTER NUMBER FOR SUB-MENU:" << endl;
		cout << "1) Search" << endl;
		cout << "2) Generate Reports" << endl;
		cout << "3) Maximum and Minimums" << endl;
		cout << "4) Edit City Data" << endl;
		cout << "5) Quit\n" << endl;

		cin >> choice;

		switch (choice)
		{
		case 1:
			searchMenu(myTree);
			break;
		case 2:
			genReportsMenu(myTree);
			break;
		case 3:
			maxMinMenu(myTree);
			break;
		case 4:
			editMenu(myTree);
			break;
		case 5:
			cout << "\nEXITING..." << endl;
			break;
		default:
			cout << "\nPLEASE ENTER VALID NUMBER..." << endl;
			break;
		}
		
	}
	return 0;
}

void searchMenu(BST<City>* myTree)
{
	int choice = 0;
	string zip = "00000";
	string state = "";
	double sqMiles = 0.0;


	while (choice != 4)
	{
		cout << "\nSEARCH MENU..." << endl;
		cout << "\nENTER VALID NUMBER:" << endl;
		cout << "1) Search by ZIP Code" << endl;
		cout << "2) Search by State" << endl;
		cout << "3) Search by Minimum Land Area" << endl;
		cout << "4) Return to Main Menu\n" << endl;

		cin >> choice;

		switch (choice)
		{
		case 1:
			cout << "PLEASE ENTER ZIP CODE: " << endl;
			cin >> zip;
			zipSearch(myTree, zip);
			break;
		case 2:
			cout << "PLEASE ENTER STATE ABBREVIATION (ex. MD, TX, CA, etc): " << endl;
			cin >> state;
			stateAbbSearch(myTree, state);
			break;
		case 3:
			cout << "PLEASE ENTER MINIMUM SQUARE MILES: " << endl;
			cin >> sqMiles;
			minLandArea(myTree, sqMiles);
			break;
		case 4:
			break;
		default:
			cout << "\nPLEASE ENTER VALID NUMBER..." << endl;
			break;
		}
	}
}

void genReportsMenu(BST<City>* myTree)
{
	int choice = 0;
	string timeZone = "";

	while (choice != 5)
	{
		cout << "\nGENERATE REPORTS MENU..." << endl;
		cout << "\nENTER VALID NUMBER:" << endl;
		cout << "1) List All Cities" << endl;
		cout << "2) List All Cities and Population Density" << endl;
		cout << "3) List All Cities in a Time Zone" << endl;
		cout << "4) Post-Order Traverse" << endl;
		cout << "5) Return to Main Menu\n" << endl;

		cin >> choice;

		switch (choice)
		{
		case 1:
			displayHeader();
			myTree->inOrderTraverse();
			break;
		case 2:
			
			break;
		case 3:
			cout << "PLEASE ENTER TIME ZONE (EST, MST, CST, or PST) ";
			cin >> timeZone;
			displayByTimeZone(myTree, timeZone);
			break;
		case 4:
			displayHeader();
			myTree->postOrderTraverse();
			break;
		case 5:
			break;
		default:
			cout << "\nPLEASE ENTER VALID NUMBER..." << endl;
			break;
		}
	}
}

void maxMinMenu(BST<City>* myTree)
{
	int choice = 0;

	while (choice != 7)
	{
		cout << "\nMAX AND MIN MENU..." << endl;
		cout << "\nENTER VALID NUMBER:" << endl;
		cout << "1) Maximum Land Area" << endl;
		cout << "2) Maximum Population" << endl;
		cout << "3) Minimum Land Area" << endl;
		cout << "4) Minimum Population" << endl;
		cout << "5) Maximum Population Density" << endl;
		cout << "6) Minimum Population Density" << endl;
		cout << "7) Return to Main Menu\n" << endl;

		cin >> choice;

		switch (choice)
		{
		case 1:
			cout << "PLACEHOLDER: max land area" << endl;
			break;
		case 2:
			cout << "PLACEHOLDER: max pop" << endl;
			break;
		case 3:
			cout << "PLACEHOLDER: min land area" << endl;
			break;
		case 4:
			cout << "PLACEHOLDER: min pop" << endl;
			break;
		case 5:
			cout << "PLACEHOLDER: max pop density" << endl;
			break;
		case 6:
			cout << "PLACEHOLDER: min pop density" << endl;
			break;
		case 7:
			break;
		default:
			cout << "\nPLEASE ENTER VALID NUMBER..." << endl;
			break;
		}

	}
}

void editMenu(BST<City>* myTree)
{
	int choice = 0;
	int popIncrease = 0;
	string city;

	while (choice != 3)
	{
		cout << "\nEDIT MENU..." << endl;
		cout << "\nENTER VALID NUMBER:" << endl;
		cout << "1) Edit Population" << endl;
		cout << "2) Edit Land Area" << endl;
		cout << "3) Return to Main Menu\n" << endl;

		cin >> choice;

		switch (choice)
		{
		case 1:

			cout << "\nPOPLATION INCREASE" << endl;
			cout << "WHICH CITY WOULD YOU LIKE TO EDIT?";
			cin >> city;
			//search tree for city, if found, prompt pop increase.

			break;
		case 2:
			cout << "PLACEHOLDER: edit land area" << endl;
			break;
		case 3:
			break;
		default:
			cout << "\nPLEASE ENTER VALID NUMBER..." << endl;
			break;
		}
	}
}

void displayHeader() {
	cout << setfill(' ');
	cout << setw(20) << left;
	cout << "|CITY";
	cout << setw(10);
	cout << "|STATE ID";
	cout << setw(25);
	cout << "|STATE";
	cout << setw(10);
	cout << "|ZIP CODE";
	cout << setw(25);
	cout << "|COUNTY";
	cout << setw(12);
	cout << "|POP.";
	cout << setw(8);
	cout << "|AREA";
	cout << setw(5);
	cout << "|TIME ZONE\n" << endl;
}

void stateAbbSearch(BST<City>* myTree, string abb)
{
	transform(abb.begin(), abb.end(), abb.begin(), ::toupper);

	StateAbbFinder searchState(abb);
	myTree->inOrderVisit(searchState);

	cout << "\nSearching for cities in " << abb << endl;

	vector<City> stateList = searchState.getList();

	if (stateList.empty())
	{
		cout << "\nNo cities in this state..." << endl;
	}
	else
	{
		for (auto p : stateList)
		{
			cout << "\n=======================================" << endl;
			cout << "CITY: " << p.getCity() << endl;
			cout << "ZIP CODE: " << p.getCountyZip() << endl;
			cout << "COUNTY: " << p.getCountyName() << endl;
			cout << "=======================================\n" << endl;
		}
	}
}

void zipSearch(BST<City>* myTree, string zip)
{
	ZipCodeFinder searchState(zip);
	myTree->inOrderVisit(searchState);

	cout << "\nSearching for cities in " << zip << endl;

	vector<City> cityList = searchState.getList();

	if (cityList.empty())
	{
		cout << "\nNO CITIES IN ZIP CODE: " << zip << endl;
	}
	else
	{
		displayHeader();
		for (auto p : cityList)
		{
			cout << p << endl;
		}
	}
}

void minLandArea(BST<City>* myTree, double area)
{
	MinLandAreaFinder searchState(area);
	myTree->inOrderVisit(searchState);

	cout << "\nSearching for cities with a minimum of "
		<< area << " square miles...\n" << endl;

	vector<City> cityList = searchState.getList();

	if (cityList.empty())
	{
		cout << "\nNO CITIES WITH LARGER SQUARE MILES THAN: "
			<< area << endl;
	}
	else
	{
		displayHeader();
		for (auto p : cityList)
		{
			cout << p << endl;
		}
	}
}

void displayByTimeZone(BST<City>* myTree, string timeZone)
{
	transform(timeZone.begin(), timeZone.end(), timeZone.begin(), ::toupper);

	GenTimeZone searchTZ(timeZone);
	myTree->inOrderVisit(searchTZ);

	cout << "\nSearching for cities in time zone: " << timeZone << endl;

	vector<City> cityList = searchTZ.getList();

	if (cityList.empty())
	{
		cout << "\nNO CITIES IN TIME ZONE: " << timeZone << endl;
	}
	else
	{
		for (auto p : cityList)
		{
			cout << "\n==============================" << endl;
			cout << "CITY: " << p.getCity() << endl;
			cout << "STATE: " << p.getState() << endl;
			cout << "ZIP: " << p.getCountyZip() << endl;
			cout << "===============================\n" << endl;
		}
	}

}




