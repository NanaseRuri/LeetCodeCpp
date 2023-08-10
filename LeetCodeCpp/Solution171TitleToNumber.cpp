#include "stdafx.h"

using namespace std;
class Solution171TitleToNumber {
public:
	int titleToNumber(string columnTitle) {
		int result = 0;
		int aMinus1 = 'A' - 1;
		for (auto& c : columnTitle) {
			result *= 26;
			result += c - aMinus1;
		}

		return result;
	}
};
