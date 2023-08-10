#include "stdafx.h"

using namespace std;

class Solution231IsPowerOfTwo
{
public:
	bool isPowerOfTwo(int n) {
		return n > 0 && (n & (n - 1)) == 0;
	}
};
