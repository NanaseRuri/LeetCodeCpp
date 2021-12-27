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

using namespace std;

class Solution118Generate
{
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> result;

		if (numRows == 0) {
			return result;
		}

		result.push_back({ 1 });
		for (int i = 1; i < numRows; i++)
		{
			result.push_back(vector<int>(i + 1));

			result[i][0] = 1;
			result[i][i] = 1;
			for (int j = 1; j < i; j++)
			{
				result[i][j] = result[i - 1][j - 1] + result[i - 1][j];
			}
		}

		return result;
	}
};
