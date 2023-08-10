#include "stdafx.h"

using namespace std;

class Solution229MajorityElement
{
public:
	vector<int> majorityElement(vector<int>& nums) {
		vector<int> result;
		int num1 = 0;
		int num2 = 0;
		int vote1 = 0;
		int vote2 = 0;

		int numsSize = nums.size();
		for (int i = 0; i < numsSize; i++)
		{
			if (nums[i] == num1) {
				++vote1;
			}
			else if (nums[i] == num2) {
				++vote2;
			}
			else if (vote1 == 0) {
				num1 = nums[i];
				vote1 = 1;
			}
			else if (vote2 == 0) {
				num2 = nums[i];
				vote2 = 1;
			}
			else {
				--vote1;
				--vote2;
			}
		}

		int count1 = 0;
		int count2 = 0;

		for (int i = 0; i < numsSize; i++)
		{
			if (num1 == nums[i]) {
				++count1;
			}
			else if (num2 == nums[i]) {
				++count2;
			}
		}

		if (vote1 > 0 && count1 > numsSize / 3) {
			result.emplace_back(num1);
		}
		if (vote2 > 0 && count2 > numsSize / 3) {
			result.emplace_back(num2);
		}
		return result;
	}
};
