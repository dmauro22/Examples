// From Leetcode #1
//
// Given an array of integers, return indices of the two numbers such that they add up to a specific target
//
// You may assume that each input would have exactly one solution, and you may not use the same element twice
//
// Brute force solution


#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	vector<int> twoSum(vector<int>& nums, int target)
	{
		vector<int> elements{ 0,0 };
		for (int i = 0; i < nums.size() - 1; i++)
		{
			for (int j = i + 1; j < nums.size(); j++)
			{
				if (nums[i] + nums[j] == target)
				{
					elements[0] = i;
					elements[1] = j;
					return elements;
				}
			}
		}
	}
};

