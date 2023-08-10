#include "stdafx.h"

using namespace std;

class Solution1137Tribonacci
{
public:
	int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
		int resultHeight = 0;

		int n = books.size();
		vector<int> dp(n + 1, 1000000);

		dp[0] = 0;
		for (int i = 0; i < n; i++) {
			int currentWidth = 0;
			int currentHeight = 0;
			for (int j = i; j >= 0; j--) {
				currentWidth += books[j][0];
				if (currentWidth > shelfWidth) {
					break;
				}
				currentHeight = max(currentHeight, books[j][1]);
				dp[i + 1] = min(dp[i + 1], dp[j] + currentHeight);
			}
		}

		return dp[n];
	}
};
