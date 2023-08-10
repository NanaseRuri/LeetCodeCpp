#include "stdafx.h"

using namespace std;

class Solution1039MinScoreTriangulation
{
	vector<vector<int>> _dp;
	int Dfs(vector<int>& values, int left, int right) {
		if (_dp[left][right] != -1) {
			return _dp[left][right];
		}

		if (left + 2 > right) {
			_dp[left][right] = 0;
			return 0;
		}
		else if (left + 2 == right) {
			int result = values[left] * values[left + 1] * values[right];
			_dp[left][right] = result;
			return result;
		}
		else {
			int minValue = INT32_MAX;
			for (int i = left + 1; i < right; i++) {
				minValue = min(minValue, values[left] * values[i] * values[right] + Dfs(values, left, i) + Dfs(values, i, right));
			}
			_dp[left][right] = minValue;
			return minValue;
		}
	}

public:
	int minScoreTriangulation(vector<int>& values) {
		int n = values.size();
		_dp.assign(n, vector<int>(n, -1));
		return Dfs(values, 0, n - 1);
	}
};
