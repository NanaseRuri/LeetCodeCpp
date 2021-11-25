#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <limits>
#include <stack>
#include <queue>

using namespace std;

class Solution045Jump {
public:
	int jump(vector<int>& nums) {
		int lastIndex = nums.size() - 1;
		int stepCount = 0;
		stack<int> minIndexStack;

		while (lastIndex > 0)
		{
			int minIndexStackSize = minIndexStack.size();
			for (int i = lastIndex - 1; i >= 0; i--)
			{
				if (nums[i] + i >= lastIndex) {
					minIndexStack.push(i);
				}
			}
			// 找不到可以跳到这个格子的格子
			if (minIndexStackSize == minIndexStack.size())
			{
				lastIndex = minIndexStack.top();
				minIndexStack.pop();
				stepCount--;
			}
			else
			{
				lastIndex = minIndexStack.top();
				minIndexStack.pop();
				stepCount++;
			}
		}

		return stepCount;
	}

	int jump1(vector<int>& nums)
	{
		int numsSize = nums.size();
		int stepCount = 0;

		int left = 0;
		while (left < numsSize - 1)
		{
			stepCount++;
			if (left + nums[left] >= numsSize - 1)
			{
				break;
			}

			int maxRightCanGet = 0;
			int maxRightIndex = 0;
			for (int i = 1; i <= nums[left]; i++)
			{
				if (maxRightCanGet < i + nums[left + i])
				{
					maxRightIndex = left + i;
					maxRightCanGet = i + nums[maxRightIndex];
				}
			}
			left = maxRightIndex;
		}

		return stepCount;
	}

	int jump2(vector<int>& nums)
	{
		int numsSize = nums.size();
		int stepCount = 0;
		int end = 0;
		int maxPosition = 0;
		for (int i = 0; i < numsSize - 1; i++)
		{
			maxPosition = max(maxPosition, nums[i] + i);
			if (i == end) {
				end = maxPosition;
				stepCount++;
			}
		}

		return stepCount;
	}
};

//int main() {
//	vector<int> nums{ 2,3,1,1,4 };
//	vector<int> nums1{ 1,2,2,2,1,4 };
//	vector<int> nums2{ 2,1 };
//	vector<int> nums3{ 3,2,1 };
//	Solution045Jump solution;
//	cout << solution.jump(nums) << endl;
//	cout << solution.jump(nums1) << endl;
//	cout << endl;
//	cout << solution.jump1(nums) << endl;
//	cout << solution.jump1(nums1) << endl;
//	cout << solution.jump1(nums2) << endl;
//	cout << solution.jump1(nums3) << endl;
//	cout << endl;
//	cout << solution.jump2(nums) << endl;
//	cout << solution.jump2(nums1) << endl;
//	cout << solution.jump2(nums2) << endl;
//	cout << solution.jump2(nums3) << endl;
//}