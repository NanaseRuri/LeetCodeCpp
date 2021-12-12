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

using namespace std;

class Solution087IsScramble
{
private:
	int*** _scam;
	string _s1, _s2;

	bool CharacterSameCount(int s1Index, int s2Index, int length) {
		int* charCount = new int[256]{};

		for (int i = 0; i < length; i++)
		{
			charCount[_s1[s1Index + i]]++;
			charCount[_s2[s2Index + i]]--;
		}

		for (int i = 0; i < 256; i++)
		{
			if (charCount[i] != 0) {
				return false;
			}
		}
		return true;
	}

	bool Dfs(int s1Index, int s2Index, int length) {
		if (_scam[s1Index][s2Index][length]) {
			return _scam[s1Index][s2Index][length] == 1;
		}

		bool subStrSame = true;
		for (int i = 0; i < length; i++)
		{
			if (_s1[s1Index + i] != _s2[s2Index + i]) {
				subStrSame = false;
				break;
			}
		}
		if (subStrSame) {
			return true;
		}

		// 没有交换的情况
		for (int i = 1; i < length; i++)
		{
			if (Dfs(s1Index, s2Index, i) && Dfs(s1Index + i, s2Index + i, length - i)) {
				_scam[s1Index][s2Index][length] = 1;
				return true;
			}
		}

		// 交换的情况
		for (int i = 1; i < length; i++)
		{
			if (Dfs(s1Index + i, s2Index, length - i) && Dfs(s1Index, s2Index + length - i, i)) {
				_scam[s1Index][s2Index][length] = 1;
				return true;
			}
		}

		_scam[s1Index][s2Index][length] = -1;
		return false;
	}

public:
	bool isScramble(string& s1, string& s2) {
		int strSize = s1.size();
		_s1 = s1;
		_s2 = s2;

		_scam = new int** [strSize] {};
		for (int i = 0; i < strSize; i++)
		{
			_scam[i] = new int* [strSize] {};
			for (int j = 0; j < strSize; j++)
			{
				_scam[i][j] = new int[strSize + 1]{};
			}
		}

		return Dfs(0, 0, strSize);
	}
};

//int main() {
//	string s1 = "A";
//	string s2 = "B";
//
//	Solution087IsScramble solution;
//	solution.isScramble(s1, s2);
//
//	s1 = "great";
//	s2 = "rgeat";
//	solution.isScramble(s1, s2);
//}