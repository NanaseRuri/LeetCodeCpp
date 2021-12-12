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

class Solution047PermuteUnique {
private:
	vector<vector<int>> _result;

	void Iteration(vector<int>& nums, vector<int>& currentResult, int lastUsedIndex, bool* indexUsed) {
		int numsSize = nums.size();
		int currentResultSize = currentResult.size();
		if (currentResultSize == numsSize) {
			indexUsed[lastUsedIndex] = false;
			_result.push_back(vector<int>(currentResult));
			currentResult.pop_back();
			return;
		}
		else {
			for (int i = 0; i < numsSize; i++)
			{
				if (indexUsed[i] || (i > 0 && nums[i] == nums[i - 1] && !indexUsed[i - 1])) {
					continue;
				}
				else {
					indexUsed[i] = true;
					currentResult.push_back(nums[i]);
					Iteration(nums, currentResult, i, indexUsed);
				}
			}
			currentResult.pop_back();
			indexUsed[lastUsedIndex] = false;
		}
	}

public:
	vector<vector<int>> permuteUnique(vector<int>& nums)
	{
		_result.clear();
		sort(nums.begin(), nums.end());
		int numsSize = nums.size();

		vector<int> currentResult;
		bool* indexUsed = new bool[numsSize] {};

		for (int i = 0; i < numsSize; i++)
		{
			if (i > 0 && nums[i] == nums[i - 1]) {
				continue;
			}

			indexUsed[i] = true;
			currentResult.push_back(nums[i]);
			Iteration(nums, currentResult, i, indexUsed);
			indexUsed[i] = false;
		}
		return _result;
	}

	void QuickSort(vector<int>& nums, int left, int right) {
		int left1 = left;
		int right1 = right;

		int key = nums[left];
		while (left < right) {
			while (left < right && nums[right] >= key)
			{
				right--;
			}
			nums[left] = nums[right];
			while (left < right && nums[left] <= key) {
				left++;
			}
			nums[right] = nums[left];
		}
		nums[left] = key;

		QuickSort(nums, left1, left1 - 1);
		QuickSort(nums, left1 + 1, right);
	}
};

//int main() {
//	vector<int> nums{ 1,1,2 };
//	vector<int> nums1{ 1,2,3 };
//	Solution047PermuteUnique solution;
//	auto result = solution.permuteUnique(nums);
//	auto result1 = solution.permuteUnique(nums1);
//}