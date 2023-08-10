#include "stdafx.h"

class Solution742CountPrimeSetBits
{
public:
	int countPrimeSetBits(int left, int right) {
		int result = 0;
		while (left <= right) {
			if ((1 << (GetBitCount(left)) & 665772) != 0) {
				++result;
			}
			++left;
		}

		return result;
	}

	int GetBitCount(int number)
	{
		number = (number & 0x55555555) + ((number >> 1) & 0x55555555);
		number = (number & 0x33333333) + ((number >> 2) & 0x33333333);
		number = (number & 0x0F0F0F0F) + ((number >> 4) & 0x0F0F0F0F);
		number = (number & 0x00FF00FF) + ((number >> 8) & 0x00FF00FF);
		number = (number & 0x0000FFFF) + ((number >> 16) & 0x0000FFFF);

		return number;
	}
};

//int main() {
//	Solution742CountPrimeSetBits solution;
//	solution.countPrimeSetBits(6, 10);
//}
