#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <limits>

using namespace std;

class Solution028StrStr {
public:
	int strStr(string haystack, string needle) {
		int needleLength = needle.size();
		if (needleLength == 0) {
			return 0;
		}

		int haystackLength = haystack.size();
		if (haystackLength < needleLength) {
			return -1;
		}

		int* kmp = new int[needleLength] {};

		int i = 1;
		int j = 0;
		while (j < i && i < needleLength)
		{
			if (needle[i] == needle[j]) {
				++j;
				kmp[i] = j;
				i++;
			}
			else {
				if (j == 0) {
					i++;
				}
				else {
					j = kmp[j - 1];
				}
			}
		}

		int haystackLeft = 0;
		int needleLeft = 0;
		while (haystackLeft + needleLength - needleLeft <= haystackLength) {
			while (needleLeft < needleLength && haystack[haystackLeft] == needle[needleLeft]) {
				needleLeft++;
				haystackLeft++;
			}

			if (needleLeft == needleLength) {
				return haystackLeft - needleLeft;
			}
			else {
				if (needleLeft == 0) {
					haystackLeft++;
				}
				else {
					needleLeft = kmp[needleLeft - 1];
				}
			}
		}

		return -1;
	}
};

//int main() {
//	Solution028StrStr solution;
//	cout << solution.strStr("mississippi", "issip") << endl;
//	cout << solution.strStr("", "") << endl;
//	cout << solution.strStr("a", "a") << endl;
//	cout << solution.strStr("aabaaabaaac", "aabaaac") << endl;
//	cout << solution.strStr("ababcaababcaabc", "ababcaabc") << endl;
//	cout << solution.strStr("mississippi", "pi") << endl;
//}