#include "stdafx.h"

using namespace std;
class Solution2469ConvertTemperature
{
public:
	vector<double> convertTemperature(double celsius) {
		return { celsius + 273.15,celsius * 1.8 + 32 };
	}
};
