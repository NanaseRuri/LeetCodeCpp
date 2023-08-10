#include "stdafx.h"

using namespace std;
class Solution010IsMatch {
public:
	/// <summary>
	/// 
	/// </summary>
	/// <param name="s">��ƥ���ַ���</param>
	/// <param name="p">�������ʽ</param>
	/// <returns></returns>
	bool isMatch(string target, string regular) {

		int targetLength = target.length();
		int regularLength = regular.length();
		int dpTargetLength = targetLength + 1;
		int dpRegularLength = regularLength + 1;

		bool** dp = new bool* [dpTargetLength];
		for (int i = 0; i < dpTargetLength; i++)
		{
			dp[i] = new bool[dpRegularLength] {};
		}

		dp[0][0] = true;

		for (int i = 0; i < dpTargetLength; i++)
		{
			for (int j = 1; j < dpRegularLength; j++)
			{
				if (regular[j - 1] == '*') {
					dp[i][j] = dp[i][j - 2];
					if (i != 0 && (regular[j - 2] == '.' || target[i - 1] == regular[j - 2])) {
						dp[i][j] = dp[i][j] || dp[i - 1][j];
					}
				}
				else {
					if (i != 0) {
						dp[i][j] = dp[i - 1][j - 1] && (regular[j - 1] == '.' || target[i - 1] == regular[j - 1]);
					}
				}
			}
		}
		return dp[targetLength][regularLength];
	}
};

//int main() {
//	Solution010IsMatch match;
//	cout << match.isMatch("aa", "a") << endl;
//	cout << match.isMatch("aa", "a*") << endl;
//	cout << match.isMatch("aab", "c*a*b") << endl;
//	cout << match.isMatch("aaa", "aaaa") << endl;
//	cout << match.isMatch("ab", ".*") << endl;
//	cout << match.isMatch("ab", ".*..") << endl;
//}
