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

class Solution566MatrixReshape
{
public:
	vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
		int row = mat.size();
		int col = mat[0].size();

		if (row * col != r * c) {
			return mat;
		}
		else {
			vector<vector<int>> result;

			int currentRow = 0;
			int currentCol = 0;
			for (int i = 0; i < r; ++i)
			{
				result.push_back(vector<int>());
				for (int j = 0; j < c; ++j)
				{
					if (currentCol == col) {
						currentCol = 0;
						++currentRow;
					}
					result[i].push_back(mat[currentRow][currentCol]);
					++currentCol;
				}
			}
			return result;
		}		
	}
};
