#pragma once

#ifndef _FRACTION_
#define _FRACTION_

using namespace std;

class Fraction
{
	friend bool lessthan(Fraction &, Fraction &);
	friend Fraction add(Fraction, Fraction);
private:
	int num;
	int den;

public:
	Fraction();					// Blank default constructor
	Fraction(int, int);			// Overloaded constructor
	void setNum(int);			// Sets the numerator
	void setDen(int);			// Sets the denominator
	void print();				// Prints the fraction
	bool reducible(Fraction);	// Checks to see whether the fraction can be reduced
	void reduceme(Fraction);	// Reduces the original fraction
	Fraction reduce(Fraction);	// Returns a reduced copy of the fraction without changing the original
	~Fraction();
};

#endif  
