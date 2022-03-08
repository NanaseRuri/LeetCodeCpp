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
using ll = long long;
class Solution1137Tribonacci
{
public:
	int tribonacci(int n) {
		int t[3] = { 0,1,1 };

		for (int i = 3; i <= n; i++)
		{
			t[i % 3] = t[0] + t[1] + t[2];
		}

		return t[n % 3];
	}

	int tribonacci1(int n) {
		if (n == 0) {
			return 0;
		}
		else if (n == 1 || n == 2) {
			return 1;
		}

		vector<vector<ll>> mat = { {1,1,1}, {1,0,0}, {0,1,0} };
		vector<vector<ll>> result = PowMatrix(mat, n - 1);

		return result[0][0];
	}

	vector<vector<ll>> PowMatrix(vector<vector<ll>>& matrix, int n) {
		vector<vector<ll>> ret{ {1,0,0},{0,1,0},{0,0,1} };

		while (n > 0)
		{
			if (n & 1) {
				ret = MultipleMatrix(ret, matrix);
			}
			n >>= 1;
			matrix = MultipleMatrix(matrix, matrix);
		}

		return ret;
	}

	vector<vector<ll>> MultipleMatrix(vector<vector<ll>>& a, vector<vector<ll>>& b) {
		vector<vector<ll>> ret(3, vector<ll>(3));
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++) {
				ret[i][j] = a[i][0] * b[0][j] + a[i][1] * b[1][j] + a[i][2] * b[2][j];
			}
		}

		return ret;
	}
};
