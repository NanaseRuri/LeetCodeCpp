#include "stdafx.h"

using namespace std;

class Solution1281SubtractProductAndSum
{
public:
	int subtractProductAndSum(int n) {
		int multipleResult = 1;
		int sumResult = 0;
		int remainder;

		while (n > 0)
		{
			remainder = n % 10;
			multipleResult *= remainder;
			sumResult *= remainder; 
			n /= 10;
		}

		return multipleResult - sumResult;
	}
};
