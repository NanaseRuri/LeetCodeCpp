#include "stdafx.h"

class Solution661ImageSmoother {
public:
	vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
		int row = img.size();
		int col = img[0].size();

		vector<vector<int>> preSums(row + 1, vector<int>(col + 1));
		for (int i = 1; i <= row; i++)
		{
			for (int j = 1; j <= col; j++)
			{
				preSums[i][j] = preSums[i - 1][j] + preSums[i][j - 1] - preSums[i - 1][j - 1] + img[i - 1][j - 1];
			}
		}

		vector<vector<int>> result(row, vector<int>(col));
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				int left = max(j - 1, 0);
				int right = min(j + 2, col);
				int top = max(i - 1, 0);
				int bottom = min(i + 2, row);

				result[i][j] = (preSums[bottom][right] + preSums[top][left] - preSums[bottom][left] - preSums[top][right]) / (right - left) / (bottom - top);
			}
		}

		return result;
	}
};


//int main() {
//	vector<vector<int>> nums{
//		{1,2,3,4,5},
//		{6,7,8,9,10},
//		{11,12,13,14,15},
//		{16,17,18,19,20},
//		{21,22,23,24,25}
//	};
//
//	Solution661ImageSmoother solution;
//	solution.imageSmoother(nums);
//}
