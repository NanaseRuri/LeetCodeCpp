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

class Solution072MinDistance
{
public:
	int minDistance(string word1, string word2) {
		int word1Size = word1.size();
		int word2Size = word2.size();

		int dpCol = word1Size + 1;
		int dpRow = word2Size + 1;

		int** dp = new int* [dpCol];
		for (int i = 0; i < dpCol; i++)
		{
			dp[i] = new int[dpRow] {};
		}

		for (int i = 0; i < dpRow; i++)
		{
			dp[0][i] = i;
		}
		for (int i = 0; i < dpCol; i++)
		{
			dp[i][0] = i;
		}

		for (int i = 1; i < dpCol; i++)
		{
			for (int j = 1; j < dpRow; j++) {
				int leftTop = dp[i - 1][j - 1];
				if (word1[i - 1] != word2[j - 1]) {
					++leftTop;
				}
				int top = dp[i - 1][j] + 1;
				int left = dp[i][j - 1] + 1;
				dp[i][j] = min(leftTop, left);
				dp[i][j] = min(dp[i][j], top);
			}
		}

		return dp[word1Size][word2Size];
	}
};

//int main() {
//
//	string word1 = "horse";
//	string word2 = "ros";
//	Solution072MinDistance solution;
//	solution.minDistance(word1, word2);
//}