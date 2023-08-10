#include "stdafx.h"

using namespace std;

class Solution043Multiply {
public:
	string multiply(string num1, string num2) {
		int num1Size = num1.size();
		int num2Size = num2.size();

		int eachPositionSize = num1Size + num2Size;
		int* eachPositionValue = new int[eachPositionSize] {};

		for (int i = 0; i < num1Size; i++)
		{
			for (int j = 0; j < num2Size; j++)
			{
				eachPositionValue[i + j + 1] += (num1[i] - '0') * (num2[j] - '0');
			}
		}

		for (int i = eachPositionSize - 1; i >= 1; i--)
		{
			if (eachPositionValue[i] >= 10) {
				eachPositionValue[i - 1] += eachPositionValue[i] / 10;
				eachPositionValue[i] %= 10;
			}
		}

		int startIndex = 0;

		while (startIndex < eachPositionSize && eachPositionValue[startIndex] == 0)
		{
			startIndex++;
		}

		if (startIndex == eachPositionSize) {
			return "0";
		}
		else {
			string result;
			for (int i = startIndex; i < eachPositionSize; i++)
			{
				result += eachPositionValue[i] + '0';
			}
			return result;
		}
	}
};

//int main() {
//	string num1 = "2";
//	string num2 = "3";
//
//	string num3 = "9133";
//	string num4 = "0";
//
//	Solution043Multiply solution;
//	cout << solution.multiply(num1, num2) << endl;
//	cout << solution.multiply(num3, num4) << endl;
//}
