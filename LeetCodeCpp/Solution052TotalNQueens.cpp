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

class Solution052TotalNQueens {
private:
	vector<vector<int>> _location;
	int _result = 0;

	void Iteration(vector<int>& currentResult, int** status, int n, int currentRow) {
		if (currentRow == n) {
			_result++;
			_location.push_back(vector<int>(currentResult));
			return;
		}

		for (int i = 0; i < n; i++)
		{
			if (status[currentRow][i] == 0) {
				currentResult.push_back(i);
				SetPositionStatus(status, n, currentRow, i, 1);
				Iteration(currentResult, status, n, currentRow + 1);
				currentResult.pop_back();
				SetPositionStatus(status, n, currentRow, i, -1);
			}
		}
	}

	void SetPositionStatus(int** status, int n, int currentRow, int currentCol, int setStaus) {
		int index = 1;
		for (int i = currentRow; i < n - 1; i++)
		{
			status[currentRow + index][currentCol] += setStaus;
			if (currentCol - index >= 0) {
				status[currentRow + index][currentCol - index] += setStaus;
			}
			if (currentCol + index < n) {
				status[currentRow + index][currentCol + index] += setStaus;
			}
			index++;
		}
	}
public:
	int totalNQueens(int n) {
		_result = 0;
		_location.clear();

		int** status = new int* [n];
		for (int i = 0; i < n; i++)
		{
			status[i] = new int[n] {};
		}
		vector<int> currentResult;

		int interationTime = n / 2 + n % 2;
		for (int i = 0; i < interationTime; i++)
		{
			currentResult.push_back(i);
			SetPositionStatus(status, n, 0, i, 1);
			Iteration(currentResult, status, n, 1);
			currentResult.pop_back();
			SetPositionStatus(status, n, 0, i, -1);
		}

		for (int i = 0; i < _location.size(); i++)
		{
			if (_location[i][0] == interationTime - 1 && n % 2 == 1) {
				break;
			}
			_result++;
		}
		return _result;
	}
};

//int main() {
//	Solution052TotalNQueens solution;
//	solution.totalNQueens(1);
//	solution.totalNQueens(4);
//	solution.totalNQueens(5);
//	solution.totalNQueens(6);
//}