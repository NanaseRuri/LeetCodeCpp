#include "stdafx.h"

using namespace std;
class Solution044IsMatch {
public:
	/// <summary>
	/// 
	/// </summary>
	/// <param name="s">��ƥ���ַ���</param>
	/// <param name="p">�������ʽ</param>
	/// <returns></returns>
	bool isMatch(string s, string p) {
		int sSize = s.size();
		int pSize = p.size();
		bool** dp = new bool* [sSize + 1];
		for (int i = 0; i < sSize + 1; i++)
		{
			dp[i] = new bool[pSize + 1]{};
		}
		dp[0][0] = true;

		for (int i = 0; i < sSize + 1; i++)
		{
			for (int j = 1; j < pSize + 1; j++) {
				if (p[j - 1] == '*') {
					if (i != 0) {
						dp[i][j] = dp[i][j - 1] || dp[i - 1][j - 1] || dp[i - 1][j];
					}
					else {
						dp[i][j] = dp[i][j - 1];
					}
				}
				else {
					if (i != 0) {
						dp[i][j] = dp[i - 1][j - 1] && (p[j - 1] == '?' || p[j - 1] == s[i - 1]);
					}
				}
			}
		}

		return dp[sSize][pSize];
	}

	bool isMatch1(string s, string p) {
		int sRight = s.size();
		int pRight = p.size();

		while (sRight > 0 && pRight > 0 && p[pRight - 1] != '*')
		{
			if (s[sRight - 1] != p[pRight - 1] && p[pRight - 1] != '?') {
				return false;
			}
			--sRight;
			--pRight;
		}

		if (pRight == 0) {
			return sRight == 0;
		}

		int sLeft = 0;
		int pLeft = 0;
		int sRecord = -1;
		int pRecord = -1;
		while (sLeft < sRight && pLeft < pRight)
		{
			if (p[pLeft] == '*') {
				++pLeft;
				pRecord = pLeft;
				sRecord = sLeft;
			}
			else if (p[pLeft] == s[sLeft] || p[pLeft] == '?') {
				++pLeft;
				++sLeft;
			}
			else if (pRecord != -1) {
				++sRecord;
				sLeft = sRecord;
				pLeft = pRecord;
			}
			else {
				return false;
			}
		}

		for (int i = pLeft; i < pRight; i++)
		{
			if (p[i] != '*') {
				return false;
			}
		}
		return true;
	}
};

//int main() {
//	string s = "aa";
//	string p = "*";
//
//	string s1 = "aa";
//	string p1 = "a";
//
//	string s2 = "cb";
//	string p2 = "?a";
//
//	string s3 = "adceb";
//	string p3 = "*a*b";
//
//	string s4 = "adceb";
//	string p4 = "a*c?b";
//
//	string s5 = "acdeb";
//	string p5 = "a*c?b";
//
//
//	Solution044IsMatch solution;
//	cout << solution.isMatch(s, p) << endl;
//	cout << solution.isMatch(s1, p1) << endl;
//	cout << solution.isMatch(s2, p2) << endl;
//	cout << solution.isMatch(s3, p3) << endl;
//	cout << solution.isMatch(s4, p4) << endl;
//	cout << solution.isMatch(s5, p5) << endl;
//	cout << endl;
//	cout << solution.isMatch1(s, p) << endl;
//	cout << solution.isMatch1(s1, p1) << endl;
//	cout << solution.isMatch1(s2, p2) << endl;
//	cout << solution.isMatch1(s3, p3) << endl;
//	cout << solution.isMatch1(s4, p4) << endl;
//	cout << solution.isMatch1(s5, p5) << endl;
//}
