//******************************************************************
// 
// Programmer: Daniel Mauro
// Completed : November 23, 2017
// 
// Shipping Service simulator
// Package weight must be greater than zero and less than or equal
// to 50.  No single side can be longer than 6, and the girth can
// be no biggger than 10.  Girth is calculated as the sum of the two 
// smallest sides times 2.
// There is an additional service charge if the ship location is out
// of state or out of country.
//******************************************************************

#include <iostream>			
#include <iomanip>          
#include <string>
#include <cstdlib>
#include <cmath>

using namespace std;

// Function prototypes
void packageInfo(int &weight, int &sideOne, int &sideTwo, int &sideThree);
int girthCalc(int sideOne, int sideTwo, int sideThree);
bool packageValidation(int weight, int sideOne, int sideTwo, int sideThree, int girth, char location);
void calcServCharge(char location, float &serviceCharge, string &state);
void printTranSummary(int transCount, string state, string status, int weight, int girth, float transactionCharge);
void printTotals(int goodTransCount, int badTransCount, float totalCharge);

int main()
{
	// Variable declarations
	char location = 'a';
	string state;
	string status;
	int weight;
	int sideOne;
	int sideTwo;
	int sideThree;
	int girth;
	int goodTransCount = 0;
	int badTransCount = 0;
	int transCount = 0;
	float serviceCharge = 0;
	float shipCharge = 0;
	float transactionCharge = 0;
	float totalCharge = 0;
	bool accept = true;
	int weightTable[] = { 0, 1, 2, 3, 5, 7, 10, 13, 16, 20, 25, 30, 35, 40, 45, 50 };
	float costTable[] = { 0, 1.50, 2.10, 4.00, 6.75, 9.90, 14.95, 19.40, 24.20, 27.30, 31.90, 38.50, 43.50, 44.80, 47.40, 55.20 };

	// Run transaction loop if exit status is false
	while (location != 'x' && location != 'X')
	{
		cout << "Welcome to Dan El Hombre Shipping Company" << endl;
		cout << "Enter delivery location" << endl;
		cout << "(T)exas, (O)ut of state, or (F)oreign: ";
		cin >> location;

		if (location != 'x' && location != 'X')
		{
			// Increment transaction number
			transCount++;

			// Get package details
			packageInfo(weight, sideOne, sideTwo, sideThree);

			// Calculate girth
			girth = girthCalc(sideOne, sideTwo, sideThree);

			// Check for shipment validity
			accept = packageValidation(weight, sideOne, sideTwo, sideThree, girth, location);

			// Calculate service charge and assign name to delivery 'state'
			calcServCharge(location, serviceCharge, state);

			// Determine shipping charge
			if (accept == true)
			{
				goodTransCount++;
				status = "Accept";

				// Loop to calculate shipping charge
				for (int i = 0; i < 16; i++)
					if (weightTable[i] < weight && weightTable[i + 1] >= weight)
						shipCharge = costTable[i + 1];
			}

			else if (accept == false)
			{
				badTransCount++;
				status = "Reject";
				transactionCharge = 0.0;
				shipCharge = 0.0;
			}

			// Add applicable fees to the transaction charge and to the running total
			transactionCharge += serviceCharge;
			transactionCharge += shipCharge;
			totalCharge += transactionCharge;

			// Display transaction summary
			printTranSummary(transCount, state, status, weight, girth, transactionCharge);

			// reset everything
			serviceCharge = 0;
			shipCharge = 0;
			transactionCharge = 0;
			state = "Unknown";
			accept = true;
		}

	} //End of transaction loop

	// Recap of all transaction totals
	printTotals(goodTransCount, badTransCount, totalCharge);

	system("pause");

	return 0;

} // End of program

// Function that sets package weight and dimensions
void packageInfo(int &weight, int &sideOne, int &sideTwo, int &sideThree)
{
	cout << "Enter package weight: ";
	cin >> weight;

	cout << "Enter package dimensions" << endl;

	cout << "Side 1: ";
	cin >> sideOne;

	cout << "Side 2: ";
	cin >> sideTwo;

	cout << "Side 3: ";
	cin >> sideThree;
}

// Function that calculates package girth
int girthCalc(int sideOne, int sideTwo, int sideThree)
{
	int bigSide;

	bigSide = sideOne;

	if (bigSide < sideTwo)
		bigSide = sideTwo;

	if (bigSide < sideThree)
		bigSide = sideThree;

	return (2 * (sideOne + sideTwo + sideThree - bigSide));
}

// Function that determines whether the package can be shipped
bool packageValidation(int weight, int sideOne, int sideTwo, int sideThree, int girth, char location)
{
	bool accept = true;

	if (weight <= 0 || weight > 50)
		accept = false;

	if (sideOne <= 0 || sideOne > 6)
		accept = false;

	if (sideTwo <= 0 || sideTwo > 6)
		accept = false;

	if (sideThree <= 0 || sideThree > 6)
		accept = false;

	if (girth > 10)
		accept = false;

	if (location != 'T' && location != 't' && location != 'O' && location != 'o' && location != 'F' && location != 'f')
		accept = false;

	return accept;
}

// Function to calculate service charge and assign name to delivery location
void calcServCharge(char location, float &serviceCharge, string &state)
{
	if (location == 'O' || location == 'o')
	{
		serviceCharge = 35.00;
		state = "Out of state";
	}

	if (location == 'F' || location == 'f')
	{
		serviceCharge = 40.00;
		state = "Foreign";
	}

	if (location == 'T' || location == 't')
	{
		serviceCharge = 0.0;
		state = "Texas";
	}
}

// Function that displays summary of individual transaction
void printTranSummary(int transCount, string state, string status, int weight, int girth, float transactionCharge)
{
	cout << endl;
	cout << "Transaction # " << transCount << endl;
	cout << "Location:     " << state << endl;
	cout << "Status:       " << status << endl;
	cout << "Weight:       " << weight << " pounds" << endl;
	cout << "Girth:        " << girth << " feet" << endl;
	cout << fixed << showpoint << setprecision(2) << setw(8) << "Cost:         $" << transactionCharge << endl << endl;
}

// Function that prints total transaction summary
void printTotals(int goodTransCount, int badTransCount, float totalCharge)
{
	cout << endl;
	cout << "Number of accepted packages: " << goodTransCount << endl;
	cout << "Number of rejected packages: " << badTransCount << endl;
	cout << "Total cost:                  $" << fixed << showpoint << setprecision(2) << totalCharge << endl << endl;
}
