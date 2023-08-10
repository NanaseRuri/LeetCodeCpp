#include "stdafx.h"

using namespace std;

class Solution080RemoveDuplicates
{
public:
	int removeDuplicates(vector<int>& nums) {
		int lastValue = nums[0];
		bool repeat = false;
		int numsSize = nums.size();
		int left = 1;
		for (int right = 1; right < numsSize; right++)
		{
			if (nums[right] != lastValue) {
				lastValue = nums[right];
				nums[left] = nums[right];
				repeat = false;
				left++;
			}
			else if (!repeat) {
				nums[left] = nums[right];
				repeat = true;
				left++;
			}
		}

		return left;
	}
};
