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

class Solution1572DiagonalSum
{
public:
	int diagonalSum(vector<vector<int>>& mat) {
		int edge = mat.size();
		int result = 0;

		for (int i = 0; i < edge; i++) {
			result += mat[i][i] + mat[edge - i - 1][i];
		}

		if (edge % 2 != 0) {
			result -= mat[edge / 2][edge / 2];
		}
		return result;
	}
};
