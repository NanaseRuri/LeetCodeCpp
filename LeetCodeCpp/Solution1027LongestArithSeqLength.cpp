#include "stdafx.h"

using namespace std;

class Solution1026MaxAncestorDiff
{
public:
	int longestArithSeqLength(vector<int>& nums) {
		int n = nums.size();
		int result = 2;
		for (int i = 0; i < n - 1; i++) {
			int currentResult = 0;
			int currentDifference = nums[i + 1] - nums[i];
			for (int j = i + 2; j < n; j++) {

			}
		}

		return result;
	}
};
