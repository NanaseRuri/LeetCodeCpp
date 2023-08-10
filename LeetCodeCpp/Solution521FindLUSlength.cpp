#include "stdafx.h"

using namespace std;

class Solution521FindLUSlength
{
public:
	int findLUSlength(string a, string b) {
		return a == b ? -1 : max(a.length(), b.length());
	}
};
