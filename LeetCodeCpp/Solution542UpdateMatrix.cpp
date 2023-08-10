#include "stdafx.h"

class Solution599FindRestaurant {
public:
	vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
		int totalRow = mat.size();
		int totalCol = mat[0].size();

		queue<pair<int, int>> currentPointQueue;
		// �ҵ���һ������ 0 �ĵ㣬���ڿ�ʼ BFS
		for (int i = 0; i < totalRow; i++) {
			for (int j = 0; j < totalCol; j++) {
				if (mat[i][j] == 0) {
					currentPointQueue.push({ i,j });
				}
			}
		}

		while (!currentPointQueue.empty()) {
			int currentQueueSize = currentPointQueue.size();
			for (int i = 0; i < currentQueueSize; i++) {
				auto point = currentPointQueue.front();
				currentPointQueue.pop();
				int row = point.first;
				int col = point.second;

				if (row > 0 && mat[row - 1][col] == 1) {
					mat[row - 1][col] = mat[row][col] - 1;
					currentPointQueue.push({ row - 1,col });
				}
				if (row < totalRow - 1 && mat[row + 1][col] == 1) {
					mat[row + 1][col] = mat[row][col] - 1;
					currentPointQueue.push({ row + 1,col });
				}
				if (col > 0 && mat[row][col - 1] == 1) {
					mat[row][col - 1] = mat[row][col] - 1;
					currentPointQueue.push({ row,col - 1 });
				}
				if (col < totalCol - 1 && mat[row][col + 1] == 1) {
					mat[row][col + 1] = mat[row][col] - 1;
					currentPointQueue.push({ row,col + 1 });
				}
			}
		}

		// �ҵ���һ������ 0 �ĵ㣬���ڿ�ʼ BFS
		for (int i = 0; i < totalRow; i++) {
			for (int j = 0; j < totalCol; j++) {
				mat[i][j] = -mat[i][j];
			}
		}

		return mat;
	}
};
