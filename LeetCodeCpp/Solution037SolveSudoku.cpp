#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <limits>
#include <stack>

using namespace std;

class Solution037SolveSudoku {
private:
	bool _rows[9][9]{};
	bool _cols[9][9]{};
	bool _square[3][3][9]{};
	vector<pair<int, int>> _nonValuePosition;
	int _processCount = 0;
	int _nonValueCount = 0;
	bool _success = false;

	void dfs(vector<vector<char>>& board) {
		if (_processCount == _nonValueCount) {
			_success = true;
			return;
		}

		auto pair = _nonValuePosition[_processCount];
		for (int i = 0; i < 9; i++)
		{
			if (!_rows[pair.first][i] && !_cols[pair.second][i] && !_square[pair.first / 3][pair.second / 3][i]) {
				_rows[pair.first][i] = _cols[pair.second][i] = _square[pair.first / 3][pair.second / 3][i] = true;
				_processCount++;
				dfs(board);
				if (_success) {
					board[pair.first][pair.second] = i + '1';
				}
				else {
					_rows[pair.first][i] = _cols[pair.second][i] = _square[pair.first / 3][pair.second / 3][i] = false;
					_processCount--;
				}
			}
		}
	}
public:
	void solveSudoku(vector<vector<char>>& board) {
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++) {
				if (board[i][j] == '.') {
					_nonValuePosition.push_back({ i,j });
					_nonValueCount++;
				}
				else {
					int value = board[i][j] - '1';
					_rows[i][value] = true;
					_cols[j][value] = true;
					_square[i / 3][j / 3][value] = true;
				}
			}
		}

		dfs(board);
	}
};

//int main() {
//	vector<vector<char>> board =
//	{
//		{'5', '3', '.', '.', '7', '.', '.', '.', '.'} ,
//		{'6', '.', '.', '1', '9', '5', '.', '.', '.'},
//		{'.', '9', '8', '.', '.', '.', '.', '6', '.'},
//		{'8', '.', '.', '.', '6', '.', '.', '.', '3'},
//		{'4', '.', '.', '8', '.', '3', '.', '.', '1'},
//		{'7', '.', '.', '.', '2', '.', '.', '.', '6'},
//		{'.', '6', '.', '.', '.', '.', '2', '8', '.'},
//		{'.', '.', '.', '4', '1', '9', '.', '.', '5'},
//		{'.', '.', '.', '.', '8', '.', '.', '7', '9'},
//	};
//
//	Solution036IsValidSudoku solution;
//	solution.solveSudoku(board);
//}