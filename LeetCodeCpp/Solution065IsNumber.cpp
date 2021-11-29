#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <limits>
#include <stack>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution065IsNumber
{
private:
	bool IsNumberAfterLetterE(string& s, int startIndex)
	{
		int sSize = s.size();
		if (sSize == startIndex)
		{
			return false;
		}

		bool findNum = false;
		int notSignIndex = s[startIndex] == '+' || s[startIndex] == '-' ? startIndex + 1 : startIndex;

		for (size_t i = notSignIndex; i < sSize; i++)
		{
			if (s[i] >= '0' && s[i] <= '9') {
				findNum = true;
			}
			else {
				return false;
			}
		}

		return findNum;
	}

public:
	bool isNumber(string& s)
	{
		bool getNum = false;
		bool findPoint = false;

		int sSize = s.size();
		int notSignIndex = s[0] == '+' || s[0] == '-' ? 1 : 0;
		for (int i = notSignIndex; i < sSize; i++)
		{
			if (s[i] == '.')
			{
				if (findPoint)
				{
					return false;
				}
				else
				{
					findPoint = true;
				}
			}
			else if (s[i] >= '0' && s[i] <= '9')
			{
				getNum = true;
			}
			else if (s[i] == 'e' || s[i] == 'E')
			{
				if (getNum)
				{
					return IsNumberAfterLetterE(s, i + 1);
				}
				else
				{
					return false;
				}
			}
			else
			{
				return false;
			}
		}

		return getNum;
	}
};

//int main() {
//	Solution065IsNumber solution;
//	string str = "0";
//	cout << solution.isNumber(str) << endl;
//
//	str = "e";
//	cout << solution.isNumber(str)<<endl;
//
//	str = ".";
//	cout << solution.isNumber(str) << endl;
//
//	str = ".1";
//	cout << solution.isNumber(str) << endl;
//
//	str = "0089";
//	cout << solution.isNumber(str) << endl;
//
//	str = "-0.1";
//	cout << solution.isNumber(str) << endl;
//
//	str = "+3.14";
//	cout << solution.isNumber(str) << endl;
//
//	str = "4.";
//	cout << solution.isNumber(str) << endl;
//
//	str = "-.9";
//	cout << solution.isNumber(str) << endl;
//
//	str = "2e10";
//	cout << solution.isNumber(str) << endl;
//
//	str = "-90E3";
//	cout << solution.isNumber(str) << endl;
//
//	str = "3e+7";
//	cout << solution.isNumber(str) << endl;
//
//	str = "+6e-1";
//	cout << solution.isNumber(str) << endl;
//
//	str = "53.5e93";
//	cout << solution.isNumber(str) << endl;
//
//	str = "-123.456e789";
//	cout << solution.isNumber(str) << endl;
//
//	str = "abc";
//	cout << solution.isNumber(str) << endl;
//
//	str = "1a";
//	cout << solution.isNumber(str) << endl;
//
//	str = "1e";
//	cout << solution.isNumber(str) << endl;
//
//	str = "e3";
//	cout << solution.isNumber(str) << endl;
//
//	str = "99e2.5";
//	cout << solution.isNumber(str) << endl;
//
//	str = "--6";
//	cout << solution.isNumber(str) << endl;
//
//	str = "++3";
//	cout << solution.isNumber(str) << endl;
//
//	str = "95a54e53";
//	cout << solution.isNumber(str) << endl;
//}