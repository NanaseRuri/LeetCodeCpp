#include "stdafx.h"

using namespace std;

class Solution033Search {
private:
	int BinarySearch(vector<int>& nums, int target, int left, int right) {
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

		return -1;
	}
public:
	int search(vector<int>& nums, int target) {
		int firstValue = nums[0];
		if (firstValue == target) {
			return 0;
		}

		int numSize = nums.size();
		int right = numSize - 1;

		int rotateCenter = -1;
		int left = 0;
		int middle;

		while (left <= right)
		{
			middle = (left + right) / 2;
			if (nums[middle] < firstValue) {
				if (nums[middle] < nums[middle - 1]) {
					rotateCenter = middle;
					break;
				}
				else {
					right = middle - 1;
				}
			}
			else {
				left = middle + 1;
			}
		}

		if (target < firstValue) {
			if (rotateCenter == -1) {
				return -1;
			}
			else {
				return BinarySearch(nums, target, rotateCenter, numSize - 1);
			}
		}
		else {
			if (rotateCenter == -1) {
				return BinarySearch(nums, target, 0, numSize - 1);
			}
			else {
				return BinarySearch(nums, target, 0, rotateCenter);
			}
		}
	}

	int search1(vector<int>& nums, int target) {
		int n = nums.size();
		if (n == 0) {
			return -1;
		}

		int left = 0;
		int right = n - 1;
		while (left <= right)
		{
			int middle = (left + right) / 2;
			if (nums[middle] == target) {
				return middle;
			}
			if (nums[0] <= nums[middle]) {
				if (nums[0] <= target && target < nums[middle]) {
					right = middle - 1;
				}
				else {
					left = middle + 1;
				}
			}
			else {
				if (nums[middle] < target && target <= nums[n - 1]) {
					left = middle + 1;
				}
				else {
					right = middle - 1;
				}
			}
		}
		return -1;
	}
};

//int main() {
//	Solution033Search solution;
//
//	vector<int> nums = { 4, 5, 6, 7, 0, 1, 2 };
//	int target = 0;
//	int target1 = 1;
//	int target4 = 5;
//	int target5 = 2;
//	vector<int> nums1 = { 0,1,2,3,4,5,6 };
//	int target2 = 1;
//	vector<int> nums2 = { 1 };
//	int target3 = 1;
//
//	cout << solution.search(nums, target) << endl;
//	cout << solution.search(nums, target1) << endl;
//	cout << solution.search(nums, target4) << endl;
//	cout << solution.search(nums, target5) << endl;
//
//	cout << solution.search(nums1, target2) << endl;
//	cout << solution.search(nums2, target3) << endl;
//	cout << solution.search(nums2, 0) << endl;
//}
