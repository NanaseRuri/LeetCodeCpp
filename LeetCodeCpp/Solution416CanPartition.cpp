#include "stdafx.h"

class Solution416CanPartition {
public:
	bool canPartition(vector<int>& nums) {
		int numsSize = nums.size();
		if (numsSize < 2) {
			return false;
		}

		int sum = accumulate(nums.begin(), nums.end(), 0);
		if (sum & 1) {
			return false;
		}

		int target = sum / 2;
		int maxNum = *max_element(nums.begin(), nums.end());
		if (target < maxNum) {
			return false;
		}

		vector<bool> dp(target + 1);
		dp[0] = true;
		for (auto& num : nums) {
			for (int j = target; j >= num; --j) {
				dp[j] = dp[j] || dp[j - num];
			}
		}

		return dp[target];
	}
};
