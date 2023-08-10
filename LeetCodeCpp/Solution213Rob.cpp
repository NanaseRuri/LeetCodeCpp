#include "stdafx.h"

using namespace std;

class Solution213Rob
{
private:
	int RobRange(vector<int>& nums, int left, int right) {
		int first = nums[left];
		int second = max(nums[left], nums[left + 1]);
		for (int i = left + 2; i <= right; i++)
		{
			int temp = second;
			second = max(first + nums[i], second);
			first = temp;
		}
		return second;
	}

public:
	int rob(vector<int>& nums) {
		int numsSize = nums.size();
		if (numsSize == 1)
		{
			return nums[0];
		}
		if (numsSize == 2) {
			return max(nums[0], nums[1]);
		}

		return max(RobRange(nums, 0, numsSize - 2), RobRange(nums, 1, numsSize - 1));
	}
};

//int main() {
//	Solution213Rob solution;
//
//	vector<int> nums1{ 1,3,1,3,100 };
//	vector<int> nums2{ 2,1,1,2 };
//	solution.rob(nums1);
//	solution.rob(nums2);
//}
