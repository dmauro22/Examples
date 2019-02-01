class Solution:
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        #for i in range(nums.len()):
        #    print(i)
        
        i = 0
        
        size = len(nums)
        
        while i < size - 1:
            j = i + 1
            while j < size:
                if (nums[i] + nums[j] == target):
                    sol = [i,j]
                    return sol
                j += 1
            i += 1
  
