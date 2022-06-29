#ifndef MENU
#define MENU
#include "Sales.h"
#include <string>
#include <iostream>
using namespace std;

class Menu:public Sales		//derived class with public access to base class(Sales)
{
	private:
		string menuNames;		//store menu name
		double menuPrices;		//store menu price
		double discount1, discount2;
		
		friend string access(Menu);		//friend function
	public:
		Menu()						//default constructor
		{
			menuNames=" ";
			menuPrices=0;
			discount1 = 0;
			discount2 = 0;
		}
		~Menu()						// destructor
		{
			menuNames=" ";
			menuPrices=0;
			discount1 = 0;
			discount2 = 0;
		}
		//mutator functions
		void setMenuNames(string);
		void setMenuPrices(double);

		//accessor functions
		string getMenuNames();
		double getMenuPrices();
		void getDaySales();
		
		//operator overloading
		Menu operator=(Menu rhs)
		{
			menuPrices = rhs.menuPrices;
			discount1 = rhs.discount1;
			discount2 = rhs.discount2;
			return *this; //this pointer
		}
};
#endif
