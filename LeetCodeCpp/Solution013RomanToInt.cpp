#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

unordered_map<char, int> valueSymbols = {
{ 'M' ,1000},
{ 'D',500} ,
{ 'C',100 },
{ 'L',50  },
{ 'X',10} ,
{ 'V',5 },
{ 'I',1 }
};

class Solution013RomanToInt {
public:
	int romanToInt(string s) {
		int strLength = s.size();
		int result = 0;
		for (int i = 0; i < strLength; i++)
		{
			if (i + 1 < strLength) {
				int left = valueSymbols[s[i]];
				int right = valueSymbols[s[i + 1]];
				if (left < right) {
					result -= left;
				}
				else {
					result += left;
				}
			}
			else {
				result += valueSymbols[s[i]];
			}
		}
		return result;
	}
};