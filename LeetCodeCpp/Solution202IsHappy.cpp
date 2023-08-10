#include "stdafx.h"


using namespace std;

class Solution202IsHappy
{
private:
	int GetNextValue(int n) {
		int result = 0;
		while (n != 0)
		{
			result += (n % 10) * (n % 10);
			n /= 10;
		}
		return result;
	}

public:
	bool isHappy(int n) {
		int slowValue = GetNextValue(n);
		int fastValue = GetNextValue(GetNextValue(n));

		while (fastValue != 1 && slowValue != fastValue)
		{
			slowValue = GetNextValue(slowValue);
			fastValue = GetNextValue(GetNextValue(fastValue));
		}

		return fastValue == 1;
	}
};

//int main() {
//	Solution202IsHappy solution;
//	solution.isHappy(4);
//	solution.isHappy(19);
//	solution.isHappy(2);
//}
