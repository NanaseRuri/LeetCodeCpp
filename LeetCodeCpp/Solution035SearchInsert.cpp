#include "stdafx.h"

using namespace std;

class Solution035SearchInsert {
public:
	int searchInsert(vector<int>& nums, int target) {
		int left = 0;
		int right = nums.size() - 1;
		int middle;
		while (left <= right)
		{
			middle = (left + right) / 2;
			if (nums[middle] == target) {
				return middle;
			}
			else if (nums[middle] < target) {
				left = middle + 1;
			}
			else {
				right = middle - 1;
			}
		}

		return left;
	}
};

//int main() {
//	Solution035SearchInsert solution;
//	vector<int> nums1 = { 5,7,8,10 };
//	vector<int> nums2 = { 5,7,8,10 };
//	vector<int> nums3 = {};
//	vector<int> nums4 = { 5,7,8,10,11 };
//	vector<int> nums5 = { 1,3,5,6 };
//	vector<int> nums6 = { 1,3,5,6 };
//	vector<int> nums7 = { 1,3,5,6 };
//	vector<int> nums8 = { 1,3,5,6 };
//
//	int target1 = 8;
//	int target2 = 6;
//	int target3 = 0;
//	int target4 = 11;
//	int target5 = 5;
//	int target6 = 6;
//	int target7 = 7;
//	int target8 = 0;
//
//	cout << solution.searchInsert(nums1, target1) << endl;
//	cout << solution.searchInsert(nums2, target2) << endl;
//	cout << solution.searchInsert(nums3, target3) << endl;
//	cout << solution.searchInsert(nums4, target4) << endl;
//	cout << solution.searchInsert(nums5, target5) << endl;
//	cout << solution.searchInsert(nums6, target6) << endl;
//	cout << solution.searchInsert(nums7, target7) << endl;
//	cout << solution.searchInsert(nums8, target8) << endl;
//}
