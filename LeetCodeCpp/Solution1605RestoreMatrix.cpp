#include "stdafx.h"

using namespace std;

class Solution1605RestoreMatrix {
public:
	vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
		int n = rowSum.size();
		int m = colSum.size();
		vector<vector<int>> result(n, vector<int>(m));

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				int currentValue = min(rowSum[i], colSum[j]);
				result[i][j] = currentValue;
				rowSum[i] -= currentValue;
				colSum[j] -= currentValue;
			}
		}

		return result;
	}
};
