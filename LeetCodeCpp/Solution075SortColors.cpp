#include "stdafx.h"

using namespace std;

class Solution075SortColors
{
public:
	void sortColors(vector<int>& nums) {
		int numsSize = nums.size();
		int ptr0 = 0;
		int ptr1 = 0;

		for (int i = 0; i < numsSize; i++)
		{
			if (nums[i] == 0) {
				if (ptr0 < ptr1) {
					nums[i] = nums[ptr1];
					nums[ptr1] = 1;
				}
				else {
					nums[i] = nums[ptr0];
				}

				nums[ptr0] = 0;
				ptr0++;
				ptr1++;
			}
			else if (nums[i] == 1) {
				nums[i] = nums[ptr1];
				nums[ptr1] = 1;
				ptr1++;
			}
		}
	}
};

//int main() {
//	vector<int> nums{ 2,0,2,1,1,0 };
//	vector<int> nums1{ 2,1,0 };
//	vector<int> nums2{ 2,0,0,1 };
//
//	Solution075SortColors solution;
//	solution.sortColors(nums);
//	solution.sortColors(nums1);
//	solution.sortColors(nums2);
//}
