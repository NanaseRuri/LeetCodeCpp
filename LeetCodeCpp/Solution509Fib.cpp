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

class Solution509Fib
{
public:
	int fib(int n) {
		int f[2] = { 0,1 };

		for (int i = 2; i < n; i++)
		{
			f[i % 2] = f[0] + f[1];
		}

		return f[n % 2];
	}

	int fib1(int n) {
		if (n < 2) {
			return n;
		}

		vector<vector<int>> matrix{ {1,1},{1,0} };
		vector<vector<int>> res = PowMatrix(matrix, n - 1);

		return res[0][0];
	}

	vector<vector<int>> PowMatrix(vector<vector<int>>& matrix, int n) {
		vector<vector<int>> ret{ {1,0},{0,1} };

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

	vector<vector<int>> MultipleMatrix(vector<vector<int>>& a, vector<vector<int>>& b) {
		vector<vector<int>> ret(2, vector<int>(2));
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 2; j++) {
				ret[i][j] = a[i][0] * b[0][j] + a[i][1] * b[1][j];
			}
		}

		return ret;
	}
};

//int main() {
//	Solution509Fib solution;
//	solution.fib1(4);
//}