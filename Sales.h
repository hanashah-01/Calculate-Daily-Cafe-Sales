//Sales.h
#ifndef SALES
#define SALES
#include "Analysis.h"

class Sales
{
	private:
		//private members
		double salesPerDay;
		double salesPerWeek;
		double salesPerItem;
		double highestSale;
		double lowestSale;
		Analysis S;			//object composition of class Analysis
	
	public:
		Sales()	//default constructor
		{
			salesPerDay=0.0;
			salesPerWeek=0.0;
			highestSale=0.0;
			lowestSale=0.0;
		}
		~Sales()	//destructor
		{
			salesPerDay=0.0;
			salesPerWeek=0.0;
			highestSale=0.0;
			lowestSale=0.0;
		}
		//mutator functions
		void SetsalesPerItem(double);
		void SetsalesPerDay(double);
		void SetsalesPerWeek(double);
		void SetHighest(double);
		void SetLowest(double);
		void print(); //function to print out average sales, highest sales and lowest sales
		
		//accessor functions
		double getsalesPerItem();
		double getsalesPerDay();
		double getsalesPerWeek();
};
#endif
