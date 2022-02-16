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
#include "TreeNode.h"
#include "Node.h"
#include <set>
#include <numeric>
#include <functional>

using namespace std;

class Solution282AddOperators
{
private:
	int _numSize;
	int _target;
	vector<string> _result;
	void Dfs(string& num, string& currentString, int index, long long currentSum, long long lastNum) {
		if (index == _numSize) {
			if (currentSum == _target) {
				_result.push_back(currentString);
			}
			return;
		}

		// 当前的字符串长度即为后续加入符号位的下标
		int operatorIndex = currentString.size();

		// 放入临时位，作为符号位后续更改
		if (index > 0) {
			currentString.push_back(0);
		}

		long long currentNum = 0;
		// 避免前置 0
		for (int j = index; j < _numSize && (j == index || num[index] != '0'); j++)
		{
			currentNum = currentNum * 10 + (num[j] - '0');
			currentString.push_back(num[j]);
			// 当第一层时，不会往符号位即第 0 位放入符号，后续层才会开始
			if (index == 0) {
				Dfs(num, currentString, j + 1, currentNum, currentNum);
			}
			else {
				currentString[operatorIndex] = '+';
				// 最后的值为 currentNum
				Dfs(num, currentString, j + 1, currentSum + currentNum, currentNum);
				currentString[operatorIndex] = '-';
				// 最后的值为 -currentNum
				Dfs(num, currentString, j + 1, currentSum - currentNum, -currentNum);
				currentString[operatorIndex] = '*';
				// 最后的值为 lastNum * currentNum
				Dfs(num, currentString, j + 1, currentSum - lastNum + lastNum * currentNum, lastNum * currentNum);
			}
		}

		currentString.resize(operatorIndex);
	}

public:
	vector<string> addOperators(string num, int target) {
		_result.clear();
		_numSize = num.length();
		_target = target;

		string expr;
		Dfs(num, expr, 0, 0, 0);
		return _result;
	}
};

//int main() {
//	Solution282AddOperators solution;
//	solution.addOperators("123", 6);
//	solution.addOperators("232", 8);
//	solution.addOperators("1015", 25);
//	solution.addOperators("00", 0);
//	solution.addOperators("3456237490", 9191);
//}