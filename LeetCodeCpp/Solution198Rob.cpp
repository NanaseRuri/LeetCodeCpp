#include "stdafx.h"


using namespace std;

class Solution198Rob
{
public:
	int rob(vector<int>& nums) {
		int numsSize = nums.size();
		if (numsSize == 1) {
			return nums[0];
		}

		int* dp = new int[2]{};
		dp[0] = nums[0];
		dp[1] = max(nums[0],nums[1]);

		for (int i = 2; i < numsSize; i++)
		{
			dp[i % 2] = max(dp[i % 2] + nums[i], dp[(i + 1) % 2]);
		}

		return max(dp[0], dp[1]);
	}
};

//int main() {
//	Solution198Rob solution;
//	vector<int> nums1{ 1,2,3,1 };
//	vector<int> nums2{ 2,7,9,3,1 };
//	solution.rob(nums1);
//	solution.rob(nums2);
//}
