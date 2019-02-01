class Solution 
{
public:
    string longestCommonPrefix(vector<string>& strs) 
    {
        // Check for an empty vector
        if (strs.empty())
        {
            return "";
        }
        
        // Initialize return value
        string common = "";
        
        // Flag to control 'while' loop
        bool cont = true;
        int i = 0;
        
        int vecSize = strs.size();
        
        // One word vector matches itself
        if (vecSize == 1)
        {
            return strs[0];
        }
        
        while (cont)
        {
            char temp = strs[0][i];
            for (int j = 1; j < vecSize; j++)
            {
                if (strs[j][i] == temp)
                {}
                else
                {
                    cont = false;
                    break;
                }
            }
            if (cont)
            {
                common += temp;
                i++;
            }
        }
        return common;
    }
};
