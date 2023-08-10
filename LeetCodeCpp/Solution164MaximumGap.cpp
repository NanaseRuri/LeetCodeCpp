#include "stdafx.h"

using namespace std;
class Solution164MaximumGap {
public:
	int maximumGap1(vector<int>& nums) {
		int numsSize = nums.size();
		if (numsSize < 2) {
			return 0;
		}

		int exp = 1;
		vector<int> buffer(numsSize);
		int maxVal = *max_element(nums.begin(), nums.end());

		while (maxVal >= exp)
		{
			vector<int> count(10);
			for (int i = 0; i < numsSize; i++)
			{
				int digit = (nums[i] / exp) % 10;
				count[digit]++;
			}
			for (int i = 1; i < 10; i++)
			{
				count[i] += count[i - 1];
			}
			for (int i = numsSize - 1; i >= 0; i--)
			{
				int digit = (nums[i] / exp) % 10;
				buffer[count[digit] - 1] = nums[i];
				count[digit]--;
			}
			copy(buffer.begin(), buffer.end(), nums.begin());
			exp *= 10;
		}

		int result = 0;
		for (int i = 1; i < numsSize; i++)
		{
			result = max(result, nums[i] - nums[i - 1]);
		}
		return result;
	}

	int maximumGap(vector<int>& nums) {
		int numsSize = nums.size();
		if (numsSize < 2) {
			return 0;
		}

		int minValue = *min_element(nums.begin(), nums.end());
		int maxValue = *max_element(nums.begin(), nums.end());
		int delta = max(1, (maxValue - minValue) / (numsSize - 1));
		int bucketSize = (maxValue - minValue) / delta + 1;

		vector<pair<int, int>> bucket(bucketSize, { -1,-1 });
		for (int i = 0; i < numsSize; i++)
		{
			int index = (nums[i] - minValue) / delta;
			if (bucket[index].first == -1) {
				bucket[index].first = bucket[index].second = nums[i];
			}
			else {
				bucket[index].first = min(bucket[index].first, nums[i]);
				bucket[index].second = max(bucket[index].second, nums[i]);
			}
		}

		int result = 0;
		int preIndex = -1;
		for (int i = 0; i < bucketSize; i++)
		{
			if (bucket[i].first == -1) {
				continue;
			}

			if (preIndex != -1) {
				result = max(result, bucket[i].first - bucket[preIndex].second);
			}
			preIndex = i;
		}
		return result;
	}
};

//int main() {
//	vector<int> nums1{ 2,5 };
//	Solution164MaximumGap solution;
//	solution.maximumGap(nums1);
//}
