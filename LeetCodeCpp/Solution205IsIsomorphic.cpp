#include "stdafx.h"


using namespace std;

class Solution203RemoveElements
{
public:
	bool isIsomorphic(string s, string t) {
		int sLength = s.length();
		if (sLength != t.length()) {
			return false;
		}
		int* charDicSToT = new int[256]{};
		int* charDicTToS = new int[256]{};

		for (size_t i = 0; i < sLength; i++)
		{
			if (charDicSToT[s[i]] == 0 && charDicTToS[t[i]] == 0) {
				charDicSToT[s[i]] = t[i];
				charDicTToS[t[i]] = s[i];
			}
			else if (charDicSToT[s[i]] != t[i]) {
				return false;
			}
		}

		return true;
	}
};

//int main() {
//	Solution203RemoveElements solution;
//	solution.isIsomorphic("foo", "bar");
//	solution.isIsomorphic("babc", "baba");
//}
