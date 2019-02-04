class Solution:
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        
        if not s:
            return 0

        maxLetters = 0
        size = len(s)
        index = 0
        found = 0
        
        wordMap = ""
        
        while index < size:
            
            found = wordMap.find(s[index])

            if not found == -1:
                wordMap = wordMap[found+1:]
            
            wordMap += (s[index])
            
            length = len(wordMap)
            
            if length > maxLetters:
                maxLetters = length
                
            index += 1
            
        return maxLetters
        
