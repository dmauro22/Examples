class Solution 
{
public:
    bool isValid(string s) 
    {
        string storage = "";
        
        int size = s.length();
        
            
        for(int i = 0; i < size; i++)
        {
            if (s[i] == ')')
            {
                if (storage.back() == '(')
                    storage.pop_back();
                else
                    return 0;
                
            }
            
            else if (s[i] == '}')
            {
                if (storage.back() == '{')
                    storage.pop_back();
                else
                    return 0;
            }
             
            else if (s[i] == ']')
            {
                if (storage.back() == '[')
                    storage.pop_back();
                else
                    return 0;
                
            }
            
            else
            {
                storage.push_back(s[i]);   
            }
        }
        
        if (storage.length() > 0)
            return 0;
        
        return 1;
    }
};
