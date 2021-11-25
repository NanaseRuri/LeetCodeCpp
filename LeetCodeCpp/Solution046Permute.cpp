#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <limits>
#include <stack>
#include <queue>

using namespace std;

class Solution046Permute {
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
				if (!indexUsed[i]) {
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
	vector<vector<int>> permute(vector<int>& nums) {
		_result.clear();
		int numsSize = nums.size();
		bool* indexUsed = new bool[numsSize] {};

		vector<int> currentResult;
		for (int i = 0; i < numsSize; i++)
		{
			indexUsed[i] = true;
			currentResult.push_back(nums[i]);
			Iteration(nums, currentResult, i, indexUsed);
		}

		return _result;
	}
};

//int main() {
//	vector<int> nums{ 1,2,3 };
//	vector<int> nums1{ 0,1 };
//	vector<int> nums2{ 1,2,3,4 };
//	vector<int> nums3{ 1 };
//	Solution046Permute solution;
//	auto result = solution.permute(nums);
//	auto result1 = solution.permute(nums1);
//	auto result2 = solution.permute(nums2);
//	auto result3 = solution.permute(nums3);
//}