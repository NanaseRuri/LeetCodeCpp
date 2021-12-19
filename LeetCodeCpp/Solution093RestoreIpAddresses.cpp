#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <limits>
#include <stack>
#include <queue>
#include <unordered_set>
#include "ListNode.h"

using namespace std;

class Solution093RestoreIpAddresses
{
private:
	vector<string> _result;
	string _currentResult;

	void Iteration(string& s, int sSize, int startIndex, int currentSegment) {
		if (currentSegment == 4) {
			_result.push_back(_currentResult);
		}

		// 最短可以多短
		int currentLength = sSize - startIndex - 3 * (3 - currentSegment);
		// 最长可以多长
		int maxLength = sSize - startIndex - 3 + currentSegment;
		// 不能比 1 短
		currentLength = max(currentLength, 1);
		// 不能比 3 长
		maxLength = min(maxLength, 3);
		while (currentLength <= maxLength)
		{
			// 排除前置 0
			if (currentLength > 1 && s[startIndex] == '0') {
				return;
			}

			int result = 0;
			for (int i = 0; i < currentLength; i++)
			{
				result = 10 * result + (s[startIndex + i] - '0');
			}
			if (result > 255) {
				return;
			}

			_currentResult += s.substr(startIndex, currentLength);
			if (currentSegment != 3) {
				_currentResult.push_back('.');
			}

			Iteration(s, sSize, startIndex + currentLength, currentSegment + 1);

			if (currentSegment != 3) {
				_currentResult.pop_back();
			}
			_currentResult.erase(_currentResult.end() - currentLength, _currentResult.end());

			currentLength++;
		}
	}

public:
	vector<string> restoreIpAddresses(string s) {
		_result.clear();
		int sSize = s.size();
		// 除去没用的情况
		if (sSize > 12 || sSize < 4) {
			return _result;
		}

		Iteration(s, s.size(), 0, 0);

		return _result;
	}
};

//int main() {
//	string str1 = "25525511135";
//	string str2 = "0000";
//	string str3 = "1111";
//	string str4 = "010010";
//	Solution093RestoreIpAddresses solution;
//	solution.restoreIpAddresses(str1);
//	solution.restoreIpAddresses(str2);
//	solution.restoreIpAddresses(str3);
//	solution.restoreIpAddresses(str4);
//}