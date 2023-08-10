#include "stdafx.h"

using namespace std;

class Solution389FindTheDifference
{
public:
    char findTheDifference(string s, string t) {
		int result = 0;
		for (auto& c:s)
		{
			result ^= c;
		}
		for (auto& c:t)
		{
			result ^= c;
		}

		return result;
    }
};
