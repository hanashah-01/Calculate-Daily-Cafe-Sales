#include "Sales.h"
#include "Analysis.h"

//to calculate average sales from a week
double Analysis::calcAvgSales(double totalWeek)
{
	int DAY = 7;
	avgSales = totalWeek / DAY;
	return avgSales;
}
//to calculate difference between highest daily sale with lowest daily sale
double Analysis::calcDifference(double hi, double lo) 
{
	return hi-lo;
}
//to calculate the amount of tax
double Analysis::calcTax(double weekly)
{
	return (weekly * 0.06);
}
