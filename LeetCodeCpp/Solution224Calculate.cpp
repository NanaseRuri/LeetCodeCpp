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

class Solution224Calculate
{
public:
	int calculate(string& s) {
		stack<int> nums{ {0} };
		stack<char> ops;
		int n = s.size();
		bool lastIsNum = false;
		for (int i = 0; i < n; i++)
		{
			char c = s[i];
			if (c == ' ') {
				continue;
			}
			if (c == '(') {
				ops.push(c);
			}
			else if (c == ')') {
				while (!ops.empty())
				{
					char op = ops.top();
					if (op != '(') {
						CalculateImpl(nums, ops);
					}
					else {
						ops.pop();
						break;
					}
				}
			}
			else {
				if (isdigit(c)) {
					int currentNum = 0;
					int j = i;
					while (j < n && isdigit(s[j]))
					{
						currentNum = 10 * currentNum + (s[j] - '0');
						j++;
					}
					nums.push(currentNum);
					i = j - 1;
				}
				else {
					if (i > 0 && (s[i - 1] == '(' || s[i - 1] == '+' || s[i - 1] == '-')) {
						nums.push(0);
					}
					while (!ops.empty() && ops.top() != '(')
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
		nums.push(op == '+' ? left + right : left - right);
	}

	int calculate1(string& s) {
		int result = 0;
		stack<int> ops{ {1} };
		int sign = 1;

		int n = s.length();
		int i = 0;
		while (i < n)
		{
			char c = s[i];

			if (c == ' ') {
				i++;
			}
			else if (c == '+') {
				sign = ops.top();
				i++;
			}
			else if (c == '-') {
				sign = -ops.top();
				i++;
			}
			else if (c == '(') {
				ops.push(sign);
				i++;
			}
			else if (c == ')') {
				ops.pop();
				i++;
			}
			else {
				int num = 0;
				while (i < n && isdigit(c))
				{
					num = num * 10 + (c - '0');
					i++;
				}
				result += sign * num;
			}
		}
		return result;
	}
};

//int main() {
//	Solution224Calculate solution;
//	string s1 = "1 + 1";
//	string s2 = "2 - 1 + 2";
//	string s3 = "(1+(4+5+2)-3)+(6+8)";
//	string s4 = "2147483647";
//	solution.calculate(s1);
//	solution.calculate(s2);
//	solution.calculate(s3);
//	solution.calculate(s4);
//}