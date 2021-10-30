#include <string>

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
};

//int main() {
//	Solution005LongestPalindrome solution;
//	solution.longestPalindrome("cbbd");
//	solution.longestPalindrome("cbdbd");
//}