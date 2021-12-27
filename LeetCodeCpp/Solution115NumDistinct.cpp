#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <limits>
#include <stack>
#include <queue>
#include <unordered_set>
#include "ListNode.h"
#include "TreeNode.h"

using namespace std;

class Solution115NumDistinct
{
public:
	int numDistinct(string s, string t) {
		int sSize = s.size();
		int tSize = t.size();

		if (sSize < tSize) {
			return 0;
		}

		unsigned long long** dp = new unsigned long long* [sSize + 1];
		for (int i = 0; i < sSize + 1; i++)
		{
			dp[i] = new unsigned long long[tSize + 1]{};
		}

		for (int i = 0; i < sSize + 1; i++)
		{
			dp[i][tSize] = 1;
		}

		for (int i = sSize - 1; i >= 0; i--)
		{
			for (int j = tSize - 1; j >= 0; j--)
			{
				if (s[i] == t[j]) {
					dp[i][j] = dp[i + 1][j + 1] + dp[i + 1][j];
				}
				else {
					dp[i][j] = dp[i + 1][j];
				}
			}
		}

		return dp[0][0];
	}
};