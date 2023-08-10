#include "stdafx.h"

using namespace std;

class Solution040CombinationSum2 {
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
			if (i > startIndex && candidates[i] == candidates[i - 1]) {
				continue;
			}
			int newSum = candidates[i] + currentSum;
			if (newSum <= target) {
				currentResult.push_back(candidates[i]);
				Iteration(candidates, currentResult, i + 1, newSum, target);
			}
			else {
				currentResult.pop_back();
				return;
			}
		}
		currentResult.pop_back();
	}

public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		_result.clear();

		sort(candidates.begin(), candidates.end());
		int candidatesSize = candidates.size();
		for (int i = 0; i < candidatesSize; i++)
		{
			if (i > 0 && candidates[i] == candidates[i - 1]) {
				continue;
			}
			vector<int> currentResult{ candidates[i] };
			Iteration(candidates, currentResult, i + 1, candidates[i], target);
		}

		return _result;
	}
};

//int main() {
//
//		vector<int>candidates{ 10,1,2,7,6,1,5 };
//		int target = 8;
//	
//		Solution040CombinationSum2 solution;
//		auto result = solution.combinationSum2(candidates, target);
//}
