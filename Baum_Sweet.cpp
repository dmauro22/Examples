//******************************************************************
// Baum Sweet Sequence
//
// Prompts user to enter a positive integer and calculates 
// the Baum-Sweet sequence from 0 to that number
//
// https://en.wikipedia.org/wiki/Baum-Sweet_sequence
// 
//******************************************************************

#include <iostream>	
#include <string>
#include <cmath>

using namespace std;

int main()
{
	// Variable declarations
	string baum = "1101";
	int baseNum;				// Number to calculate sequence to
	int i = 2;				// array element marker

	cout << "Enter base nummber: ";
	cin >> baseNum;

	// Calculate Baum-Sweet sequence
	while (i < baseNum)
	{
		if (baum[i] == '0')			
			if (baum[i + 1] == '0')    
				baum.append("0000");	// 00 yields 0000
			else
				baum.append("1001");	// 01 yields 1001

		else
			if (baum[i + 1] == '0')
				baum.append("0100");	// 10 yields 0100
			else
				baum.append("1101");	// 11 yields 1101
		i += 2;					// Move to the next two elements
	}

	// Output results
	for (int k = 0; k <= baseNum; k++)
		cout << baum[k] << " ";
	
	cout << endl;

	system("pause");

	return 0;
}
