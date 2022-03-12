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

class Solution413NumberOfArithmeticSlices {
public:
	int numberOfArithmeticSlices(vector<int>& nums) {
		int result = 0;
		int left = 0;
		int numsSize = nums.size();
		int leftLimit = numsSize - 3;
		while (left <= leftLimit) {
			int right = left + 1;
			int gap = nums[right] - nums[left];
			while (right < numsSize) {
				if (nums[right] - nums[right - 1] == gap) {
					right++;
				}
				else {
					break;
				}
			}

			if (right >= left + 2) {
				result += (right - left - 1) * (right - left - 2) / 2;
			}
			left = right - 1;
		}

		return result;
	}

	int numberOfArithmeticSlices1(vector<int>& nums) {
		int numsSize = nums.size();
		if (numsSize <= 2) {
			return 0;
		}

		int result = 0;

		int delta = nums[0] - nums[1];
		int time = 0;

		for (int i = 2; i < numsSize; i++)
		{
			if (nums[i - 1] - nums[i] == delta) {
				++time;
			}
			else {
				delta = nums[i - 1] - nums[i];
				time = 0;
			}
			result += time;
		}

		return result;
	}
};

//int main() {
//	Solution413NumberOfArithmeticSlices solution;
//	vector<int> nums1{ 1,2,3,4 };
//	vector<int> nums2{ 1 };
//	vector<int> nums3{ 1,2,3,8,9,10 };
//	solution.numberOfArithmeticSlices(nums1);
//	solution.numberOfArithmeticSlices(nums2);
//	solution.numberOfArithmeticSlices(nums3);
//}