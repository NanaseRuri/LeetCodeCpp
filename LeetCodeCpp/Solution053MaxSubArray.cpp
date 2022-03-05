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

	struct Status {
		int lSum, rSum, mSum, iSum;

		Status(int lSum, int rSum, int mSum, int iSum) :lSum(lSum), rSum(rSum), mSum(mSum), iSum(iSum) {

		}
	};

	Status PushUp(Status l, Status r) {
		int iSum = l.iSum + r.iSum;
		int lSum = max(l.lSum, l.iSum + r.lSum);
		int rSum = max(r.rSum, r.iSum + l.rSum);
		int mSum = max(max(l.mSum, r.mSum), l.rSum + r.lSum);
		return Status(lSum, rSum, mSum, iSum);
	}

	Status Get(vector<int>& nums, int l, int r) {
		if (l == r) {
			return Status(nums[l], nums[l], nums[l], nums[l]);
		}

		int middle = (l + r) / 2;
		Status lSub = Get(nums, l, middle);
		Status rSub = Get(nums, middle + 1, r);
		return PushUp(lSub, rSub);
	}

	int maxSubArray1(vector<int>& nums) {
		return Get(nums, 0, nums.size() - 1).mSum;
	}
};

//int main() {
//	vector<int> nums{ -2,1,-3,4,-1,2,1,-5,4 };
//	Solution053MaxSubArray solution;
//	solution.maxSubArray1(nums);
//}