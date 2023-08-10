#include "stdafx.h"

using namespace std;

class Solution289GameOfLife
{
public:
	void gameOfLife(vector<vector<int>>& board) {
		int rows = board.size();
		int cols = board[0].size();

		for (int row = 0; row < rows; row++)
		{
			for (int col = 0; col < cols; col++)
			{
				int liveNeighbors = 0;
				for (int i = -1; i < 2; i++)
				{
					for (int j = -1; j < 2; j++)
					{
						if (i == 0 && j == 0) {
							continue;
						}
						int x = row + i;
						int y = col + j;
						if (x >= 0 && x < rows && y >= 0 && y < cols && (board[x][y] == 1 || board[x][y] == -1)) {
							++liveNeighbors;
						}
					}
				}

				if (board[row][col] == 1 && (liveNeighbors < 2 || liveNeighbors>3)) {
					board[row][col] = -1;
				}
				if (board[row][col] == 0 && liveNeighbors == 3) {
					board[row][col] = 2;
				}
			}
		}

		for (int row = 0; row < rows; row++)
		{
			for (int col = 0; col < cols; col++)
			{
				if (board[row][col] == -1) {
					board[row][col] = 0;
				}
				else if (board[row][col] == 2) {
					board[row][col] = 1;
				}
			}
		}
	}
};

//int main() {
//	Solution289GameOfLife solution;
//	vector<vector<int>> nums{ {0,1,0},{0,0,1},{1,1,1},{0,0,0} };
//	solution.gameOfLife(nums);
//}
