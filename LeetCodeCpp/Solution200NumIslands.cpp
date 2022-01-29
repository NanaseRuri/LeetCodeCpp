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

class Solution200NumIslands
{
private:
	int _result;
	int _gridRow;
	int _gridCol;
	void Iteration(vector<vector<char>>& grid, int row, int col) {
		if (row < 0 || row >= _gridRow || col < 0 || col >= _gridCol || grid[row][col] != '1') {
			return;
		}
		else {
			grid[row][col] = '*';
			Iteration(grid, row - 1, col);
			Iteration(grid, row + 1, col);
			Iteration(grid, row, col - 1);
			Iteration(grid, row, col + 1);
		}
	}
public:
	int numIslands(vector<vector<char>>& grid) {
		_result = 0;
		_gridRow = grid.size();
		_gridCol = grid[0].size();

		for (int i = 0; i < _gridRow; i++)
		{
			for (int j = 0; j < _gridCol; j++)
			{
				if (grid[i][j] == '1') {
					_result++;
					Iteration(grid, i, j);
				}
			}
		}

		for (int i = 0; i < _gridRow; i++)
		{
			for (int j = 0; j < _gridCol; j++)
			{
				if (grid[i][j] == '*') {
					grid[i][j] = '1';
				}
			}
		}

		return _result;
	}
};
