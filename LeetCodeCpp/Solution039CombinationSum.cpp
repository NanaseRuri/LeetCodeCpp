#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <limits>
#include <stack>

using namespace std;

class Solution039CombinationSum {
private:
	vector<vector<int>> _result;
	void Iteration(vector<int>& candidates, vector<int>& currentResult, int startIndex, int currentSum, int target) {
		if (currentSum == target) {
			vector<int> newResult(currentResult);
			_result.push_back(newResult);
			currentResult.pop_back();
			return;
		}

		int candidatesSize = candidates.size();
		for (int i = startIndex; i < candidatesSize; i++)
		{
			int newSum = candidates[i] + currentSum;
			if (newSum <= target) {
				currentResult.push_back(candidates[i]);
				Iteration(candidates, currentResult, i, newSum, target);
			}
			else {
				currentResult.pop_back();
				return;
			}
		}
		currentResult.pop_back();
	}

public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		_result.clear();

		sort(candidates.begin(), candidates.end());
		int candidatesSize = candidates.size();
		for (int i = 0; i < candidatesSize; i++)
		{
			vector<int> currentResult{ candidates[i] };
			Iteration(candidates, currentResult, i, candidates[i], target);
		}

		return _result;
	}
};

//int main() {
//	vector<int>candidates{ 2, 7, 6, 3, 5, 1 };
//	int target = 9;
//
//	Solution039CombinationSum solution;
//	auto result = solution.combinationSum(candidates, target);
//}