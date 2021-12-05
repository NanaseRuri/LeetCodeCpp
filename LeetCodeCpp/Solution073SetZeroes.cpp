#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <limits>
#include <stack>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution073SetZeroes
{
public:
	void setZeroes(vector<vector<int>>& matrix) {
		int rowCount = matrix.size();
		int colCount = matrix[0].size();

		bool* rowNeedSetZero = new bool[rowCount] {};
		bool* colNeedSetZero = new bool[colCount] {};

		for (int i = 0; i < rowCount; i++)
		{
			for (int j = 0; j < colCount; j++)
			{
				if (matrix[i][j] == 0) {
					rowNeedSetZero[i] = true;
					colNeedSetZero[j] = true;
				}
			}
		}

		for (int row = 0; row < rowCount; row++)
		{
			if (rowNeedSetZero[row]) {
				for (int col = 0; col < colCount; col++)
				{
					matrix[row][col] = 0;
				}
			}
		}

		for (int col = 0; col < colCount; col++)
		{
			if (colNeedSetZero[col]) {
				for (int row = 0; row < rowCount; row++)
				{
					matrix[row][col] = 0;
				}
			}
		}
	}

	void setZeroes1(vector<vector<int>>& matrix) {
		int rowCount = matrix.size();
		int colCount = matrix[0].size();

		bool firstRowWithZero = false;
		bool firstColWithZero = false;
		for (int i = 0; i < rowCount; i++)
		{
			if (matrix[i][0] == 0) {
				firstColWithZero = true;
				break;
			}
		}
		for (int i = 0; i < colCount; i++)
		{
			if (matrix[0][i] == 0) {
				firstRowWithZero = true;
				break;
			}
		}

		for (int i = 0; i < rowCount; i++)
		{
			for (int j = 0; j < colCount; j++) {
				if (matrix[i][j] == 0) {
					matrix[i][0] = 0;
					matrix[0][j] = 0;
				}
			}
		}

		for (int i = 1; i < rowCount; i++)
		{
			if (matrix[i][0] == 0) {
				for (int j = 1; j < colCount; j++)
				{
					matrix[i][j] = 0;
				}
			}
		}

		for (int i = 1; i < colCount; i++)
		{
			if (matrix[0][i] == 0) {
				for (int j = 1; j < rowCount; j++) {
					matrix[j][i] = 0;
				}
			}
		}

		if (firstRowWithZero) {
			for (int i = 0; i < colCount; i++)
			{
				matrix[0][i] = 0;
			}
		}
		if (firstColWithZero) {
			for (int i = 0; i < rowCount; i++)
			{
				matrix[i][0] = 0;
			}
		}
	}
};

//int main() {
//	vector<vector<int>> temp{ {1,1,1},{1,0,1},{1,1,1} };
//	vector<vector<int>> temp1{ {0,1,2,0},{3,4,5,2},{1,3,1,5} };
//	Solution073SetZeroes solution;
//	solution.setZeroes1(temp);
//	solution.setZeroes1(temp1);
//}