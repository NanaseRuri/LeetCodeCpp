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

class Solution079Exist
{
private:
	bool Iteration(bool** charUsed, vector<vector<char>>& board, string& word, int row, int col, int index) {
		if (index == word.size()) {
			return true;
		}

		if (row > 0 && !charUsed[row - 1][col] && board[row - 1][col] == word[index]) {
			charUsed[row - 1][col] = true;
			if (Iteration(charUsed, board, word, row - 1, col, index + 1)) {
				return true;
			}
			charUsed[row - 1][col] = false;
		}

		if (row + 1 < board.size() && !charUsed[row + 1][col] && board[row + 1][col] == word[index]) {
			charUsed[row + 1][col] = true;
			if (Iteration(charUsed, board, word, row + 1, col, index + 1)) {
				return true;
			}
			charUsed[row + 1][col] = false;
		}

		if (col > 0 && !charUsed[row][col - 1] && board[row][col - 1] == word[index]) {
			charUsed[row][col - 1] = true;
			if (Iteration(charUsed, board, word, row, col - 1, index + 1)) {
				return true;
			}
			charUsed[row][col - 1] = false;
		}

		if (col + 1 < board[0].size() && !charUsed[row][col + 1] && board[row][col + 1] == word[index]) {
			charUsed[row][col + 1] = true;
			if (Iteration(charUsed, board, word, row, col + 1, index + 1)) {
				return true;
			}
			charUsed[row][col + 1] = false;
		}

		return false;
	}

public:
	bool exist(vector<vector<char>>& board, string& word) {
		int row = board.size();
		int col = board[0].size();
		bool** charUsed = new bool* [row];
		for (int i = 0; i < row; i++)
		{
			charUsed[i] = new bool[col] {};
		}

		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++) {
				if (board[i][j] == word[0]) {
					charUsed[i][j] = true;
					if (Iteration(charUsed, board, word, i, j, 1))
					{
						return true;
					}
					charUsed[i][j] = false;
				}
			}
		}
		return false;
	}
};


//int main() {
//	vector<vector<char>> boards{
//		{'A','B','C','E'},
//		{'S','F','C','S'},
//		{'A','D','E','E'}
//	};
//
//	string word = "ABCCED";
//	string word1 = "ABCE";
//
//	Solution079Exist solution;
//	cout << solution.exist(boards, word) << endl;
//	cout << solution.exist(boards, word1) << endl;
//}