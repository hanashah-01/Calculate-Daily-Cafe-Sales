#ifndef ANALYSIS
#define ANALYSIS
#include "Sales.h"
#include <iostream>

class Analysis
{
	private:
		double avgSales;
		
	public:
		Analysis()		//default constructor
		{
			avgSales=0.0;
		}
		~Analysis(){}		//destructor
		//functions to calculate analysis
		double calcAvgSales(double totalWeek);
		double calcDifference(double, double);
		double calcTax(double weekly);	
};
#endif
