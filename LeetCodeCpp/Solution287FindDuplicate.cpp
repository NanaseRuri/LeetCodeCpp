#include "stdafx.h"

using namespace std;

class Solution287FindDuplicate
{
public:
	int findDuplicate(vector<int>& nums) {
		int numsSize = nums.size();
		int left = 1;
		int right = numsSize - 1;
		int result = -1;

		while (left <= right)
		{
			int middle = (left + right) / 2;
			int count = 0;
			for (int i = 0; i < numsSize; i++)
			{
				if (nums[i] <= nums[middle]) {
					++count;
				}
			}
			if (count <= middle) {
				left = middle + 1;
			}
			else {
				right = middle - 1;
				result = middle;
			}
		}

		return result;
	}
	int findDuplicate1(vector<int>& nums) {
		int n = nums.size();
		int result = 0;
		int bitMax = 31;
		while (((n - 1) >> bitMax) == 0)
		{
			--bitMax;
		}
		for (int bit = 0; bit <= bitMax; bit++)
		{
			int x = 0;
			int y = 0;
			for (int i = 0; i < n; i++)
			{
				if (nums[i] & (1 << bit)) {
					++x;
				}
				if (i >= 1 && (i & (1 << bit))) {
					++y;
				}
			}

			if (x > y) {
				result |= 1 << bit;
			}
		}

		return result;
	}
	int findDuplicate2(vector<int>& nums) {
		int slow = 0;
		int fast = 0;
		do
		{
			slow = nums[slow];
			fast = nums[nums[fast]];
		} while (slow != fast);

		slow = 0;
		while (slow != fast)
		{
			slow = nums[slow];
			fast = nums[fast];
		}
		return slow;
	}
};

//int main() {
//	Solution287FindDuplicate solution;
//
//	vector<int> nums1{ 1,3,4,2,2 };
//	vector<int> nums2{ 2,2,2,2,2 };
//	solution.findDuplicate(nums1);
//	solution.findDuplicate(nums2);
//}
