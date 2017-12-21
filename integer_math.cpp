//******************************************************************
// Simple integer math to display function modularity
//
// This program will be used to start my project
//******************************************************************

#include <iostream>				// for cin, cout, endl

using namespace std;

// Declare function prototypes

int sumnum(int, int);
int prodnum(int, int);
int avgnum(int, int);
int divnum(int, int);
int modnum(int, int);

int main()					
{ 
// Declare variables
	int num1 = 0;
	int num2 = 0;
	int sums = 0;
	int prod = 0;
	int avg = 0;
	int div = 0;
	int mod = 0;
	
// Get values for first two integers

	cout << "Enter any integer: ";
	cin >> num1;

	cout << "Enter another integer: ";
	cin >> num2;

// Calculate sum of integers

	sums = sumnum(num1, num2);

// Calculate product of integers
	
	prod = prodnum(num1, num2);
	
// Calculate average of integers

	avg = avgnum(num1, num2);
	
// Calculate integer 1 divided by integer 2

	div = divnum(num1, num2);
	
// Calculate remainder of integer 1 divided by integer 2

	mod = modnum(num1, num2);
	
// Print results of calculations

	cout << "Integer 1 = " << num1 << endl;
	
	cout << "Integer 2 = " << num2 << endl;
	
	cout << "The sum = " << sums << endl;
	
	cout << "The product = " << prod << endl;

	cout << "The average = " << avg << endl;
		
	cout << "The quotient = " << div << endl;

	cout << "The modulus = " << mod << endl;
	
	return 0;
	

}

int sumnum(int num1, int num2)
{
	int sums = num1 + num2;
	return sums;
}


int prodnum(int num1, int num2)
{
	int prod = num1 * num2;
	return prod;
}


int avgnum(int num1, int num2)
{
	int avg = (num1 + num2) / 2;
	return avg;
}

int divnum(int num1, int num2)

{
	int div = num1 / num2;
	return div;
}

int modnum(int num1, int num2)
{
	int mod = num1 % num2;
	return mod;
}

