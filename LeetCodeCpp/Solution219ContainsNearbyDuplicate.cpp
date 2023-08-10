#include "stdafx.h"

using namespace std;

class Solution219ContainsNearbyDuplicate
{
public:
	bool containsNearbyDuplicate(vector<int>& nums, int k) {
		unordered_set<int> numsSet;
		int numsSize = nums.size();

		for (int i = 0; i < numsSize; i++)
		{
			if (i > k) {
				numsSet.erase(nums[i - k - 1]);
			}
			if (numsSet.find(nums[i]) != numsSet.end()) {
				return true;
			}
			numsSet.emplace(nums[i]);
		}

		return false;
	}
};
