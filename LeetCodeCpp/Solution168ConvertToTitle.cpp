#include "stdafx.h"

using namespace std;
class Solution168ConvertToTitle {
public:
	string convertToTitle(int columnNumber) {
		string result;
		while (columnNumber != 0)
		{
			--columnNumber;
			result += columnNumber % 26 + 'A';
			columnNumber /= 26;
		}
		reverse(result.begin(), result.end());
		return result;
	}
};
//
//int main() {
//	Solution168ConvertToTitle solution;
//	solution.convertToTitle(701);
//	solution.convertToTitle(28);
//}
