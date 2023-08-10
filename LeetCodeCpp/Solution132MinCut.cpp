#include "stdafx.h"

using namespace std;

class Solution132MinCut
{
public:
	int minCut(string s) {
		vector<vector<bool>> palidromeRecord;
		int sLength = s.size();
		palidromeRecord.assign(sLength, vector<bool>(sLength, true));

		for (int i = sLength - 2; i >= 0; i--)
		{
			for (int j = i + 1; j < sLength; j++)
			{
				palidromeRecord[i][j] = palidromeRecord[i + 1][j - 1] && s[i] == s[j];
			}
		}

		vector<int> minCut(sLength, INT32_MAX);
		for (int i = 0; i < sLength; i++)
		{
			if (palidromeRecord[0][i]) {
				minCut[i] = 0;
			}
			else
			{
				for (int j = 0; j < i; j++)
				{
					if (palidromeRecord[j + 1][i]) {
						minCut[i] = min(minCut[i], minCut[j] + 1);
					}					
				}
			}
		}

		return minCut[sLength - 1];
	}
};


//int main() {
//	string s = "aab";
//	string s1 = "ccaacabacb";
//	Solution132MinCut solution;
//	solution.minCut(s);
//	solution.minCut(s1);
//}
