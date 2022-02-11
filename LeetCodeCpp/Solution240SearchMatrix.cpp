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

class Solution240SearchMatrix
{
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int totalRow = matrix.size();
		int totalCol = matrix.size();

		int currentRow = 0;
		int currentCol = totalCol - 1;
		while (currentRow < totalRow && currentCol >= totalCol)
		{
			if (matrix[currentRow][currentCol] == target) {
				return true;
			}
			if (matrix[currentRow][currentCol] > target) {
				--currentCol;
			}
			else {
				++currentRow;
			}
		}

		return false;
	}
};