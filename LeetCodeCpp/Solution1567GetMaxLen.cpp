#include "stdafx.h"

using namespace std;

class Solution1567GetMaxLen
{
public:
	int getMaxLen(vector<int>& nums) {
		int n = nums.size();
		int positive = nums[0] > 0;
		int negative = nums[0] < 0;
		int maxLength = positive;

		for (int i = 1; i < n; i++)
		{
			if (nums[i] > 0) {
				++positive;
				negative = negative > 0 ? negative + 1 : 0;
			}
			else if (nums[i] < 0) {
				int newPositive = negative > 0 ? negative + 1 : 0;
				int newNegative = positive + 1;
				tie(positive, negative) = { newPositive,newNegative };
			}
			else {
				positive = negative = 0;
			}
			maxLength = max(maxLength, positive);
		}

		return maxLength;
	}
};
