#include "stdafx.h"

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

		// Լ�� a �ǳ��Ƚ϶̵����飬�������
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

	string addBinary1(string a, string b) {
		string result;
		int carry = 0;
		for (int i = a.length() - 1, j = b.length() - 1; i >= 0 || j >= 0; i--, j--) {
			int currentSum = carry;
			currentSum += i >= 0 ? a[i] - '0' : 0;
			currentSum += j >= 0 ? b[j] - '0' : 0;
			result += (currentSum % 2) + '0';
			carry = currentSum / 2;
		}

		if (carry > 0) {
			result += '1';
		}
		reverse(result.begin(), result.end());
		return result;
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
