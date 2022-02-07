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

class Solution214ShortestPalindrome
{
public:
	string shortestPalindrome2(string s) {
		int sLength = s.length();
		if (sLength <= 1) {
			return s;
		}

		int palindromePrefixEndIndex = GetPalindromePrefixEndIndex(s);
		if (palindromePrefixEndIndex == sLength) {
			return s;
		}

		string appendStr = s.substr(palindromePrefixEndIndex, sLength);
		reverse(appendStr.begin(), appendStr.end());

		return appendStr + s;
	}

	int GetPalindromePrefixEndIndex(string s) {
		int sLength = s.length();

		string processS;
		processS += "#";
		for (int i = 0; i < sLength; i++)
		{
			processS += s[i];
			processS += "#";
		}
		int processSLength = processS.length();
		int* p = new int[processSLength / 2 + 1]{};
		int c = 0;
		int r = 0;

		for (int i = 1; i <= processSLength / 2; i++)
		{
			int mirror = 2 * c - i;
			if (r > i) {
				p[i] = min(r - i, p[mirror]);
			}
			else
			{
				p[i] = 0;
			}

			int left = i - 1 - p[i];
			int right = i + 1 + p[i];
			while (right < processSLength && left >= 0 && processS[left] == processS[right])
			{
				p[i]++;
				right++;
				left--;
			}

			if (i + p[i] > r) {
				c = i;
				r = i + p[i];
			}
		}

		int length = 0;
		for (int i = 0; i <= processSLength / 2; i++)
		{
			if (p[i] - i == 0) {
				length = i;
			}
		}

		return length;
	}

	string shortestPalindrome(string s) {
		int sLength = s.length();
		vector<int> fail(sLength, -1);
		for (int i = 1; i < sLength; i++)
		{
			int j = fail[i - 1];
			while (j != -1 && s[j + 1] != s[i]) {
				j = fail[j];
			}
			if (s[j + 1] == s[i])
			{
				fail[i] = j + 1;
			}
		}

		int best = -1;
		for (int i = sLength - 1; i >= 0; i--)
		{
			while (best != -1 && s[best + 1] != s[i]) {
				best = fail[best];
			}
			if (s[best + 1] == s[i]) {
				++best;
			}
		}

		string add = (best == sLength - 1 ? "" : s.substr(best + 1, sLength));
		reverse(add.begin(), add.end());
		return add + s;
	}

	string shortestPalindrome1(string s) {
		int sLength = s.length();
		if (sLength <= 1) {
			return s;
		}

		int palindromeStartIndex = 0;
		bool currentIsPalindrome;
		for (int i = sLength; i > 0; i--)
		{
			currentIsPalindrome = true;
			for (int j = 0; j <= i / 2; j++)
			{
				if (s[j] != s[i - j - 1]) {
					currentIsPalindrome = false;
					break;
				}
			}
			if (currentIsPalindrome) {
				palindromeStartIndex = i;
				break;
			}
		}
		string result;
		for (int i = sLength - 1; i >= palindromeStartIndex; i--)
		{
			result += s[i];
		}
		result += s;

		return result;
	}
};

//int main() {
//	Solution214ShortestPalindrome solution;
//	solution.shortestPalindrome1("aacecaaa");
//	solution.shortestPalindrome1("aacecaaaa");
//	solution.shortestPalindrome1("abcd");
//	solution.shortestPalindrome1("abcd");
//
//	cout << solution.shortestPalindrome2("aacecaaa") << endl;
//	cout << solution.shortestPalindrome2("aacecaaaa") << endl;
//	cout << solution.shortestPalindrome2("abcd") << endl;
//	cout << solution.shortestPalindrome2("aba") << endl;
//}