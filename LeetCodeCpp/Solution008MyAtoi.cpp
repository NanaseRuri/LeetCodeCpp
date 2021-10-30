#include <string>
#include <limits>
#include <iostream>

using namespace std;
class Solution008MyAtoi {
public:
	int myAtoi(string s) {
		int strLength = s.length();
		int result = 0;
		int i = 0;
		while (s[i] == ' ' && i < strLength) {
			i++;
		}

		if (i == strLength) {
			return  0;
		}
		int positive;
		if (s[i] == '-') {
			positive = -1;
			i++;
		}
		else if (s[i] == '+') {
			positive = 1;
			i++;
		}
		else {
			positive = 1;
		}

		while (i < strLength)
		{
			if (s[i] == '0') {
				i++;
			}
			else {
				break;
			}
		}

		int bitsCount = 0;
		int minLimit = INT_MIN / 10;
		int maxLimit = INT_MAX / 10;

		while (s[i] >= '0' && s[i] <= '9')
		{
			if (bitsCount == 10) {
				return positive == 1 ? INT_MAX : INT_MIN;
			}
			if (bitsCount == 9 && (result < minLimit || result > maxLimit))
			{
				return positive == 1 ? INT_MAX : INT_MIN;
			}
			if (bitsCount == 9 && (result == minLimit || result == maxLimit)) {
				if (positive == 1) {
					if (s[i] >= '7' && s[i] <= '9') {
						return INT_MAX;
					}
				}
				else {
					if (s[i] >= '8' && s[i] <= '9') {
						return INT_MIN;
					}
				}
			}

			result *= 10;
			result += (s[i] - '0') * positive;
			bitsCount++;
			i++;
		}

		return result;
	}
};

//int main() {
//	Solution008MyAtoi atoi;
//	cout << atoi.myAtoi("2147483646") << endl;
//	cout << atoi.myAtoi("21474836460") << endl;
//}