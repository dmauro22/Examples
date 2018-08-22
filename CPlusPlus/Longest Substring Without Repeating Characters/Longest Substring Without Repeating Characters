class Solution
{
public:
	int lengthOfLongestSubstring(string s)
	{
		string walker;  // It 'walks' the length of the other string
		int maxUnique = 0;
		int found = 0;

		for (int i = 0; i < s.length(); i++)
		{
			found = walker.find(s[i]);
			walker += s[i];

			if (found != -1)
			{
				if (found == 0)
					walker.erase(0, 1);
				else
					walker.erase(0, found + 1);
			}

			if (maxUnique < walker.length())
				maxUnique = walker.length();


		}
		return maxUnique;

	}
};
