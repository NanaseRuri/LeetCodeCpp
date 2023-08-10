#include "stdafx.h"

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
