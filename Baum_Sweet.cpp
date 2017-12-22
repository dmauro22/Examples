//******************************************************************
// Baum Sweet Sequence
//
//
//
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
	int j = 1;
	int cont = 1;
	int i;
	int k;


	cout << "Enter base nummber: ";
	cin >> baseNum;

	j = 0;

	while (baseNum > pow(2, j))
	{
		j++;
	}
		//cout << endl << "you need 2 to the :" << j << " spaces" << endl;
		//cout << endl << "Again? 1 to repeat: ";
		//cin >> cont;
	cout << endl << "you need 2 to the " << j << " spaces" << endl;
	cout << "Which equals " << pow(2, j) << " spaces" << endl;
 

	cout << baum[0] << endl;
	cout << baum[1] << endl;
	cout << baum[2] << endl;
	cout << baum[3] << endl;
	//cout << baum.length() << endl;

	//start = baum.length() / 2;

	//cout << start << endl;

	i = 2;

	while (baum.length() < pow(2,j))
	{
		while (i < pow(2, j))
		{
			//cout << "test" << endl;
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


		//i *= 2;
		//baum.append("1");
	}

	cout << baum << endl;

	for (k = 0; k < baseNum; k++)
		cout << baum[k] << ",";
	k++;
	cout << baum[k];

	cout << endl;

	system("pause");

	return 0;
}
