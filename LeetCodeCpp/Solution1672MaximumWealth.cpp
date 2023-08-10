#include "stdafx.h"

using namespace std;

class Solution1672MaximumWealth
{
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int row = accounts.size();
        int col = accounts[0].size();
        int result = 0;

        for (int i = 0; i < row; i++) {
            int currentResult = 0;
            for (int j = 0; j < col; j++) {
                currentResult += accounts[i][j];
            }
            result = max(currentResult, result);
        }

        return result;
    }
};
