#include "stdafx.h"


using namespace std;
class Solution209MinSubArrayLen {
public:
	int minSubArrayLen(int target, vector<int>& nums) {
		int left = 0;
		int right = 0;
		int currentTotal = nums[0];
		int result = INT32_MAX;
		int numsSize = nums.size();

		while (left < numsSize && right < numsSize)
		{
			if (currentTotal > target) {
				result = min(result, right - left + 1);
				currentTotal -= nums[left];
				left++;
			}
			if (currentTotal == target) {
				result = min(result, right - left + 1);
				right++;
				if (right < numsSize) {
					currentTotal += nums[right];
				}
			}
			else if (currentTotal < target) {
				right++;
				if (right < numsSize) {
					currentTotal += nums[right];
				}
			}
		}

		return result == INT32_MAX ? 0 : result;
	}

	int minSubArrayLen1(int target, vector<int>& nums) {
		int left = 0;
		int right = 0;
		int currentTotal = 0;
		int result = INT32_MAX;
		int numsSize = nums.size();

		while (right < numsSize)
		{
			currentTotal += nums[right];
			while (currentTotal >= target)
			{
				result = min(result, right - left + 1);
				currentTotal -= nums[left];
				left++;
			}
			right++;
		}

		return result == INT32_MAX ? 0 : result;
	}

	int minSubArrayLenNLogN(int target, vector<int>& nums) {
		int n = nums.size();
		if (n == 0) {
			return 0;
		}
		int result = INT32_MAX;
		vector<int> sums(n + 1);

		for (int i = 1; i <= n; i++)
		{
			sums[i] = sums[i - 1] + nums[i - 1];
		}

		for (int i = 1; i <= n; i++)
		{
			int temp = target + sums[i - 1];
			auto bound = lower_bound(sums.begin(), sums.end(), target);
			if (bound != sums.end()) {
				result = min(result, static_cast<int>((bound - sums.begin()) - (i - 1)));
			}
		}

		return result == INT32_MAX ? 0 : result;
	}
};

//int main() {
//	Solution209MinSubArrayLen solution;
//	int target1 = 7;
//	int target2 = 4;
//	int target3 = 11;
//	int target4 = 11;
//	vector<int> nums1{ 2,3,2,1,4,3 };
//	vector<int> nums2{ 1,4,4 };
//	vector<int> nums3{ 1,1,1,1,1,1 };
//	vector<int> nums4{ 1,2,3,4,5 };
//
//	cout << solution.minSubArrayLen1(target1, nums1) << endl;
//	cout << solution.minSubArrayLen1(target2, nums2) << endl;
//	cout << solution.minSubArrayLen1(target3, nums3) << endl;
//	cout << solution.minSubArrayLen1(target4, nums4) << endl;
//}
