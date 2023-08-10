#include "stdafx.h"

class Solution976LargestPerimeter
{
public:
	int largestPerimeter(vector<int>& nums) {
		sort(nums.begin(), nums.end());

		int perimeter = 0;

		for (int i = nums.size() - 1; i >= 2; --i) {
			if (nums[i] < nums[i - 1] + nums[i - 2]) {
				perimeter = nums[i] + nums[i - 1] + nums[i - 2];
				break;
			}
		}

		return perimeter;
	}
};
