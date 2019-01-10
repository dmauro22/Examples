// This solution accepts a Roman numeral in the form of a string and returns an integer
// representing the Roman numeral in integer format

class Solution
{
public:
	int romanToInt(string s)
	{	
		string roman = s;
		int digit = 0;
	
		while (roman.size() > 0)
		{
			if (roman[0] == 'I')
			{
				if (roman[1] == 'X')
				{
					digit += 9;
					roman.erase(0, 2);
				}
				else if (roman[1] == 'V')
				{
					digit += 4;
					roman.erase(0, 2);
				}
				else
				{
					digit += 1;
					roman.erase(roman.begin());
				}
			}

			else if (roman[0] == 'V')
			{
				digit += 5;
				roman.erase(roman.begin());
			}

			if (roman[0] == 'X')
			{
				if (roman[1] == 'C')
				{
					digit += 90;
					roman.erase(0, 2);
				}
				else if (roman[1] == 'L')
				{
					digit += 40;
					roman.erase(0, 2);
				}
				else
				{
					digit += 10;
					roman.erase(roman.begin());
				}
			}

			else if (roman[0] == 'L')
			{
				digit += 50;
				roman.erase(roman.begin());
			}

			if (roman[0] == 'C')
			{
				if (roman[1] == 'M')
				{
					digit += 900;
					roman.erase(0, 2);
				}
				else if (roman[1] == 'D')
				{
					digit += 400;
					roman.erase(0, 2);
				}
				else
				{
					digit += 100;
					roman.erase(roman.begin());
				}
			}

			else if (roman[0] == 'D')
			{
				digit += 500;
				roman.erase(roman.begin());
			}

			else if (roman[0] == 'M')
			{
				digit += 1000;
				roman.erase(roman.begin());
			}
		}

		return digit;
	}
};
