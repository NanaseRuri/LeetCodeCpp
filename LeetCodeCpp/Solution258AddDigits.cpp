#include "stdafx.h"

using namespace std;

class Solution258AddDigits
{
public:
	int addDigits(int num) {
		return (num - 1) % 9 + 1;
	}
};
