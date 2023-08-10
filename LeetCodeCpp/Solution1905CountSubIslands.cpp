#include "stdafx.h"

using namespace std;

class Solution1905CountSubIslands
{
private:
	static constexpr int dx[4] = { -1, 0, 1, 0 };
	static constexpr int dy[4] = { 0, 1, 0, -1 };

public:
	int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
		int row = grid1.size();
		int col = grid1[0].size();

		auto bfs = [&](int sx, int sy) {
			queue<pair<int, int>> q;
			q.emplace(sx, sy);
			grid2[sx][sy] = 0;
			bool check = grid1[sx][sy];

			while (!q.empty()) {
				auto [x, y] = q.front();
				q.pop();
				for (int i = 0; i < 4; i++) {
					int nx = x + dx[i];
					int ny = y + dy[i];
					if (nx >= 0 && nx < row && ny >= 0 && ny < col && grid2[nx][ny] == 1) {
						q.emplace(nx, ny);
						grid2[nx][ny] = 0;
						if (grid1[nx][ny] != 1) {
							check = false;
						}
					}
				}
			}
			return check;
		};

		int result = 0;

		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if (grid2[i][j] == 1) {
					result += bfs(i, j);
				}
			}
		}

		return result;
	}
};

//int main() {
//    Solution1802NumDifferentIntegers solution;
//    solution.numDifferentIntegers("a1b01c001");
//}
