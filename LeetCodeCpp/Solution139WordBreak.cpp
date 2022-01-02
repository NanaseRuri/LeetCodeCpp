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
#include "Node.h"
#include <set>

using namespace std;

class Solution139WordBreak
{
public:
	bool wordBreak(string s, vector<string>& wordDict) {
		int minWordSize = INT32_MAX;
		int maxWordSize = 1;
		unordered_set<string> wordSet;
		for (auto word : wordDict)
		{
			minWordSize = min(minWordSize, (int)word.size());
			maxWordSize = max(maxWordSize, (int)word.size());
			wordSet.insert(word);
		}

		int sLength = s.length();
		vector<bool> dp(sLength + 1);
		dp[0] = true;

		for (int i = 1; i <= sLength; i++)
		{
			for (int j = 0; j < i; j++)
			{
				if (i - j < minWordSize) {
					break;
				}
				if (i - j > maxWordSize) {
					continue;
				}
				if (dp[j] && wordSet.find(s.substr(j, i - j)) != wordSet.end()) {
					dp[i] = true;
					break;
				}
			}
		}
		return dp[sLength];
	}
};

//int main() {
//	string s = "applepenapple";
//	vector<string> wordDict{ "apple", "pen" };
//	Solution139WordBreak solution;
//	solution.wordBreak(s, wordDict);
//}