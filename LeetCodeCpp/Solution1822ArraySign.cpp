#include "stdafx.h"

using namespace std;

class Solution1822ArraySign
{
public:
	int arraySign(vector<int>& nums) {
		int sign = 1;

		for (auto& num : nums)
		{
			if (num < 0) {
				sign = -sign;
			}
			else if (num == 0) {
				return 0;
			}
		}

		return sign;
	}
};
