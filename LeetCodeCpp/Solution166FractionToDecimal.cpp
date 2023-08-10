#include "stdafx.h"

using namespace std;
class Solution166FractionToDecimal {
public:
	string fractionToDecimal(int numerator, int denominator) {
		long numeratorLong = numerator;
		long denominatorLong = denominator;

		if (numeratorLong % denominatorLong == 0) {
			return to_string(numeratorLong / denominatorLong);
		}

		numeratorLong = abs(numeratorLong);
		denominatorLong = abs(denominatorLong);
		string result;
		if ((numerator ^ denominator) < 0) {
			result.push_back('-');
		}

		long integerPart = numeratorLong / denominatorLong;
		result += to_string(integerPart);
		result.push_back('.');

		string fractionPart;
		unordered_map<long, int> remainderIndexMap;
		long remainder = numeratorLong % denominatorLong;
		int index = 0;
		while (remainder != 0 && remainderIndexMap.find(remainder) == remainderIndexMap.end())
		{
			remainderIndexMap[remainder] = index;
			remainder *= 10;
			fractionPart += to_string(remainder / denominatorLong);
			remainder %= denominatorLong;
			index++;
		}
		if (remainder != 0) {
			int insertIndex = remainderIndexMap[remainder];
			fractionPart = fractionPart.substr(0, insertIndex) + '(' + fractionPart.substr(insertIndex) + ')';
		}
		result += fractionPart;

		return result;
	}
};

//int main() {
//	Solution166FractionToDecimal solution;
//	cout << solution.fractionToDecimal(INT32_MIN, 1) << endl;
//}
