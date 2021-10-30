#include <string>
#include <map>
#include <vector>

using namespace std;

const vector<pair<int, string>> valueSymbols = {
{1000, "M"},
{900,  "CM"},
{500,  "D"},
{400,  "CD"},
{100,  "C"},
{90,   "XC"},
{50,   "L"},
{40,   "XL"},
{10,   "X"},
{9,    "IX"},
{5,    "V"},
{4,    "IV"},
{1,    "I"},
};

class Solution012IntToRoman {
public:
	string intToRoman(int num) {
		string result;
		int valueSysbolsLength = valueSymbols.size();
		for (int i = 0; i < valueSysbolsLength; i++)
		{
			int key = valueSymbols[i].first;
			string charValue = valueSymbols[i].second;
			while (num >= key) {
				num -= key;
				result += charValue;
			}
		}

		return result;
	}
};