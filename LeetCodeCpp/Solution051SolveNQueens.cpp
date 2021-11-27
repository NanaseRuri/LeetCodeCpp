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

class Solution051SolveNQueens {
private:
	vector<vector<string>> _result;
	vector<vector<int>> _location;
	void Iteration(vector<int>& currentResult, int** status, int n, int currentRow) {
		if (currentRow == n) {
			_location.push_back(vector<int>(currentResult));
			AddOneResult(currentResult, n);
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

	void AddOneResult(vector<int>& currentResult, int n) {
		vector<string> result;
		for (int i = 0; i < n; i++)
		{
			string s;
			s.append(n, '.');
			s[currentResult[i]] = 'Q';
			result.push_back(s);
		}
		_result.push_back(result);
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
	vector<vector<string>> solveNQueens(int n) {
		_result.clear();
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
			for (int j = 0; j < _location[i].size(); j++)
			{
				_location[i][j] = n - 1 - _location[i][j];
			}
			AddOneResult(_location[i], n);
		}

		return _result;
	}
};

//int main() {
//	Solution051SolveNQueens solution;
//	auto result = solution.solveNQueens(1);
//	result = solution.solveNQueens(2);
//	result = solution.solveNQueens(3);
//	result = solution.solveNQueens(4);
//	result = solution.solveNQueens(5);
//	result = solution.solveNQueens(6);
//	result = solution.solveNQueens(7);
//	result = solution.solveNQueens(8);
//	result = solution.solveNQueens(9);
//}