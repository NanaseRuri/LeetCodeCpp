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

class Solution2170MinimumOperations
{
public:
	int minimumOperations(vector<int>& nums) {
		unordered_map<int, int> oddCount;
		unordered_map<int, int> evenCount;

		int numsSize = nums.size();
		for (int i = 0; i < numsSize; i += 2)
		{
			oddCount[nums[i]] += 1;
		}
		for (int i = 1; i < numsSize; i += 2)
		{
			evenCount[nums[i]] += 1;
		}

		int maxOdd = 0;
		int maxOddCount1 = 0;
		for (auto& pair : oddCount)
		{
			if (pair.second > maxOddCount1) {
				maxOdd = pair.first;
				maxOddCount1 = pair.second;
			}
		}

		int maxEven = 0;
		int maxEvenCount1 = 0;
		for (auto& pair : evenCount)
		{
			if (pair.second > maxEvenCount1) {
				maxEven = pair.first;
				maxEvenCount1 = pair.second;
			}
		}

		if (maxOdd == maxEven) {
			oddCount.erase(maxOdd);
			evenCount.erase(maxEven);

			int maxOddCount2 = 0;
			int maxEvenCount2 = 0;
			for (auto& pair : oddCount)
			{
				if (pair.second > maxOddCount2) {
					maxOddCount2 = pair.second;
				}
			}

			for (auto& pair : evenCount)
			{
				if (pair.second > maxEvenCount2) {
					maxEvenCount2 = pair.second;
				}
			}

			return numsSize - max(maxOddCount1 + maxEvenCount2, maxOddCount2 + maxEvenCount1);
		}
		else {
			return numsSize - maxOddCount1 - maxEvenCount1;
		}
	}
};

//int main() {
//	Solution2170MinimumOperations solution;
//	vector<int> nums1{ 3,1,3,2,4,3 };
//	vector<int> nums2{ 1,2,2,2,2 };
//	vector<int> nums3{ 1, 3, 4, 3, 3, 2, 3, 3, 2, 2, 3 };
//	solution.minimumOperations(nums1);
//	solution.minimumOperations(nums2);
//	solution.minimumOperations(nums3);
//}