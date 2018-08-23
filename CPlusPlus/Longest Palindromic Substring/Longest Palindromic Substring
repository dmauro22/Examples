class Solution
{
public:
	bool match(string checkMe, int a, int b)
	{
		int start = a;
		int end = b;

		while (start <= end)
		{
			if (checkMe[start] == checkMe[end])
			{
				start++;
				end--;
			}
			else
				return false;
		}
		return true;
	}
	string longestPalindrome(string s)
	{
		string sTest = s;
		bool palpal = false;
		string answer{""};
		int maxLength = 0;
		int count = 1;

        if (s.length() == 1)
			return sTest;
        
        if (s.length() == 2 && s[0] != s[1])
			return sTest.erase(1);
		
        
		for (int i = 0; i < s.length(); i++)			// Index where we'll start checking
		{
			int start = 0;
			int end = s.length() - i;
			while (end < s.length())
			{
				palpal = match(sTest, start, end);
				if (palpal)
				{
					answer.append(sTest, start, s.length() - i + 1);
					return answer;
				}
				start++;
				end++;
			}
		}
        
		if (sTest.length() > 0)
		{
			int temp = sTest.length() - 1;
			return sTest.erase(1, temp);
		}
		else
			return "";

	}
};
