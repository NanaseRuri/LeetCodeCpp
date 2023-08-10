#include "stdafx.h"

using namespace std;

class Solution228SummaryRanges
{
public:
	vector<string> summaryRanges(vector<int>& nums) {
		vector<string> result;
		int numsSize = nums.size();

		int left = 0;
		int right;
		while (left < numsSize)
		{
			result.emplace_back(to_string(nums[left]));
			right = left;
			while (right + 1 < numsSize && nums[right + 1] == nums[right] + 1)
			{
				++right;
			}
			if (left != right) {
				result.back() += "->" + to_string(nums[right]);
			}

			left = right + 1;
		}
		return result;
	}
};
