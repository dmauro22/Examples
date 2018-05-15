#include "Fraction.h"

using namespace std;

#include <iostream>

// This just has the function definitions
// The parts of the class and the names of
// the functions go in the .h file


// Math for fraction reduction
int GCD(int a, int b)
{
	while (true)
	{
		a = a % b;
		if (a == 0) return b;
		b = b % a;
		if (b == 0) return a;
	}
}

// Math to calculate lowest common multiple
int LCM(int a, int b)
{
	return((a*b) / GCD(a, b));
}

// Default constructor
Fraction::Fraction()
{

}


// Overloaded constructor
Fraction::Fraction(int n, int d)
{
	setNum(n);
	setDen(d);
}


// Numerator setter
void Fraction::setNum(int nu)
{
	num = nu;
}


// Denominator setter with range testing
void Fraction::setDen(int de)
{
	while (de < 1)
	{
		using std::cout;
		using std::endl;
		cout << "Denominator must be a positive integer" << endl;
		cout << "Enter a denominator: ";
		cin >> de;
	}
	den = de;
}


// Display the numerator and denominator of the fraction
void Fraction::print()
{
	std::cout << num << "/" << den << endl;
}


// Check to see whether the fraction can be reduced
bool Fraction::reducible(Fraction)
{
	bool red = false;
	int a;
	int b;
	a = num;
	b = den;

	int div = GCD(a, b);	// Greatest common divisor

	red = (div > 1);

	return red;
}


// Reduces the fraction passed to it
void Fraction::reduceme(Fraction)
{
	int di = GCD(num, den);
	num /= di;
	den /= di;
}


// Returns a reduced copy of the fraction without changing the original
Fraction Fraction::reduce(Fraction old)
{
	Fraction newFraction(old);
	newFraction.reduceme(newFraction);
	return newFraction;
}


// Destructor
Fraction::~Fraction()
{
}



// Non member functions


// Adds two fractions 
Fraction add(Fraction x, Fraction y)
{
	Fraction xCopy;
	Fraction yCopy;

	int lcm = LCM(x.den, y.den);

	cout << "The lowest common multiple is: " << lcm << endl;

	int factorX = lcm / x.den;
	int factorY = lcm / y.den;

	xCopy.setNum(x.num * factorX);
	xCopy.setDen(x.den * factorX);

	yCopy.setNum(y.num * factorY);
	yCopy.setDen(y.den * factorY);

	xCopy.setNum(xCopy.num + yCopy.num);

	xCopy.reduceme(xCopy);

	cout << "Added fraction, reduced: ";

	xCopy.print();

	cout << "\n";

	return xCopy;
}


// Compares fractions to see if one is less than the other
bool lessthan(Fraction &x, Fraction &y)
{
	bool less = 0;

	Fraction xCopy = x;
	Fraction yCopy = y;

	if (x.den != y.den)
	{
		//Denominators not equal, we must find a lowest common multiple

		xCopy.setNum(x.num * y.den);
		xCopy.setDen(x.den * y.den);

		yCopy.setNum(y.num * x.den);
		yCopy.setDen(y.den * x.den);

	}

	if (xCopy.num > yCopy.num)
		less = 1;
	else
		less = 0;

	return less;
}
