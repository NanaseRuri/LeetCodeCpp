#include <string>
#include <iostream>

using namespace std;
class Solution006Convert {
public:
	string convert(string s, int numRows) {
		if (numRows == 1) {
			return s;
		}
		else {
			string result;
			int strLength = s.length();

			int totalGap = 2 * (numRows - 1);
			int gap;
			int j;

			for (int i = 0; i < numRows; i++)
			{
				j = i;
				if (j == 0 || j == numRows - 1) {
					while (j < strLength) {
						result += s[j];
						j += totalGap;
					}
				}
				else {
					gap = 2 * i;
					while (j < strLength) {
						result += s[j];
						gap = totalGap - gap;
						j += gap;
					}
				}
			}

			return result;
		}
	}
};

//int main() {
//	Solution006Convert solution;
//	cout << solution.convert("PAYPALISHIRING", 3) << endl;
//	cout << solution.convert("PAYPALISHIRING", 4) << endl;
//	cout << solution.convert("A", 1) << endl;
//}