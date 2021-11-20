#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <limits>
#include <stack>

using namespace std;

class Solution034SearchRange {
private:
	int BinarySearch(vector<int>& nums, int target) {
		int middle;
		int left = 0;
		int right = nums.size() - 1;

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
	vector<int> searchRange(vector<int>& nums, int target) {
		int middle = BinarySearch(nums, target);
		if (middle == -1) {
			return { -1,-1 };
		}

		int leftOfLeftPart = 0;
		int rightOfLeftPart = middle;

		int leftOfRightPart = middle;
		int rightOfRightPart = nums.size() - 1;


		while (leftOfLeftPart <= rightOfLeftPart)
		{
			middle = (leftOfLeftPart + rightOfLeftPart) / 2;
			if (nums[middle] == target) {
				rightOfLeftPart = middle - 1;
			}
			else {
				leftOfLeftPart = middle + 1;
			}
		}

		while (rightOfRightPart >= leftOfRightPart)
		{
			middle = (leftOfRightPart + rightOfRightPart) / 2;
			if (nums[middle] == target) {
				leftOfRightPart = middle + 1;
			}
			else {
				rightOfRightPart = middle - 1;
			}
		}

		return { leftOfLeftPart,rightOfRightPart };
	}
};

//int main() {
//	Solution034SearchRange solution;
//	vector<int> nums1 = { 5,7,7,8,8,10 };
//	vector<int> nums2 = { 5,7,7,8,8,10 };
//	vector<int> nums3 = {};
//	vector<int> nums4 = { 5,7,7,8,8,10,11 };
//
//	int target1 = 8;
//	int target2 = 6;
//	int target3 = 0;
//	int target4 = 11;
//
//	vector<int> result1 = solution.searchRange(nums1, target1);
//	vector<int> result2 = solution.searchRange(nums2, target2);
//	vector<int> result3 = solution.searchRange(nums3, target3);
//	vector<int> result4 = solution.searchRange(nums4, target4);
//}