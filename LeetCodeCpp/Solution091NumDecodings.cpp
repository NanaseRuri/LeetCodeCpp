#include "stdafx.h"

using namespace std;

class Solution091NumDecodings
{
public:
	int numDecodings1(string& s) {
		if (s[0] == '0') {
			return 0;
		}

		int sSize = s.size();

		int result = 0;
		int preResult = 1;
		int theResultBeforePreResult;
		for (int i = 0; i < sSize; i++)
		{
			result = 0;
			if (s[i] != '0') {
				result += preResult;
			}
			if (i > 0 && s[i - 1] != '0' && ((s[i - 1] - '0') * 10 + s[i] - '0') <= 26) {
				result += theResultBeforePreResult;
			}

			theResultBeforePreResult = preResult;
			preResult = result;
		}
		
		return result;
	}

	int numDecodings(string& s) {
		if (s[0] == '0') {
			return 0;
		}

		int sSize = s.size();
		int* dp = new int[sSize + 1]{};
		dp[0] = 1;
		for (int i = 0; i < sSize; i++)
		{
			if (s[i] != '0') {
				dp[i + 1] += dp[i];
			}
			if (i > 0 && s[i - 1] != '0' && ((s[i - 1] - '0') * 10 + s[i] - '0') <= 26) {
				dp[i + 1] += dp[i - 1];
			}
		}

		return dp[sSize];
	}
};

//int main() {
//	Solution091NumDecodings solution;
//
//	string s = "12";
//	cout << solution.numDecodings(s) << endl;
//
//	s = "226";
//	cout << solution.numDecodings(s) << endl;
//
//	s = "0";
//	cout << solution.numDecodings(s) << endl;
//
//	s = "20";
//	cout << solution.numDecodings(s) << endl;
//
//	s = "30";
//	cout << solution.numDecodings(s) << endl;
//
//	s = "06";
//	cout << solution.numDecodings1(s) << endl;
//
//	s = "1000";
//	cout << solution.numDecodings1(s) << endl;
//
//	s = "26";
//	cout << solution.numDecodings(s) << endl;
//
//	s = "2611055971756562";
//	cout << solution.numDecodings(s) << endl;
//}
