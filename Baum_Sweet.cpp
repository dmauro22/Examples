///******************************************************************
// Baum Sweet Sequence
//
// Prompts user to enter a positive integer and calculates 
// the Baum-Sweet sequence from 0 to that number
// 
//******************************************************************

#include <iostream>	
#include <string>
#include <cmath>

using namespace std;

int main()
{
	// Variable declarations

	string baum = "1101";		// First 4 elements of Baum-Sweet sequence
	int baseNum;			// number to calculate up to
	int i = 2;				// array element marker

	cout << "Enter base nummber: ";
	cin >> baseNum;

	// Calculate Baum-Sweet sequence
	while (i < baseNum)
	{
		if (baum[i] == '0')
			if (baum[i + 1] == '0')
			{
				baum.append("0000");
			}
			else
			{
				baum.append("1001");
			}
		else
			if (baum[i + 1] == '0')
			{
				baum.append("0100");
			}
			else
			{
				baum.append("1101");
			}
		i += 2;
	}

	// Output results
	for (int k = 0; k <= baseNum; k++)
		cout << baum[k] << " ";
	
	cout << endl;

	system("pause");

	return 0;
}

