#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <limits>
#include <stack>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution076MinWindow
{
public:
	string minWindow(string s, string t) {
		int sSize = s.size();
		int tSize = t.size();

		if (tSize > sSize) {
			return "";
		}

		// 每个单词出现的次数
		int* charaterTotalCount = new int[256]{};
		// 字符与其出现的个数
		unordered_map<char, int> charCountMap;
		// 总的字符个数
		int totalCharCount = 0;
		// 当前的字符个数，当字符与其出现的次数相同时加一，否则需要根据 characterIndexes、indexOfAddedCharacter 以及 existsIndexes 减去等同的值
		int currentCharCount = 0;
		// 起始下标
		int minResultStartIndex = -1;
		// 长度
		int minResultLength = INT32_MAX;

		int slidingWindowStartIndex = 0;
		int slidingWindowEndIndex = 0;

		for (size_t i = 0; i < tSize; i++)
		{
			if (charaterTotalCount[t[i]] == 0) {
				totalCharCount++;
				charCountMap.insert({ t[i], 0 });
			}
			charaterTotalCount[t[i]]++;
		}

		for (int i = 0; i < sSize; ++i, ++slidingWindowEndIndex)
		{
			int currentChar = s[i];
			int charaterNeedCount = charaterTotalCount[currentChar];
			if (charaterNeedCount > 0) {
				++charCountMap[currentChar];
				if (charCountMap[currentChar] == charaterNeedCount) {
					++currentCharCount;
				}

				if (currentCharCount == totalCharCount) {
					while (true)
					{
						char windowsStartChar = s[slidingWindowStartIndex];

						if (charaterTotalCount[windowsStartChar] > 0) {
							if (charCountMap[windowsStartChar] == charaterTotalCount[windowsStartChar]) {
								--charCountMap[windowsStartChar];
								--currentCharCount;
								break;
							}
							else {
								--charCountMap[windowsStartChar];
							}
						}
						++slidingWindowStartIndex;
					}

					int currentWordLength = slidingWindowEndIndex - slidingWindowStartIndex + 1;
					if (currentWordLength < minResultLength) {
						minResultStartIndex = slidingWindowStartIndex;
						minResultLength = currentWordLength;
					}
					++slidingWindowStartIndex;
				}
			}
		}

		if (minResultStartIndex == -1) {
			return "";
		}
		else {
			return s.substr(minResultStartIndex, minResultLength);
		}
	}
};


//int main()
//{
//	string s1 = "ADOBECODEBANC";
//	string t1 = "ABC";
//
//	string s2 = "a";
//	string t2 = "a";
//
//	string s3 = "a";
//	string t3 = "aa";
//
//	string s4 = "aaaaaaaaaaaabbbbbcdd";
//	string t4 = "abcdd";
//
//	Solution076MinWindow solution;
//	cout << solution.minWindow(s1, t1) << endl;
//	cout << solution.minWindow(s2, t2) << endl;
//	cout << solution.minWindow(s3, t3) << endl;
//	cout << solution.minWindow(s4, t4) << endl;
//}