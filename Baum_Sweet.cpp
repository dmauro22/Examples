//******************************************************************
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
	string baum = "1101";
	int start;
	int baseNum;
	int j = 0;
	int i;
	int k;

	cout << "Enter base nummber: ";
	cin >> baseNum;

	while (baseNum > pow(2, j))
		j++;
	
	i = 2;
	
	while (baum.length() < pow(2,j))
	{
		while (i < pow(2, j))
		{
			if (baum[i] == '0')
				if (baum[i + 1] == '0')
				{
					baum.append("0000");
					cout << "0 0" << endl;
				}
				else
				{
					baum.append("1001");
					cout << "0 1" << endl;
				}
			else
				if (baum[i + 1] == '0')
				{
					baum.append("0100");
					cout << "1 0" << endl;
				}
				else
				{
					baum.append("1101");
					cout << "1 1" << endl;
				}
			i += 2;
		}
	}
	for (k = 0; k < baseNum; k++)
		cout << baum[k] << ",";
	k++;
	cout << baum[k];
	cout << endl;

	system("pause");

	return 0;
}
