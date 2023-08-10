#include "stdafx.h"

using namespace std;

class Solution128LongestConsecutive
{
public:
	int longestConsecutive(vector<int>& nums) {
		unordered_set<int> numsSet{ nums.begin(),nums.end() };

		int numsSize = nums.size();
		int maxLength = 0;
		for (const int& num : numsSet) {
			if (numsSet.find(num - 1) == numsSet.end()) {
				int currentNum = num;
				int currentLength = 1;

				while (numsSet.find(currentNum + 1) != numsSet.end()) {
					currentNum += 1;
					currentLength += 1;
				}

				maxLength = max(maxLength, currentLength);
			}
		}

		return maxLength;
	}
};
