#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <limits>
#include <stack>
#include <queue>
#include <unordered_set>
#include "ListNode.h"
#include "TreeNode.h"
#include "Node.h"
#include <set>

using namespace std;

class Solution239MaxSlidingWindow
{
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		if (k == 1) {
			return vector<int>(nums);
		}

		priority_queue<pair<int, int>>priorityQueue;
		for (int i = 0; i < k; i++)
		{
			priorityQueue.emplace(nums[i], i);
		}

		vector<int> result;
		result.push_back(priorityQueue.top().first);

		int numsSize = nums.size();
		for (int i = k; i < numsSize; i++)
		{
			int lastIndex = i - k;
			priorityQueue.emplace(nums[i], i);
			while (priorityQueue.top().second <= lastIndex)
			{
				priorityQueue.pop();
			}

			result.push_back(priorityQueue.top().first);
		}

		return result;
	}

	vector<int> maxSlidingWindow1(vector<int>& nums, int k) {
		if (k == 1) {
			return vector<int>(nums);
		}

		deque<int> q;
		for (int i = 0; i < k; i++)
		{
			while (!q.empty() && nums[i] >= nums[q.back()])
			{
				q.pop_back();
			}
			q.push_back(i);
		}

		vector<int> result{ nums[q.front()] };
		int n = nums.size();
		for (int i = k; i < n; i++)
		{
			while (!q.empty() && nums[i] >= nums[q.back()])
			{
				q.pop_back();
			}
			q.push_back(i);
			while (q.front() <= i - k) {
				q.pop_front();
			}
			result.push_back(nums[q.front()]);
		}
		return result;
	}

	vector<int> maxSlidingWindow2(vector<int>& nums, int k) {
		if (k == 1) {
			return vector<int>(nums);
		}

		int n = nums.size();
		vector<int> prefixMax(n);
		vector<int> suffixMax(n);
		for (int i = 0; i < n; i++)
		{
			if (i % k == 0) {
				prefixMax[i] = nums[i];
			}
			else {
				prefixMax[i] = max(prefixMax[i - 1], nums[i]);
			}
		}

		suffixMax[n - 1] = nums[n - 1];
		for (int i = n - 2; i >= 0; i--)
		{
			if ((i + 1) % k == 0) {
				suffixMax[i] = nums[i];
			}
			else {
				suffixMax[i] = max(suffixMax[i + 1], nums[i]);
			}
		}

		vector<int> result;
		for (int i = 0; i <= n - k; i++)
		{
			result.push_back(max(suffixMax[i], prefixMax[i + k - 1]));
		}

		return result;
	}
};

//int main() {
//	Solution239MaxSlidingWindow solution;
//	vector<int> nums1{ 1,3,-1,-3,5,3,6,7 };
//	vector<int> result1 = solution.maxSlidingWindow(nums1, 3);
//}