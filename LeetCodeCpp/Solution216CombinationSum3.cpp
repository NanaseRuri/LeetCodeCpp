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
#include <numeric>

using namespace std;

class Solution216CombinationSum3
{
private:
	vector<int> _currentResult;
	vector<vector<int>> _result;

	void Dfs(int left, int right, int k, int target) {
		int currentResultSize = _currentResult.size();
		if (currentResultSize + (right - left + 1) < k || currentResultSize > k) {
			return;
		}
		if (currentResultSize == k && accumulate(_currentResult.begin(), _currentResult.end(), 0) == target) {
			_result.push_back(_currentResult);
			return;
		}

		_currentResult.push_back(left);
		Dfs(left + 1, right, k, target);
		_currentResult.pop_back();
		Dfs(left + 1, right, k, target);
	}

public:
	vector<vector<int>> combinationSum31(int k, int n) {
		_result.clear();
		_currentResult.clear();

		Dfs(1, 9, k, n);
		return _result;
	}
	vector<vector<int>> combinationSum3(int k, int n) {
		vector<vector<int>> result;
		if (k <= 0 || k >= 9) {
			return result;
		}

		if (n< (k * (k + 1)) / 2 || n>(19 - k) * k / 2) {
			return result;
		}


	}
};