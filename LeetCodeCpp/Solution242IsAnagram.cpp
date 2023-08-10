#include "stdafx.h"

using namespace std;

class Solution242IsAnagram
{
public:
	bool isAnagram(string s, string t) {
		if (s.size() != t.size()) {
			return false;
		}
		unordered_map<char, int> charCountOfS;
		for (auto& c : s)
		{
			++charCountOfS[c];
		}

		for (auto& c : t)
		{
			--charCountOfS[c];
		}

		for (auto& charCountPair : charCountOfS)
		{
			if (charCountPair.second != 0) {
				return false;
			}
		}

		return true;
	}
};
