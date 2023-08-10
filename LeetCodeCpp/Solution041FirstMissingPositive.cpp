#include "stdafx.h"

using namespace std;

class Solution041FirstMissingPositive {
public:
	int firstMissingPositive(vector<int>& nums) {
		int numsLength = nums.size();

		for (int i = 0; i < numsLength; i++)
		{
			while (nums[i] > 0 && nums[i] <= numsLength && nums[i] != nums[nums[i] - 1]) {
				swap(nums[nums[i] - 1], nums[i]);
			}
		}

		for (int i = 0; i < numsLength; i++)
		{
			if (nums[i] != i + 1) {
				return i + 1;
			}
		}
		return numsLength + 1;
	}
};

//int main() {
//
//	vector<int>nums{ 3,4,-1,1 };
//
//	Solution041FirstMissingPositive solution;
//	cout << solution.firstMissingPositive(nums) << endl;
//}
