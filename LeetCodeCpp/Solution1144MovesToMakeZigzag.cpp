#include "stdafx.h"

using namespace std;
class Solution1144MovesToMakeZigzag
{
public:
	int MovesToMakeZigzagImpl(vector<int>& nums, int startIndex) {
		int numsSize = nums.size();
		int result = 0;
		int rightLimit = numsSize - 1;

		while (startIndex < numsSize) {
			int currentMinus = 0;
			if (startIndex > 0) {
				currentMinus = max(currentMinus, nums[startIndex] - nums[startIndex - 1] + 1);
			}
			if (startIndex < rightLimit) {
				currentMinus = max(currentMinus, nums[startIndex] - nums[startIndex + 1] + 1);
			}

			result += currentMinus;
			startIndex += 2;
		}

		return result;
	}

	int movesToMakeZigzag(vector<int>& nums) {
		return min(MovesToMakeZigzagImpl(nums, 0), MovesToMakeZigzagImpl(nums, 1));
	}
};


//int main() {
//	Solution1144MovesToMakeZigzag solution;
//
//	vector<int> nums1{ 1,2,3 };
//	vector<int> nums2{ 9,6,1,6,2 };
//	solution.movesToMakeZigzag(nums1);
//	solution.movesToMakeZigzag(nums2);
//}
