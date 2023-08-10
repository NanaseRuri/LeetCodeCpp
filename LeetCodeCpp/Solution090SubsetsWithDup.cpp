#include "stdafx.h"

using namespace std;

class Solution090SubsetsWithDup
{
private:
	vector<int> _currentResult;
	vector<vector<int>> _totalResult;

	void Iteration(vector<int>& nums, int startIndex, int numsSize) {
		_totalResult.push_back(_currentResult);

		for (int i = startIndex; i < numsSize; i++)
		{
			if (i > startIndex && nums[i] == nums[i - 1]) {
				continue;
			}

			_currentResult.push_back(nums[i]);
			Iteration(nums, i + 1, numsSize);
			_currentResult.pop_back();
		}
	}

public:
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		_currentResult.clear();
		_totalResult.clear();

		sort(nums.begin(), nums.end());
		Iteration(nums, 0, nums.size());

		return _totalResult;
	}

	void QuickSort(vector<int>& nums, int left, int right) {
		if (left >= right) {
			return;
		}

		int key = nums[left];
		int l = left;
		int r = right;
		while (l < r) {
			while (l < r && nums[r] >= key)
			{
				r--;
			}
			nums[l] = nums[r];
			while (l < r && nums[l] <= key)
			{
				l++;
			}
			nums[r] = nums[l];
		}
		nums[l] = key;
		QuickSort(nums, left, l - 1);
		QuickSort(nums, l + 1, right);
	}
};

//int main() {
//	Solution090SubsetsWithDup solution;
//
//	vector<int> nums{ 2,5,1,3,9,2,4,8,6,4 };
//	solution.QuickSort(nums, 0, nums.size() - 1);
//
//	nums = { 2,1,2 };
//	solution.QuickSort(nums, 0, nums.size() - 1);
//	solution.subsetsWithDup(nums);
//	nums = { 0 };
//	solution.subsetsWithDup(nums);
//}
