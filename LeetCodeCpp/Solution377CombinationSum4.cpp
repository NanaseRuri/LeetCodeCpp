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

using namespace std;

class Solution377CombinationSum4
{
public:
	int combinationSum4(vector<int>& nums, int target) {
		vector<int> dp(target + 1);
		dp[0] = 1;

		for (int j = 1; j <= target; j++)
		{
			for (auto& num : nums)
			{
				if (num <= j) {
					dp[j] += dp[j - num];
				}				
			}
		}

		return dp[target];
	}
};

//int main() {
//	Solution377CombinationSum4 solution;
//
//	vector<int> nums1{ 1,2,3 };
//	vector<int> nums2{ 9 };
//
//	int target1 = 4;
//	int target2 = 3;
//	solution.combinationSum4(nums1, target1);
//	solution.combinationSum4(nums2, target2);
//}