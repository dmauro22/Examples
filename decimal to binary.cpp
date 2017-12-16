//*******************************************************
// Decimal to Binary conversion:
//
// This program prompts user to input an integer, then
// calculates and returns the binary form of the integer.
// 
//*******************************************************

#include <iostream>	
#include <iomanip>          	 
#include <cstdlib>
#include <cmath>

using namespace std;

// Prototypes
int spacesNeeded(int);
void binaryCalc(int[], int, int);

int main()
{
	int theNumber;			// input number
	int *theBinary = NULL;		// binary equivalent
	int places;			// number of array slots needed
	char cont = 'y';		// Continue flag

	while (cont == 'y' || cont == 'Y')
	{
		theNumber = 0;
		places = 0;
		cout << "Enter a non-negative integer: ";
		cin >> theNumber;
		
		places = spacesNeeded(theNumber);

		theBinary = new int[places];

		binaryCalc(theBinary, places, theNumber);

		// Special case if input number is zero
		if (theNumber == 0)
		{
			places = 1;
			theBinary[0] = 0;
		}

		cout << "Binary form of " << theNumber << " is ";
		for (int i = 0; i < places; i++)
			cout << theBinary[i];
		cout << endl << endl << "Again?  Y for yes: ";
		cin >> cont;
		cout << endl;
	}

	delete[] theBinary;
	theBinary = nullptr;

	system("pause");
	return 0;
}

// Function that determines the number spaces needed to hold the binary number
int spacesNeeded(int mainNum)
{
	int slots = 0;
	while ((mainNum - pow(2, slots) + 1) > 0)
	{
		slots++;
	}
	return slots;
}

// Function to convert the decimal number to binary
void binaryCalc(int theBinary[], int places, int theNumber)
{
	for (int i = 0; i < places; i++)
	{
		if ((theNumber % int(pow(2, i + 1))) == 0)
		{
			theBinary[places - 1 - i] = 0;
		}
		else
		{
			theBinary[places - 1 - i] = 1;
			theNumber -= pow(2, i);
		}
	}
}
