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

class Solution059GenerateMatrix {
public:
	vector<vector<int>> generateMatrix(int n) {
		vector<vector<int>> result(n, vector<int>(n, 0));

		int index = 0;
		int currentValue = 1;
		int lastValue = n * n;
		int currentRow;
		int currentCol;
		while (true)
		{
			currentRow = index;
			for (int i = index; i < n - index; i++)
			{
				result[currentRow][i] = currentValue;
				++currentValue;
			}
			if (currentValue > lastValue) {
				break;
			}

			currentCol = n - 1 - index;
			for (int i = index + 1; i < n - index; i++)
			{
				result[i][currentCol] = currentValue;
				++currentValue;
			}

			currentRow = n - index - 1;
			for (int i = currentCol - 1; i >= index; --i)
			{
				result[currentRow][i] = currentValue;
				++currentValue;
			}
			if (currentValue > lastValue) {
				break;
			}

			currentCol = index;
			for (int i = currentRow - 1; i > index; --i)
			{
				result[i][currentCol] = currentValue;
				++currentValue;
			}
			index++;
		}

		return result;
	}
};

//int main() {
//	Solution059GenerateMatrix solution;
//	solution.generateMatrix(3);
//	solution.generateMatrix(1);
//	solution.generateMatrix(2);
//	solution.generateMatrix(4);
//}