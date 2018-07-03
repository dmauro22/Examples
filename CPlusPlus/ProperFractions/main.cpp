
#include <iostream>
#include <vector>
#include <iomanip>
#include "ProperFraction.h"

using namespace std;

int main()
{
	int numerator;
	int denominator;

	cout << "Fraction Functions, here we go" << endl << endl;

	Proper TheFraction;

	cout << "Enter a numerator: ";
	cin >> numerator;
	TheFraction.setNum(numerator);

	cout << "Enter a denominator: ";
	cin >> denominator;
	TheFraction.setDen(denominator);

	Proper NewFraction = TheFraction;

	Proper MyFraction(NewFraction);

	cout << endl;

	cout << "Original fraction: ";
	TheFraction.print();
	cout << "Copied fraction using '=': ";
	NewFraction.print();
	cout << "Second copied fraction using '()': ";
	MyFraction.print();

	Proper copyFraction = TheFraction.reduce(TheFraction);

	cout << endl;

	cout << "Reducible (1 = reducible, 0 = not reducible): " << TheFraction.reducible(TheFraction) << endl << endl;

	cout << "Reduced Copy: ";
	copyFraction.print();

	cout << "Unchanged Original: ";
	TheFraction.print();

	TheFraction.reduceme(TheFraction);

	cout << "Original Fraction, reduced: ";

	TheFraction.print();

	cout << endl;

	Proper Fraction2;

	cout << "Enter a new numerator: ";
	cin >> numerator;
	Fraction2.setNum(numerator);

	cout << "Enter a new denominator: ";
	cin >> denominator;
	Fraction2.setDen(denominator);

	cout << "\n";

	Proper RandoFract = add(TheFraction, Fraction2);

	cout << "Added Fractions: ";
	
	RandoFract.print();

	bool lt = lessthan(TheFraction, Fraction2);

	if (lt == 1)
		cout << "Fraction one is greater than fraction 2" << endl;
	else
		cout << "Fraction one is less than fraction 2" << endl;

	system("pause");

	return 0;
}

