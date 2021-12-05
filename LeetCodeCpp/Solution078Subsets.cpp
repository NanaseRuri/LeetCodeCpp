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

class Solution078Subsets
{
private:
	vector<vector<int>> _result;
	vector<int> _curResult;

	void Iteration(vector<int>& nums, int startIndex, int numsSize) {
		_result.push_back(vector<int>(_curResult));
		if (startIndex == numsSize) {
			return;
		}

		for (int i = startIndex; i < numsSize; i++)
		{
			_curResult.push_back(nums[i]);
			Iteration(nums, i + 1, numsSize);
			_curResult.pop_back();
		}
	}
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		_result.clear();
		_curResult.clear();

		Iteration(nums, 0, nums.size());
		return _result;
	}
};
