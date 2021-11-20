#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <limits>
#include <stack>

using namespace std;

class Solution036IsValidSudoku {
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		int horizontal[9][9]{};
		int vertical[9][9]{};
		int square[3][3][9]{};

		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++) {
				if (board[i][j] != '.') {
					int value = board[i][j] - '1';
					horizontal[i][value]++;
					vertical[j][value]++;
					square[i / 3][j / 3][value]++;

					if (horizontal[i][value] > 1 || vertical[j][value] > 1 || square[i / 3][j / 3][value] > 1) {
						return false;
					}
				}
			}
		}

		return true;
	}
};