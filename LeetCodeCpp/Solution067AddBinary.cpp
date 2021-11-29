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

class Solution067AddBinary
{
public:
	string addBinary(string& a, string& b) {
		int aSize = a.size();
		int bSize = b.size();

		string* shorterString = &a;
		string* longerString = &b;
		int shortSize = aSize;
		int longerSize = bSize;

		// 约定 a 是长度较短的数组，方便遍历
		if (aSize > bSize) {
			shorterString = &b;
			longerString = &a;
			shortSize = bSize;
			longerSize = aSize;
		}

		bool needCarry = false;

		auto shortStringBegin = shorterString->rbegin();
		auto shorterStringEnd = shorterString->rend();
		auto longerStringBegin = longerString->rbegin();
		auto longerStringEnd = longerString->rend();

		for (; shortStringBegin != shorterStringEnd; ++shortStringBegin, ++longerStringBegin)
		{
			int carry = needCarry ? 1 : 0;
			*longerStringBegin += carry + *shortStringBegin - '0';

			if (*longerStringBegin >= '2') {
				*longerStringBegin -= 2;
				needCarry = true;
			}
			else {
				needCarry = false;
			}
		}

		for (; longerStringBegin != longerStringEnd; ++longerStringBegin)
		{
			if (needCarry) {
				*longerStringBegin += 1;

				if (*longerStringBegin >= '2') {
					*longerStringBegin -= 2;
					needCarry = true;
				}
				else {
					needCarry = false;
					break;
				}
			}
			else {
				break;
			}
		}

		if (needCarry) {
			longerString->insert(0, 1, '1');
		}

		return *longerString;
	}
};

//int main() {
//	string a = "11";
//	string b = "1";
//
//	Solution067AddBinary solution;
//	solution.addBinary(a, b);
//
//	a = "111";
//	b = "1";
//	solution.addBinary(a, b);
//}