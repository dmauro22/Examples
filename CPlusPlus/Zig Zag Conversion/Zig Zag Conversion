class Solution 
{
public:
    string convert(string s, int numRows) 
    {
        
    if (numRows < 1)
			return NULL;

		if (numRows == 1 || numRows >= s.length())
			return s;

		string converted{};

		int magNum = (numRows + numRows - 2);

		int magNumCom = 0;

		int last = 0;
			
		for (int i = 0; i < numRows; i++)
		{
			last = i;
			converted.push_back(s[last]);

			if (i == 0)
			{
				while (last + magNum < s.length())
				{
					last += magNum;
					converted.push_back(s[last]);
				}
			}

			else if (i == numRows - 1)
			{
				while (last + magNumCom < s.length())
				{
					last += magNumCom;
					converted.push_back(s[last]);
				}
			}

			else
			{
				bool flag = 1;
				while (last + magNum < s.length() && flag)
				{
					last += magNum;
					converted.push_back(s[last]);

					if (last + magNumCom < s.length())
					{
						last += magNumCom;
						converted.push_back(s[last]);
					}
					else
						flag = 0;
				}
			}

			magNum -= 2;
			magNumCom += 2;

		}

		return converted;
    }
};
