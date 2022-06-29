//Sales.cpp
#include<iostream>
#include "Sales.h"
#include "Analysis.h"
#include<iomanip>
using namespace std;

//mutator function
void Sales::SetsalesPerItem(double I)
{salesPerItem = I;
}

void Sales::SetsalesPerDay(double D)
{	salesPerDay=D;
}

void Sales::SetsalesPerWeek(double W)
{ 	salesPerWeek=W;	
}

//accessor function
double Sales::getsalesPerItem() //get sales for each item in menu
{	return salesPerItem;
}

double Sales::getsalesPerDay() //get sales for all items daily
{	return salesPerDay;
}

double Sales::getsalesPerWeek() //get sales for all items for the week
{	return salesPerWeek;
}

void Sales::SetHighest(double hi) //get the highest sale among daily sales
{
	highestSale = hi;
}

void Sales::SetLowest(double lo) //get the lowest sale among daily sales
{
	lowestSale = lo;
}

//display avg, lowest, highest day, difference between highest and lowest sale
//and calculate the tax
void Sales::print()
{
	int day = 7;
	cout << setprecision(2) << fixed;
	cout << "Average Sales: RM" << S.calcAvgSales(salesPerWeek) << endl;
	cout << "Highest Sales: RM" << highestSale << endl;
	cout << "Lowest Sales: RM" << lowestSale << endl;
	cout << "Difference: RM" << S.calcDifference(highestSale, lowestSale) << endl;
	cout << "Tax 6%: RM" << S.calcTax(salesPerWeek) << endl;
}
