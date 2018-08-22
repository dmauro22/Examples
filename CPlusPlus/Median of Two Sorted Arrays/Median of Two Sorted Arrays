class Solution
{
public:
	double indexCalc(vector<int>& n3)
	{
		double med = 0;

		if (n3.size() % 2 == 1)   // Odd sized array, can take the exact middle
		{
			int OddIndex = n3.size() / 2;
			return n3[OddIndex];
		}
		else                        // Even sized array, need to take two middle
		{
			int EvenIndex1 = n3.size() / 2;
			int EvenIndex2 = ((n3.size() / 2) - 1);
			return (n3[EvenIndex1] + n3[EvenIndex2]) / 2.0;
		}

		//return med;
	}

	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
	{
		vector <int> n1 = nums1;
		vector <int> n2 = nums2;
		vector <int> nums3{};

		while (!n1.empty() || !n2.empty())
		{
			if (n1.empty())
			{
				nums3.insert(nums3.end(), n2.begin(), n2.end());
				return indexCalc(nums3);
			}

			else if (n2.empty())
			{
				nums3.insert(nums3.end(), n1.begin(), n1.end());
				return indexCalc(nums3);
			}

			else
			{
				if (n1[0] < n2[0])
				{
					nums3.push_back(n1[0]);
					n1.erase(n1.begin());
				}

				else
				{
					nums3.push_back(n2[0]);
					n2.erase(n2.begin());
				}
			}
		}
		return indexCalc(nums3);
	}

};
