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

class Solution740DeleteAndEarn
{
public:
	int deleteAndEarn(vector<int>& nums) {
		int* numsSum = new int[10002]{};

		for (auto& num : nums)
		{
			numsSum[num] += num;
		}

		int dp[2] = {};

		for (int i = 1; i <= 10000; i++)
		{
			dp[i % 2] = max(dp[i % 2] + numsSum[i], dp[(i + 1) % 2]);
		}

		return max(dp[0], dp[1]);
	}
};

//int main() {
//	vector<int> nums1{ 3,4,2 };
//	vector<int> nums2{ 2,2,3,3,3,4 };
//	Solution740DeleteAndEarn solution;
//	solution.deleteAndEarn(nums1);
//	solution.deleteAndEarn(nums2);
//}