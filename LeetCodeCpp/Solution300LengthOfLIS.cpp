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

class Solution300LengthOfLIS
{
public:
	int lengthOfLIS2(vector<int>& nums) {
		int numsSize = nums.size();
		if (numsSize == 0) {
			return 0;
		}

		vector<int> dp(numsSize + 1);
		dp[0] = -5000;
		int length = 0;
		for (int i = 0; i < numsSize; i++) {
			if (dp[length] < nums[i]) {
				++length;
				dp[length] = nums[i];
			}
			else {
				int left = 0;
				int right = length;
				while (left <= right) {
					int middle = (left + right) / 2;
					if (dp[middle] < nums[i]) {
						left = middle + 1;
					}
					else {
						right = middle - 1;
					}
				}
				dp[left] = nums[i];
			}
		}

		return length;
	}

	int lengthOfLIS1(vector<int>& nums) {
		int numsSize = nums.size();
		vector<int> dp(numsSize);
		dp[0] = 1;

		for (int i = 1; i < numsSize; i++)
		{
			dp[i] = 1;
			for (int j = 0; j < i; j++)
			{
				if (nums[i] > nums[j]) {
					dp[i] = max(dp[i], dp[j] + 1);
				}
			}
		}

		return *max_element(dp.begin(), dp.end());
	}

	int lengthOfLIS(vector<int>& nums) {
		int length = 1;
		int numsSize = nums.size();
		vector<int> dp(numsSize + 1);
		dp[length] = nums[0];
		for (int i = 1; i < numsSize; i++)
		{
			if (nums[i] > dp[length]) {
				dp[++length] = nums[i];
			}
			else {
				int left = 1;
				int right = length;
				int pos = 0;
				while (left <= right)
				{
					int middle = (left + right) / 2;
					if (dp[middle] < nums[i]) {
						pos = middle;
						left = middle + 1;
					}
					else {
						right = middle - 1;
					}
				}
				dp[pos + 1] = nums[i];
			}
		}

		return length;
	}
};

//int main() {
//	Solution300LengthOfLIS solution;
//	vector<int> nums1{ 4,10,4,3,8,9 };
//	solution.lengthOfLIS(nums1);
//}