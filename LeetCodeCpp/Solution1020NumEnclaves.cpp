#include "stdafx.h"

using namespace std;

class Solution1020NumEnclaves
{
	int _row;
	int _col;

	void Dfs(vector<vector<int>>& grid, int row, int col) {
		if (row < 0 || col < 0 || row >= _row || col >= _col) {
			return;
		}

		if (grid[row][col] == 1) {
			grid[row][col] = -1;
			Dfs(grid, row - 1, col);
			Dfs(grid, row + 1, col);
			Dfs(grid, row, col - 1);
			Dfs(grid, row, col + 1);
		}
	}

public:
	int numEnclaves(vector<vector<int>>& grid) {
		_row = grid.size();
		_col = grid[0].size();

		for (int i = 0; i < _col; i++) {
			Dfs(grid, 0, i);
			Dfs(grid, _row - 1, i);
		}

		for (int i = 1; i < _row - 1; i++) {
			Dfs(grid, i, 0);
			Dfs(grid, i, _col - 1);
		}

		int result = 0;
		for (int i = 0; i < _row; i++) {
			for (int j = 0; j < _col; j++) {
				if (grid[i][j] == 1) {
					result++;
					grid[i][j] = 1;
				}
				else if (grid[i][j] == -1) {
					grid[i][j] = 1;
				}
			}
		}

		return result;
	}
};
