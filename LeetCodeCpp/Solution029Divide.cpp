#include "stdafx.h"

using namespace std;

class Solution029Divide {
public:
	int divide(int dividend, int divisor) {
		if (dividend == 0) {
			return 0;
		}

		if (dividend == INT32_MIN) {
			if (divisor == -1) {
				return INT32_MAX;
			}
			else if (divisor == INT32_MIN)
			{
				return 1;
			}
		}

		if (divisor == INT32_MIN) {
			return 0;
		}

		unsigned int quotient = 0;
		bool positive = ((dividend >= 0) == (divisor > 0));
		unsigned int unsignedDividend = dividend > 0 ? dividend : ((unsigned int)dividend - 1) ^ 0xFFFFFFFF;
		unsigned int unsignedDivisor = divisor > 0 ? divisor : ((unsigned int)divisor - 1) ^ 0xFFFFFFFF;
		unsigned int maxLimit = UINT32_MAX >> 1;

		while (unsignedDividend >= unsignedDivisor) {
			unsigned int currentDivisor = unsignedDivisor;
			unsigned int quotientTemp = 0;
			while (unsignedDividend >= currentDivisor && currentDivisor <= maxLimit) {
				currentDivisor = currentDivisor << 1;

				if (quotientTemp == 0) {
					quotientTemp = 1;
				}
				else {
					quotientTemp = quotientTemp << 1;
				}
			}
			unsignedDividend -= currentDivisor >> 1;
			quotient += quotientTemp == 0 ? 1 : quotientTemp;
		}

		return positive ? quotient : (quotient ^ 0xFFFFFFFF) + 1;
	}
};

//int main() {
//	Solution029Divide divide;
//	cout << divide.divide(10, 3) << endl;
//	cout << divide.divide(10, -3) << endl;
//	cout << divide.divide(-10, 3) << endl;
//	cout << divide.divide(-10, -3) << endl;
//
//	cout << divide.divide(INT32_MAX, 1) << endl;
//	cout << divide.divide(INT32_MAX, -1) << endl;
//	cout << divide.divide(INT32_MAX, INT32_MIN) << endl;
//	cout << divide.divide(INT32_MAX, INT32_MAX) << endl;
//	cout << divide.divide(INT32_MIN, 1) << endl;
//	cout << divide.divide(INT32_MIN, -1) << endl;
//	cout << divide.divide(INT32_MIN, INT32_MIN) << endl;
//	cout << divide.divide(INT32_MIN, INT32_MAX) << endl;
//}
