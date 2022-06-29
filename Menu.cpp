#include<iostream>
#include "Menu.h"
#include "Sales.h"
using namespace std;
//mutators
void Menu::setMenuNames(string m) //Set names of items in menu
{
	menuNames=m;
}
void Menu::setMenuPrices(double p) //Set prices of items in menu
{
	menuPrices=p;
}

//accessors
string Menu::getMenuNames() //Get names of items in menu
{
	return menuNames;
}
double Menu::getMenuPrices() //Get prices of items in menu
{
	return menuPrices;
}
void Menu::getDaySales() //Get amount of sales per day(daily)
{
	Sales::getsalesPerDay();
}
