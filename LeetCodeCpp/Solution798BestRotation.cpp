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

class Solution798BestRotation
{
public:
	int bestRotation(vector<int>& nums) {
		int n = nums.size();

		vector<int> diff(n);

		for (int i = 0; i < n; i++)
		{
			int low = (i + 1) % n;
			int high = (i - nums[i] + n + 1) % n;

			++diff[low];
			--diff[high];

			if (low >= high) {
				++diff[0];
			}
		}

		int bestIndex = 0;
		int maxScore = 0;
		int score = 0;
		for (int i = 0; i < n; i++)
		{
			score += diff[i];
			if (score > maxScore) {
				bestIndex = i;
				maxScore = score;
			}
		}

		return bestIndex;
	}

	int bestRotation1(vector<int>& nums) {
		int n = nums.size();
		int originValue = 0;

		for (int i = 0; i < n; i++)
		{
			if (nums[i] <= i) {
				++originValue;
			}
		}

		vector<int> steps(n, 0);
		for (int i = 0; i < n; i++)
		{
			if (nums[i] <= i) {
				steps[i - nums[i]]++;
			}
			else {
				steps[i + n - nums[i]]++;
			}
		}

		int ans = 0;
		int maxValue = originValue;

		for (int i = 1; i < n; i++)
		{
			originValue = originValue - steps[i - 1] + 1;
			if (originValue > maxValue) {
				ans = i;
				maxValue = originValue;
			}
		}

		return ans;
	}
};

//int main() {
//	Solution798BestRotation solution;
//
//	vector<int> nums1{ 2,3,1,4,0 };
//	vector<int> nums2{ 1,3,0,2,4 };
//	solution.bestRotation(nums1);
//	solution.bestRotation(nums2);
//	solution.bestRotation1(nums1);
//	solution.bestRotation1(nums2);
//}