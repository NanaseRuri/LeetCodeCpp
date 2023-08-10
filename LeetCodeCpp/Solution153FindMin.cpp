#include "stdafx.h"

using namespace std;

class Solution153FindMin
{
public:
	int findMin(vector<int>& nums) {
		int left = 0;
		int right = nums.size() - 1;
		int middle;
		while (left < right)
		{
			middle = (left + right) / 2;
			if (nums[middle] < right) {
				right = middle - 1;
			}
			else {
				left = middle;
			}
		}
		return 0;
	}
};
