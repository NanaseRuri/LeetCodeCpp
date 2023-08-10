#include "stdafx.h"

using namespace std;

class Solution066PlusOne
{
public:
	vector<int> plusOne(vector<int>& digits) {
		bool needCarry = false;
		int digitsSize = digits.size();
		for (int i = digitsSize - 1; i >= 0; i--)
		{
			digits[i] += 1;
			if (digits[i] == 10) {
				digits[i] = 0;
				needCarry = true;
			}
			else {
				needCarry = false;
			}

			if (!needCarry) {
				break;
			}
		}

		if (needCarry) {
			digits.insert(digits.begin(), 1);
		}
		return digits;
	}
};
