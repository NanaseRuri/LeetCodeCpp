#include "stdafx.h"

using namespace std;

class Solution2169CountOperations
{
public:
	int countOperations(int num1, int num2) {
		int count = 0;
		while (num1 != 0 && num2 != 0)
		{
			count += 1;

			int minValue = min(num1, num2);
			num1 = num1 + num2 - (minValue << 1);
			num2 = minValue;
		}
		return count;
	}
};
