#include "stdafx.h"

using namespace std;

class Solution264NthUglyNumber
{
public:
	int missingNumber(vector<int>& nums) {
		int numsSize = nums.size();
		for (int i = 0; i < numsSize; i++)
		{
			while (nums[i] != i && nums[i] < numsSize) {
				swap(nums[i], nums[nums[i]]);
			}
		}

		for (int i = 0; i < numsSize; i++)
		{
			if (nums[i] != i) {
				return i;
			}
		}
		return numsSize;
	}
	int missingNumber1(vector<int>& nums) {
		int numsSize = nums.size();
		int sum = numsSize * (numsSize + 1) / 2;
		for (int i = 0; i < numsSize; i++) {
			sum -= nums[i];
		}
		return sum;
	}
	int missingNumber2(vector<int>& nums) {
		int numsSize = nums.size();
		int xOrSum = 0;
		for (int i = 0; i <= numsSize; i++)
		{
			xOrSum ^= i;
		}

		for (auto& num : nums)
		{
			xOrSum ^= num;
		}
		return xOrSum;
	}
};
