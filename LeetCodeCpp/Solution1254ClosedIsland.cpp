#include "stdafx.h"

using namespace std;

class Solution1254ClosedIsland
{
	int _row;
	int _col;
public:
	bool Dfs(vector<vector<int>>& grid, int row, int col) {
		if (row < 0 || col < 0 || row >= _row || col >= _col) {
			return false;
		}

		if (grid[row][col] != 0) {
			return true;
		}

		grid[row][col] = -1;
		bool reusltTop = Dfs(grid, row - 1, col);
		bool reusltBottom = Dfs(grid, row + 1, col);
		bool reusltLeft = Dfs(grid, row, col - 1);
		bool reusltRight = Dfs(grid, row, col + 1);

		return reusltTop && reusltBottom && reusltLeft && reusltRight;
	}

	int closedIsland(vector<vector<int>>& grid) {
		_row = grid.size();
		_col = grid[0].size();

		int result = 0;
		for (int row = 1; row < _row; row++) {
			for (int col = 1; col < _col; col++) {
				if (grid[row][col] == 0) {
					result += Dfs(grid, row, col);
				}
			}
		}

		for (int row = 0; row < _row; row++) {
			for (int col = 0; col < _col; col++) {
				if (grid[row][col] == -1) {
					grid[row][col] = 0;
				}
			}
		}

		return result;
	}
};

//int main() {
//	Solution1254ClosedIsland solution;
//	vector<vector<int>> grid1{
//		{1,1,1,1,1,1,1,0},
//		{1,0,0,0,0,1,1,0},
//		{1,0,1,0,1,1,1,0},
//		{1,0,0,0,0,1,0,1},
//		{1,1,1,1,1,1,1,0}
//	};
//	vector<vector<int>> grid2{
//		{0,0,1,0,0},
//		{0,1,0,1,0},
//		{0,1,1,1,0},
//	};
//	vector<vector<int>> grid3{
//		{0,0,1,1,0,1,0,0,1,0},
//		{1,1,0,1,1,0,1,1,1,0},
//		{1,0,1,1,1,0,0,1,1,0},
//		{0,1,1,0,0,0,0,1,0,1},
//		{0,0,0,0,0,0,1,1,1,0},
//		{0,1,0,1,0,1,0,1,1,1},
//		{1,0,1,0,1,1,0,0,0,1},
//		{1,1,1,1,1,1,0,0,0,0},
//		{1,1,1,0,0,1,0,1,0,1},
//		{1,1,1,0,1,1,0,1,1,0}
//	};
//	solution.closedIsland(grid1);
//	solution.closedIsland(grid2);
//	solution.closedIsland(grid3);
//}
