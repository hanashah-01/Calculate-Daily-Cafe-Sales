/*******************************************************************************
/* Assignment 1
/* What the program do: Calculate daily sales for each item in the café for a week
/* Programmer name: 1. HANA SHAH BINTI FAIZAL SHAH
                    2. SITI SARAH BINTI AHMAD
/* Programmer Matric #: 1. 153583
                        2. 152633
/* Question #: 1
/******************************************************************************/
#include <string>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include "Sales.h"
#include "Menu.h"
#include "Analysis.h"
using namespace std;

//function prototype
void menuSet(int, string m, double p, string[], double[], Menu Cafe[]);
void displayMenu(int numFood, Menu Cafe[]);
void itemSoldInput(int, string[], double[], double, double &totalDay, int, Menu Cafe[]);
void SalesReport(Menu[], double[], const int);

int main()
{
	const int SIZE=30, DAY=7;
	Menu Cafe[SIZE]; 						//object of class Menu is created
	string menuName[SIZE],m;				//array to store data from input file
	double menuPrice[SIZE],p, totalWeek;
	double daily[DAY];
	char choice;
	bool check;
	
	ifstream inputMenu;						//for reading data from a file
	ofstream outputMenu;					//for writing data back into file after changes
	
	//purpose of program
	cout << "This Program is to Calculate Daily Cafe Sales and for a week." << endl;
	
	//for loop to repeat same steps 7 times
	for (int open=0; open<DAY; open++)
	{
		int numFood = 0;					//for dynamic memory allocation
		int *counter = nullptr;
	
		inputMenu.open("Menu.txt"); 		// Open input file containing menu of the restaurant
		if (inputMenu)
		{
			while (inputMenu)
			{
				getline(inputMenu,menuName[numFood]); 	//get menu names
				inputMenu>> menuPrice[numFood]; 		//get menu price
				inputMenu.ignore();						//ignore whitespace
				numFood++;								//to keep track of how many menu names 
														//are there
			}
			inputMenu.close();							//close file
			
			counter = new int[numFood]; 				//dynamically allocate memory for 
														//unknown number of lines in text file
		}
		else
			cout << "Error opening file." << endl;		//if file is not exist
			
			
		//set menuName and menuPrice as private members of class Menu
		menuSet(numFood, m, p, menuName, menuPrice, Cafe);
		
		//------------------------------Display Menu----------------------------------------
		cout << "------------------Day " << open+1 << " Operating------------------" << endl << endl;
		cout << "--------------Menu---------------Price(RM)---" << endl;
		displayMenu(numFood, Cafe);
		
		double salesperItem[numFood];     //create an array to keep user input values
		double sale = 0.0;
		double totalDay=0.0;			//total sales for a day
		
		//function call for displaying total sale for each item
		itemSoldInput(numFood, menuName, salesperItem, sale, totalDay, open, Cafe);
		daily[open] = totalDay; //save total sales for every day
		totalWeek += totalDay; //accumulate total sale for the week
			
		//------------------------------------------------------------------
		//option for user to add menu names
		cout << "Add new menus? -Y/N-" << endl;
		cout << "Your Choice: ";
		cin >> choice;
		//User Input Validation
		while (choice!='y'&& choice!='Y'&&choice!='N'&&choice!='n')
		{
			cout <<"\nERROR! We didn't quite catch that T_T'. Please enter [Y/N].\nAdd new menus? ";
			cout<<"[Y/N]: ";
			cin >> choice;
		}
		
		do 
		{
			if (choice == 'y' || choice == 'Y')
			{
				numFood++;							//if user choose to add new food, dynamic array 
													//size was increased by 1
				
				cout << "Enter new menu name: ";
				cin.ignore();
				getline(cin, m);
				cout << "Enter the price: RM";
				cin >> p;
				while (p<1 || p==0)
				{
					cout<<"\nERROR! Please enter a positive value for price.\n";
					cout<<"Enter the price: RM";
					cin >> p;
				}
				menuName[numFood-1] = m;			//menu name and price were stored in Menu class
				Cafe[numFood-1].setMenuNames(m);
				menuPrice[numFood-1] = p;
				Cafe[numFood-1].setMenuPrices(p);
		
				outputMenu.open("Menu.txt");
				outputMenu << setprecision(2) << fixed;
				for (int m=0; m<numFood; m++)
				{
					if (m == numFood-1) //To prevent a blank space at the last line in the file
					{
						outputMenu << Cafe[m].getMenuNames() << endl;
						outputMenu << Cafe[m].getMenuPrices();
						continue;
			 		}
			 		outputMenu << Cafe[m].getMenuNames() << endl;
					outputMenu << Cafe[m].getMenuPrices() << endl;
				}
				outputMenu.close();
				 //Asks user if they want to update more menu
		    	cout << "Do you want to update more menu? [Y/N]: ";
		    	cin >> choice;
		    	
		    	if(choice == 'y' || choice == 'Y')
		    	check=true;
		    	if(choice == 'N'|| choice == 'n')
		    	break; //get out of loop
			}
			else
			break; //get out of loop
		}while(check==true);
		
	if (open == 6)  //totalWeek was saved on the 7th day of the week for calculations
		Cafe[open].SetsalesPerWeek(totalWeek);
		
	system("PAUSE");		
	system("CLS");			//clear all output before
	delete [] counter;		//delete dynamic array-release array from memory
	}
	
	//function to display report sales
	SalesReport(Cafe, daily, DAY);
	
	cout <<endl << "Happy Hour:----Every Thursday----" << endl;
	//operator overloading
	menuPrice[0]=menuPrice[3];
	cout << menuName[0] << " is the same price as " << menuName[3] << endl;
	cout << "Both at same price RM" << menuPrice[0]; 

	return 0;
}

void menuSet(int numFood, string m, double p, string menuName[], double menuPrice[], Menu Cafe[])
{
	for (int j=0; j<numFood; j++)
	{
		m = menuName[j];
		Cafe[j].setMenuNames(m);
		p = menuPrice[j];
		Cafe[j].setMenuPrices(p);
	}
}
//Function to display contents of menu
void displayMenu(int numFood, Menu Cafe[])
{
	cout<<fixed<<showpoint<<setprecision(2);
	for(int i=0; i < numFood; i++) 
	{
    cout<<"["<<i+1<<"]\t"<<left<<setw(10)<< Cafe[i].getMenuNames(); //display menu names
    cout << "  \t" << right<<setw(10) << Cafe[i].getMenuPrices() << endl;//display prices
	}
	cout << "---------------------------------------------" << endl;
	cout << endl;
}

void itemSoldInput(int numFood, string menuName[], double salesperItem[], double sale,
 double &totalDay, int open, Menu Cafe[])
{
	for(int k=0; k<numFood; k++)
	{
		do{  //do-while loop for input validation. accept value within 0-200 
			cout << "Enter item sold for "<<menuName[k]<<right<<setw(2)<<":";
			cin>>salesperItem[k];
			
			if (salesperItem[k]<0 || salesperItem[k]>200)
			cout << "Invalid Input!(Enter number within 0-200)" << endl;
			
		}while (salesperItem[k]<0 || salesperItem[k]>200);
		
		sale = salesperItem[k] * Cafe[k].getMenuPrices(); //calculate sales for an item
		Cafe[k].SetsalesPerItem(sale); //set the sales for each individual item into class Sales
	}
	cout << endl;
	
	//shows the sale(total) for each item
	cout << "---------------DAY " << open+1 << " SALES:-------------" << endl;
	for(int i=0; i <numFood; i++) 
	{
      cout << menuName[i] << "\t: RM";
      cout<< Cafe[i].getsalesPerItem() <<endl;
 	  totalDay+=Cafe[i].getsalesPerItem(); //accumulate sales for the day
 	  
	}
	cout << endl;
	cout << "Total Sales Today\t: RM"<<totalDay<<endl;
	Cafe[open].SetsalesPerDay(totalDay); //set the total sales for the day into a Sale class member
	
}
//Display the analysis made from daily sales
void SalesReport(Menu Cafe[], double daily[], const int SIZE)
{
	double highest = daily[0], lowest = daily[0];
	
	cout << "----------Analysis Report--------" << endl;
	for (int i=0; i<SIZE; i++)
		//display total sales each day
		cout << "Sales Day " << i+1 << " :\tRM"	<< Cafe[i].getsalesPerDay() << endl;		
	
	//display sales for a week
	cout << "Sales for A Week: RM" << Cafe[SIZE-1].getsalesPerWeek() << endl << endl;		

	for (int s=0; s<SIZE; s++)
	{
		if(highest < daily[s])
		highest = daily[s];
		
		if (lowest > daily[s])
		lowest = daily[s];
	}
	
	Cafe[SIZE-1].SetHighest(highest);
	Cafe[SIZE-1].SetLowest(lowest);
	Cafe[SIZE-1].print();	 
}
