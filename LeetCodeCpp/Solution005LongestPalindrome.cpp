#include <string>
#include <vector>

using namespace std;
class Solution005LongestPalindrome {
public:
	string longestPalindrome(string s) {
		int maxLength = 0;
		int maxLeft = 0;
		int strLength = s.length();

		int currentLength;
		int currentLeft;
		for (int i = 0; i < strLength; i++)
		{
			currentLength = 0;
			currentLeft = i - currentLength;
			// 回文串为奇数的情况
			for (int j = i; j < strLength && i - currentLength >= 0; j++)
			{
				if (s[j] == s[i - currentLength])
				{
					currentLeft = i - currentLength;
					currentLength++;
				}
				else {
					break;
				}
			}

			currentLength = currentLength * 2 - 1;
			if (currentLength > maxLength) {
				maxLeft = currentLeft;
				maxLength = currentLength;
			}

			currentLength = 0;
			currentLeft = i;
			// 回文串为偶数的情况
			for (int j = i + 1; j < strLength && i - currentLength >= 0; j++)
			{
				if (s[j] == s[i - currentLength])
				{
					currentLeft = i - currentLength;
					currentLength++;
				}
				else {
					break;
				}
			}
			currentLength = currentLength * 2;
			if (currentLength > maxLength) {
				maxLeft = currentLeft;
				maxLength = currentLength;
			}
		}

		return s.substr(maxLeft, maxLength);
	}


	string longestPalindrome1(string s) {
		int n = s.size();
		if (n < 2) {
			return s;
		}

		int maxLen = 1;
		int begin = 0;
		vector<vector<bool>> dp(n, vector<bool>(n));

		for (int i = 0; i < n; i++)
		{
			dp[i][i] = true;
		}

		for (int l = 2; l <= n; l++)
		{
			for (int i = 0; i < n; i++)
			{
				int j = l + i - 1;
				if (j >= n) {
					break;
				}
				if (s[i] != s[j]) {
					dp[i][j] = false;
				}
				else {
					if (j - i < 3) {
						dp[i][j] = true;
					}
					else {
						dp[i][j] = dp[i + 1][j - 1];
					}
				}

				if (dp[i][j] && j - i + 1 > maxLen) {
					maxLen = j - i + 1;
					begin = i;
				}
			}
		}

		return s.substr(begin, maxLen);
	}
};

//int main() {
//	Solution005LongestPalindrome solution;
//	solution.longestPalindrome("cbbd");
//	solution.longestPalindrome("cbdbd");
//}