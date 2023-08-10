#include "stdafx.h"

using namespace std;

class Solution1314MatrixBlockSum
{
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int row = mat.size();
        int col = mat[0].size();

        vector<vector<int>> preSum(row + 1, vector<int>(col + 1));
        for (int i = 1; i <= row; i++) {
            for (int j = 1; j <= col; j++) {
                preSum[i][j] = mat[i - 1][j - 1] - preSum[i - 1][j - 1] + preSum[i - 1][j] + preSum[i][j - 1];
            }
        }
        
        vector<vector<int>> result(row, vector<int>(col));
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                result[i][j] = Get(preSum, row, col, i + k + 1, j + k + 1) + Get(preSum, row, col, i - k, j - k) - Get(preSum, row, col, i + k + 1, j - k) - Get(preSum, row, col, i - k, j + k + 1);
            }
        }

        return result;
    }

    int Get(vector<vector<int>>& mat, int m, int n, int x, int y) {
        x = max(min(x, m), 0);
        y = max(min(y, n), 0);
        return mat[x][y];
    }
};

//int main() {
//	vector<vector<int>> mats{ {1,2,3}, {4,5,6},{7,8,9} };
//
//	Solution1314MatrixBlockSum solution;
//	solution.matrixBlockSum(mats, 1);
//}
