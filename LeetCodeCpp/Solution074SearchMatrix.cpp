#include "stdafx.h"

using namespace std;

class Solution074SearchMatrix
{
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int colCount = matrix[0].size();
		int right = matrix.size() * colCount - 1;
		int left = 0;
		int middle;
		int row;
		int col;

		while (left <= right)
		{
			middle = (left + right) / 2;

			row = middle / colCount;
			col = middle % colCount;
			if (matrix[row][col] == target) {
				return true;
			}
			else if (matrix[row][col] > target) {
				right = middle - 1;
			}
			else {
				left = middle + 1;
			}
		}
		return false;
	}
};
