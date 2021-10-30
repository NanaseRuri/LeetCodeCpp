#include <string>
#include <iostream>

using namespace std;
class Solution003LongestSubstringWithoutRepeatingCharacters {
public:
	int lengthOfLongestSubstring(string s) {
		int left = 0;
		int maxLength = 0;
		int lastIndex[256];
		for (size_t i = 0; i < 256; i++)
		{
			lastIndex[i] = -1;
		}

		for (size_t i = 0; i < s.length(); i++)
		{
			if (lastIndex[s[i]] != -1) {
				int currentLength = i - left;
				if (maxLength < currentLength) {
					maxLength = currentLength;
				}

				if (left < lastIndex[s[i]] + 1) 
				{
					left = lastIndex[s[i]] + 1;
				}
			}
			lastIndex[s[i]] = i;
		}

		// 遍历到最后
		int lastLength = s.length() - left;
		if (maxLength < lastLength) {
			maxLength = lastLength;
		}

		return maxLength;
	}
};

//int main() {
//	string s = "abcabcbb";
//	string s1 = "bbbbb";
//	string s2 = "pwwkew";
//	string s3 = "";
//	string s4 = "abba";
//	Solution003LongestSubstringWithoutRepeatingCharacters solution;
//	cout << solution.lengthOfLongestSubstring(s) << endl;
//	cout << solution.lengthOfLongestSubstring(s1) << endl;
//	cout << solution.lengthOfLongestSubstring(s2) << endl;
//	cout << solution.lengthOfLongestSubstring(s3) << endl;
//	cout << solution.lengthOfLongestSubstring(s4) << endl;
//}