#include "stdafx.h"

using namespace std;

class CTCI0502PrintBin {
public:
	string printBin(double num) {
		if (num == 0 || num == 1) {
			return to_string(num);
		}

		string result = "0.";
		for (int i = 0; i < 32; i++, num *= 2) {
			int digit = num;
			result += digit + '0';
			num -= digit;

			if (num == 0) {
				return result;
			}
		}

		return "ERROR";
	}
};

//int main() {
//	CTCI0502PrintBin solution;
//	solution.printBin(0.1);
//}
