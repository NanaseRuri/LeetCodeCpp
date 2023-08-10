#include "stdafx.h"

using namespace std;

class Solution085MaximalRectangle
{
public:
	int maximalRectangle(vector<vector<char>>& matrix) {
		int row = matrix.size();
		int  col = matrix[0].size();
		int** continueCount = new int* [row];
		for (int i = 0; i < row; i++)
		{
			continueCount[i] = new int[col] {};
		}

		for (int i = 0; i < row; i++)
		{
			int j = 0;
			while (j < col)
			{
				int tempContinueCount = 0;
				for (int k = j; k < col; k++)
				{
					if (matrix[i][k] == '0') {
						break;
					}
					tempContinueCount++;
				}

				for (int k = 0; k < tempContinueCount; k++)
				{
					continueCount[i][j + k] = tempContinueCount - k;
				}
				if (j + tempContinueCount < col) {
					continueCount[i][j + tempContinueCount] = 0;
				}

				j += tempContinueCount + 1;
			}
		}

		int maxArea = 0;
		stack<int> myStack;
		for (int j = 0; j < col; j++)
		{
			for (int i = 0; i < row; i++)
			{
				if (myStack.empty() || continueCount[i][j] > continueCount[myStack.top()][j]) {
					myStack.push(i);
				}
				else {
					while (!myStack.empty() && continueCount[i][j] <= continueCount[myStack.top()][j])
					{
						int lastHeight = continueCount[myStack.top()][j];
						myStack.pop();
						maxArea = max(maxArea, lastHeight * (myStack.empty() ? i : i - myStack.top() - 1));
					}

					myStack.push(i);
				}
			}

			int lastHeight = 0;
			while (!myStack.empty())
			{
				int lastIndex = myStack.top();
				int width = continueCount[lastIndex][j];
				myStack.pop();
				int tempHeight = myStack.empty() ? lastIndex + 1 : lastIndex - myStack.top();
				maxArea = max(maxArea, width * (tempHeight + lastHeight));
				lastHeight += tempHeight;
			}
		}

		return maxArea;
	}
};

//int main() {
//	vector<vector<char>> matrix1{
//		{'1','0','1','0','0'} ,
//		{'1','0','1','1','1'},
//		{'1','1','1','1','1'},
//		{'1','0','0','1','0'}
//	};
//
//	Solution085MaximalRectangle solution;
//	solution.maximalRectangle(matrix1);
//}
