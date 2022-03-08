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

class Solution392IsSubsequence
{
public:
	bool isSubsequence(string s, string t) {
		int sLeft = 0;
		int tLeft = 0;
		int sSize = s.size();
		int tSize = t.size();

		while (sLeft < sSize && tLeft < tSize)
		{
			if (s[sLeft] == t[tLeft]) {
				++sLeft;
			}
			++tLeft;
		}

		return sLeft == sSize;
	}

	bool isSubsequence1(string s, string t) {
		int n = s.size();
		int m = t.size();

		vector<vector<int>> f(m + 1, vector<int>(26, 0));
		for (int i = 0; i < 26; i++)
		{
			f[m][i] = m;
		}

		for (int i = m - 1; i >= 0; i--) {
			for (int j = 0; j < 26; j++)
			{
				if (t[i] == j + 'a') {
					f[i][j] = i;
				}
				else
				{
					f[i][j] = f[i + 1][j];
				}
			}
		}

		int add = 0;
		for (int i = 0; i < n; i++) {
			if (f[add][s[i] - 'a'] == m) {
				return false;
			}
			add = f[add][s[i] - 'a'] + 1;
		}

		return true;
	}
};
