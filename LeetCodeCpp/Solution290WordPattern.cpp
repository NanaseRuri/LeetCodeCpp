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

class Solution283MoveZeroes
{
public:
	bool wordPattern(string& pattern, string& s) {
		unordered_map<string, char> str2ChMap;
		unordered_map<char, string> ch2StrMap;
		int strLength = s.length();
		int i = 0;
		for (auto ch : pattern) {
			if (i >= strLength) {
				return false;
			}
			int j = i;
			while (j < strLength && s[j] != ' ') {
				j++;
			}
			string currentStr = s.substr(i, j - i);
			if (str2ChMap.count(currentStr) && str2ChMap[currentStr] != ch) {
				return false;
			}
			if (ch2StrMap.count(ch) && ch2StrMap[ch] != currentStr) {
				return false;
			}
			str2ChMap[currentStr] = ch;
			ch2StrMap[ch] = currentStr;
			i = j + 1;
		}
		return i >= strLength;
	}
};