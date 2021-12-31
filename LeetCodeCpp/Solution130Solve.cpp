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

class Solution130Solve
{
	int _totalRow;
	int _totalCol;
	const char _markChar = 'a';
	void Dfs(vector<vector<char>>& board, int row, int col) {
		if (row < 0 || row >= _totalRow || col < 0 || col >= _totalCol || board[row][col] != 'O') {
			return;
		}

		board[row][col] = _markChar;
		Dfs(board, row - 1, col);
		Dfs(board, row + 1, col);
		Dfs(board, row, col - 1);
		Dfs(board, row, col + 1);
	}

public:
	void solve(vector<vector<char>>& board) {
		_totalRow = board.size();
		_totalCol = board[0].size();

		for (int i = 0; i < _totalCol; i++)
		{
			Dfs(board, 0, i);
			Dfs(board, _totalRow - 1, i);
		}

		for (int i = 0; i < _totalRow; i++)
		{
			Dfs(board, i, 0);
			Dfs(board, i, _totalCol - 1);
		}

		for (int i = 0; i < _totalRow; i++)
		{
			for (int j = 0; j < _totalCol; j++)
			{
				if (board[i][j] == _markChar) {
					board[i][j] = 'O';
				}
				else if (board[i][j] == 'O') {
					board[i][j] = 'X';
				}
			}
		}
	}
};
