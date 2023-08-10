#include "stdafx.h"

using namespace std;

class Solution054SpiralOrder {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		int i = 0;
		int rowCount = matrix.size();
		int colCount = matrix[0].size();
		int endRow = rowCount / 2;
		int endCol = colCount / 2;
		bool needEndColWhenDown = colCount % 2 == 1;
		bool needEndColWhenUp = colCount % 2 == 0;
		int index = 0;
		int rowIndex;
		int colIndex;
		vector<int> result;

		while (true)
		{
			rowIndex = index;
			int currentColCount = colCount - index;
			for (int i = index; i < currentColCount; i++)
			{
				result.push_back(matrix[rowIndex][i]);
			}
			if (rowIndex == endRow) {
				break;
			}

			colIndex = currentColCount - 1;
			int currentRowCount = rowCount - index;
			for (int i = index + 1; i < currentRowCount; i++)
			{
				result.push_back(matrix[i][colIndex]);
			}

			if (needEndColWhenDown && colIndex == colCount / 2) {
				break;
			}

			rowIndex = currentRowCount - 1;
			for (int i = colIndex - 1; i >= index; i--)
			{
				result.push_back(matrix[rowIndex][i]);
			}

			if (rowIndex == endRow) {
				break;
			}

			colIndex = index;
			for (int i = rowIndex - 1; i > index; i--)
			{
				result.push_back(matrix[i][colIndex]);
			}

			if (needEndColWhenUp && colIndex == colCount / 2 - 1) {
				break;
			}

			index++;
		}

		return result;
	}
};

//int main() {
//	vector<vector<int>> nums{ {1,2,3},{4,5,6},{7,8,9} };
//	vector<vector<int>> nums1{ {1,2,3,4},{5,6,7,8} };
//	vector<vector<int>> nums2{ {1,2,3,4},{5,6,7,8},{9,10,11,12} };
//	vector<vector<int>> nums3{ {1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16} };
//	vector<vector<int>> nums4{ {7},{9},{6} };
//	vector<vector<int>> nums5{ {2,3,4},{5,6,7},{8,9,10},{11,12,13},{14,15,16} };
//	vector<vector<int>> nums6{
//		{1,11},
//		{2,12},
//		{3,13},
//		{4,14},
//		{5,15},
//		{6,16},
//		{7,17},
//		{8,18},
//		{9,19},
//		{10,20} };
//
//	Solution054SpiralOrder solution;
//	solution.spiralOrder(nums);
//	solution.spiralOrder(nums1);
//	solution.spiralOrder(nums2);
//	solution.spiralOrder(nums3);
//	solution.spiralOrder(nums4);
//	solution.spiralOrder(nums5);
//	solution.spiralOrder(nums6);
//}
