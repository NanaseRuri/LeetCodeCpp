#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <limits>
#include <stack>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution053MaxSubArray {
public:
	int maxSubArray(vector<int>& nums) {
		int sum = 0;
		int maxValue = INT32_MIN;
		int numsSize = nums.size();
		for (int i = 0; i < numsSize; i++)
		{
			sum += nums[i];
			maxValue = max(maxValue, sum);
			if (sum < 0) {
				sum = 0;
			}
		}
		return maxValue;
	}
};

//int main() {
//	vector<int> nums{ -2,1,-3,4,-1,2,1,-5,4 };
//	Solution053MaxSubArray solution;
//	solution.maxSubArray(nums);
//}