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

using namespace std;

class Solution227Calculate
{
private:
	unordered_map<char, int> _opLevelMap{
		{'+',1},
		{'-',1},
		{'*',2},
		{'/',2}
	};
public:
	int calculate(string& s) {
		stack<char> ops;
		stack<int> nums{ {0} };

		int sLength = s.length();

		for (int i = 0; i < sLength; i++)
		{
			char c = s[i];
			if (c == ' ') {
				continue;
			}
			if (isdigit(c)) {
				int j = i;
				int num = 0;
				while (j < sLength && isdigit(s[j]))
				{
					num = 10 * num + (s[j] - '0');
					j++;
				}
				nums.push(num);
				i = j - 1;
			}
			else {
				if (c == '(')
				{
					ops.push(c);
				}
				else if (c == ')') {
					while (!ops.empty())
					{
						char currentOp = ops.top();
						if (currentOp == '(') {
							ops.pop();
							break;
						}
						CalculateImpl(nums, ops);
					}
				}
				else {
					if (i > 0 && (s[i - 1] == '(' || s[i - 1] == '+' || s[i - 1] == '-')) {
						nums.push(0);
					}
					while (!ops.empty() && ops.top() != '(' && _opLevelMap[ops.top()] >= _opLevelMap[c])
					{
						CalculateImpl(nums, ops);
					}
					ops.push(c);
				}
			}
		}

		while (!ops.empty())
		{
			CalculateImpl(nums, ops);
		}

		return nums.top();
	}

	void CalculateImpl(stack<int>& nums, stack<char>& ops) {
		int right = nums.top();
		nums.pop();
		int left = nums.top();
		nums.pop();

		char op = ops.top();
		ops.pop();

		if (op == '+') {
			nums.push(left + right);
		}
		else if (op == '-') {
			nums.push(left - right);
		}
		else if (op == '*') {
			nums.push(left * right);
		}
		else if (op == '/') {
			nums.push(left / right);
		}
	}
};

//int main() {
//	Solution227Calculate solution;
//	string s1 = "1 + 1";
//	string s2 = "2 - 1 + 2";
//	string s3 = "(1+(4+5+2)-3)+(6+8)";
//	string s4 = "2147483647";
//	string s5 = "3+2*2";
//	string s6 = "(3+2)*2";
//	string s7 = "(3+2*2)*2";
//	string s8 = "(3*2+2)*2";
//	solution.calculate(s1);
//	solution.calculate(s2);
//	solution.calculate(s3);
//	solution.calculate(s4);
//	solution.calculate(s5);
//	solution.calculate(s6);
//	solution.calculate(s7);
//	solution.calculate(s8);
//}