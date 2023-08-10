#include "stdafx.h"

using namespace std;

class Solution283MoveZeroes
{
public:
	void moveZeroes(vector<int>& nums) {
		int left = 0;
		int right = 0;
		int numsSize = nums.size();
		while (right < numsSize)
		{
			if (nums[right] != 0) {
				swap(nums[left], nums[right]);
				++left;
			}
			++right;
		}
	}
};
