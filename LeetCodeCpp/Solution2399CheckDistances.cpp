#include "stdafx.h"

using namespace std;
class Solution2399CheckDistances
{
public:
	bool checkDistances(string s, vector<int>& distance) {
		int lastIndex[256]{};

		for (int i = 0; i < s.size(); i++) {
			if (lastIndex[s[i]] != 0 && (i - lastIndex[s[i]]) != distance[s[i] - 'a']) {
				return false;
			}
			lastIndex[s[i]] = i + 1;
		}
		return true;
	}
};
