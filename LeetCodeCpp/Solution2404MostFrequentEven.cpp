#include "stdafx.h"

using namespace std;
class Solution2404MostFrequentEven
{
public:
	int mostFrequentEven(vector<int>& nums) {
		int result = -1;
		int count = 0;
		unordered_map<int, int> numsCount;
		for (auto num : nums)
		{
			numsCount[num]++;
			if (num % 2 == 0) {
				if (numsCount[num] > count) {
					result = num;
					count = numsCount[num];
				}
				else if (num < result && numsCount[num] == count) {
					result = num; 
				}
			}
		}

		return result;
	}
};
