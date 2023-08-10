#include "stdafx.h"

using namespace std;

class Solution137SingleNumber
{
public:
	int singleNumber(vector<int>& nums) {
		int numsSize = nums.size();
		int result = 0;
		for (int i = 0; i < 32; i++)
		{
			int currentNum = 0;
			for (int j = 0; j < numsSize; j++)
			{
				// ȡ�� i λ
				currentNum += ((nums[j] >> i) & 1);
			}
			if (currentNum % 3 == 1) {
				result |= (1 << i);
			}
		}
		return result;
	}
};

//int main() {
//	vector<int> nums{ 2,2,3,2 };
//	Solution137SingleNumber solution;
//	solution.singleNumber(nums);
//}
