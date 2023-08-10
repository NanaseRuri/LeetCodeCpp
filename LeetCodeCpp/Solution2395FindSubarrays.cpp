#include "stdafx.h"

using namespace std;
class Solution2395FindSubarrays
{
public:
	bool findSubarrays(vector<int>& nums) {
		unordered_set<int> sumMap;
		for (int i = 0; i < nums.size() - 1; i++) {
			int currentSum = nums[i] + nums[i + 1];
			if (sumMap.find(currentSum) != sumMap.end()) {
				return true;
			}
			sumMap.insert(currentSum);
		}
		return false;
	}
};
