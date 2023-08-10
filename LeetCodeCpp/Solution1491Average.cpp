#include "stdafx.h"

using namespace std;

class Solution1491Average
{
public:
	double average(vector<int>& salary) {
		int currentMax = INT32_MIN;
		int currentMin = INT32_MAX;
		int sum = 0;

		for (auto& s : salary)
		{
			currentMax = max(currentMax, s);
			currentMin = min(currentMin, s);
			sum += s;
		}

		return ((double)sum - currentMax - currentMin) / (salary.size() - 2);
	}
};
