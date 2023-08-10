#include "stdafx.h"

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

		// ÿ�����ʳ��ֵĴ���
		int* charaterTotalCount = new int[256]{};
		// �ַ�������ֵĸ���
		unordered_map<char, int> charCountMap;
		// �ܵ��ַ�����
		int totalCharCount = 0;
		// ��ǰ���ַ����������ַ�������ֵĴ�����ͬʱ��һ��������Ҫ���� characterIndexes��indexOfAddedCharacter �Լ� existsIndexes ��ȥ��ͬ��ֵ
		int currentCharCount = 0;
		// ��ʼ�±�
		int minResultStartIndex = -1;
		// ����
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
