#include "stdafx.h"

using namespace std;

class Solution1641CountVowelStrings
{
public:
	int countVowelStrings(int n) {
		vector<int> dp{ 1,1,1,1,1 };

		for (int i = 1; i < n; i++) {
			for (int j = 4; j > 0; j--) {
				dp[j - 1] += dp[j];
			}
		}

		return accumulate(dp.begin(), dp.end(), 0);
	}

	int countVowelStrings1(int n) {
		return (n + 4) * (n + 3) * (n + 2) * (n + 1) / 4 / 3 / 2;
	}
};
