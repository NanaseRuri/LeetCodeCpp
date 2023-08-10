#include "stdafx.h"

using namespace std;

class Solution2104SubArrayRanges
{
public:
	long long subArrayRanges(vector<int>& nums) {
		long long result = 0;

		int numsSize = nums.size();
		for (int i = 0; i < numsSize; i++)
		{
			int maxValue = nums[i];
			int minValue = nums[i];
			for (int j = i + 1; j < numsSize; j++)
			{
				maxValue = max(maxValue, nums[j]);
				minValue = min(minValue, nums[j]);
				result += maxValue - minValue;
			}
		}

		return result;
	}


	long long subArrayRanges1(vector<int>& nums) {
		int numsSize = nums.size();
		vector<int> leftMax(numsSize);
		vector<int> leftMin(numsSize);
		vector<int> rightMax(numsSize);
		vector<int> rightMin(numsSize);

		stack<int> maxStack;
		stack<int> minStack;

		for (int i = 0; i < numsSize; i++)
		{
			// �涨��ߵ����ұ�ʱ����Ϊ��ߵ������ұߵ�С
			while (!minStack.empty() && nums[minStack.top()] > nums[i])
			{
				minStack.pop();
			}

			leftMin[i] = minStack.empty() ? -1 : minStack.top();
			minStack.push(i);

			while (!maxStack.empty() && nums[maxStack.top()] <= nums[i])
			{
				maxStack.pop();
			}
			leftMax[i] = maxStack.empty() ? -1 : maxStack.top();
			maxStack.push(i);
		}

		maxStack = stack<int>();
		minStack = stack<int>();

		for (int i = numsSize - 1; i >= 0; i--)
		{
			while (!minStack.empty() && nums[minStack.top()] >= nums[i])
			{
				minStack.pop();
			}
			rightMin[i] = minStack.empty() ? numsSize : minStack.top();
			minStack.push(i);

			while (!maxStack.empty() && nums[maxStack.top()] < nums[i])
			{
				maxStack.pop();
			}
			rightMax[i] = maxStack.empty() ? numsSize : maxStack.top();
			maxStack.push(i);
		}

		long long maxSum = 0;
		long long minSum = 0;

		for (int i = 0; i < numsSize; i++)
		{
			maxSum += static_cast<long long>(rightMax[i] - i) * (i - leftMax[i]) * nums[i];
			minSum += static_cast<long long>(rightMin[i] - i) * (i - leftMin[i]) * nums[i];
		}

		return maxSum - minSum;
	}
};

//int main() {
//	vector<int> nums1{ 1,2,3 };
//	vector<int> nums2{ 4,-2,-3,4,1 };
//
//	Solution2104SubArrayRanges solution;
//	solution.subArrayRanges1(nums1);
//	solution.subArrayRanges1(nums2);
//}
