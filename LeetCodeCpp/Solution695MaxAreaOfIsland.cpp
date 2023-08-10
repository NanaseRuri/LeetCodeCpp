#include "stdafx.h"

class Solution695MaxAreaOfIsland {
public:
	int _row;
	int _col;

	int Dfs(vector<vector<int>>& grid, int row, int col) {
		if (row < 0 || col < 0 || row >= _row || col >= _col || grid[row][col] != 1) {
			return 0;
		}

		grid[row][col] = -1;
		return 1 + Dfs(grid, row - 1, col) + Dfs(grid, row + 1, col) + Dfs(grid, row, col - 1) + Dfs(grid, row, col + 1);
	}

	int maxAreaOfIsland(vector<vector<int>>& grid) {
		_row = grid.size();
		_col = grid[0].size();

		int result = 0;
		for (int row = 0; row < _row; row++) {
			for (int col = 0; col < _col; col++) {
				if (grid[row][col] == 1) {
					result = max(result, Dfs(grid, row, col));
				}
			}
		}

		for (int row = 0; row < _row; row++) {
			for (int col = 0; col < _col; col++) {
				if (grid[row][col] == -1) {
					grid[row][col] = 1;
				}
			}
		}

		return result;
	}
};

//int main() {
//	Solution695MaxAreaOfIsland solution;
//	
//	vector<vector<int>> grid{
//		{0,0,1,0,0,0,0,1,0,0,0,0,0},
//		{0,0,0,0,0,0,0,1,1,1,0,0,0},
//		{0,1,1,0,1,0,0,0,0,0,0,0,0},
//		{0,1,0,0,1,1,0,0,1,0,1,0,0},
//		{0,1,0,0,1,1,0,0,1,1,1,0,0},
//		{0,0,0,0,0,0,0,0,0,0,1,0,0},
//		{0,0,0,0,0,0,0,1,1,1,0,0,0},
//		{0,0,0,0,0,0,0,1,1,0,0,0,0}
//	};
//
//	solution.maxAreaOfIsland(grid);
//}
