#include "stdafx.h"

using namespace std;

class Solution097IsInterleave
{
public:
	bool isInterleave(string& s1, string& s2, string& s3) {
		int s1Size = s1.size();
		int s2Size = s2.size();
		int s3Size = s3.size();
		if (s1Size + s2Size != s3Size) {
			return false;
		}

		bool** dp = new bool* [s1Size + 1]{};
		for (int i = 0; i < s1Size + 1; i++)
		{
			dp[i] = new bool[s2Size + 1]{};
		}
		dp[0][0] = true;

		for (int i = 1; i < s1Size + 1; i++)
		{
			dp[i][0] = dp[i - 1][0] && s1[i - 1] == s3[i - 1];
		}

		for (int i = 1; i < s2Size + 1; i++)
		{
			dp[0][i] = dp[0][i - 1] && s2[i - 1] == s3[i - 1];
		}

		for (int i = 1; i < s1Size + 1; i++)
		{
			for (int j = 1; j < s2Size + 1; j++)
			{
				dp[i][j] = dp[i - 1][j] && s1[i - 1] == s3[i + j - 1];
				dp[i][j] = dp[i][j] || (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
			}
		}

		return dp[s1Size][s2Size];
	}
};

//int main() {
//	Solution097IsInterleave solution;
//	string s11 = "aabcc";
//	string s21 = "dbbca";
//	string s31 = "aadbbcbcac";
//
//	string s12 = "aabcc";
//	string s22 = "dbbca";
//	string s32 = "aadbbbaccc";
//
//	string s13 = "";
//	string s23 = "";
//	string s33 = "";
//
//	solution.isInterleave(s11, s21, s31);
//	solution.isInterleave(s12, s22, s32);
//	solution.isInterleave(s13, s23, s33);
//}
