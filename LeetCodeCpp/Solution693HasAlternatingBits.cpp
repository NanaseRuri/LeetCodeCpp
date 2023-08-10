#include "stdafx.h"

class Solution693HasAlternatingBits {
public:
	bool hasAlternatingBits(int n) {
		int lastBitAnd = n & 1;
		n >>= 1;

		while (n > 0)
		{
			if ((n & 1) == lastBitAnd) {
				return false;
			}

			lastBitAnd = n & 1;
			n >>= 1;
		}
		return true;
	}
};
