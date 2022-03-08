#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <limits>
#include <stack>
#include <queue>
#include <unordered_set>
#include "ListNode.h"
#include "TreeNode.h"
#include "Node.h"
#include <set>

class Solution918MaxSubarraySumCircular
{
public:
	int maxSubarraySumCircular(vector<int>& nums) {
		int numsSize = nums.size();
		if (numsSize == 1) {
			return nums[0];
		}

		int dp = nums[0];
		int maxValue = dp;
		int sum = dp;
		int minValue = 0;
		
		for (int i = 1; i < numsSize; i++)
		{
			sum += nums[i];
			dp = nums[i] + max(dp, 0);
			maxValue = max(dp, maxValue);
		}
		dp = nums[0];

		for (int i = 1; i < numsSize - 1; i++) {
			dp = nums[i] + min(0, dp);
			minValue = min(dp, minValue);
		}

		return max(maxValue, sum - minValue);
	}
};

//int main() {
//	vector<int> nums1{ 1,-2,3,-2 };
//	vector<int> nums2{ 5,-3,5 };
//	vector<int> nums3{ 3,-2,2,-3 };
//
//	Solution918MaxSubarraySumCircular solution;
//	solution.maxSubarraySumCircular(nums1);
//	solution.maxSubarraySumCircular(nums2);
//	solution.maxSubarraySumCircular(nums3);
//}