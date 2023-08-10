#include "stdafx.h"

using namespace std;

class Solution027RemoveElement {
public:
	int removeElement(vector<int>& nums, int val) {
		int numSize = nums.size();
		if (numSize == 0) {
			return 0;
		}

		int left = 0;
		int right = numSize - 1;
		int dulplicateCount = 0;
		while (left <= right)
		{
			if (nums[left] == val) {
				dulplicateCount++;
				while (left < right && nums[right] == val)
				{
					right--;
					dulplicateCount++;
				}
				nums[left] = nums[right];
				right--;
			}
			left++;
		}

		return numSize - dulplicateCount;
	}
};
