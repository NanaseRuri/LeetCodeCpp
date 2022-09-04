#include "stdafx.h"

class Solution961RepeatedNTimes
{
public:
	int repeatedNTimes(vector<int>& nums) {
		int candidate[3]{ INT32_MAX,INT32_MAX,INT32_MAX };
		int lastUpdateIndex = 0;

		for (auto& num : nums)
		{
			if (num == candidate[0] || num == candidate[1] || num == candidate[2]) {
				return num;
			}

			candidate[lastUpdateIndex % 3] = num;
			++lastUpdateIndex;
		}

		return -1;
	}

	int repeatedNTimes1(vector<int>& nums) {
		int numsSize = nums.size();
		mt19937 rand{ random_device()() };
		uniform_int_distribution<int> dis(0, nums.size() - 1);

		while (true) {
			int x = dis(rand);
			int y = dis(rand);
			if (x != y && nums[x] == nums[y]) {
				return nums[x];
			}
		}
	}
};