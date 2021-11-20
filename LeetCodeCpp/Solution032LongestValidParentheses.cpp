#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <limits>
#include <stack>

using namespace std;

class Solution032LongestValidParentheses {
public:

	/// <summary>
	/// 方法 1 ：两轮遍历，O(n)，O(1)
	/// </summary>
	/// <param name="s"></param>
	/// <returns></returns>
	int longestValidParentheses1(string s) {
		int strSize = s.size();
		if (strSize < 2) {
			return 0;
		}

		int leftParenthesisCount = 0;
		int rightParenthesisCount = 0;
		int maxParenthesesLength = 0;
		for (int i = 0; i < strSize; i++)
		{
			if (s[i] == '(') {
				leftParenthesisCount++;
			}
			else {
				rightParenthesisCount++;
			}

			if (leftParenthesisCount == rightParenthesisCount) {
				if (maxParenthesesLength < leftParenthesisCount * 2) {
					maxParenthesesLength = leftParenthesisCount * 2;
				}
			}
			else if (rightParenthesisCount > leftParenthesisCount) {
				rightParenthesisCount = 0;
				leftParenthesisCount = 0;
			}
		}

		leftParenthesisCount = 0;
		rightParenthesisCount = 0;
		for (int i = strSize - 1; i > 0; i--)
		{
			if (s[i] == '(') {
				leftParenthesisCount++;
			}
			else {
				rightParenthesisCount++;
			}

			if (leftParenthesisCount == rightParenthesisCount) {
				if (maxParenthesesLength < leftParenthesisCount * 2) {
					maxParenthesesLength = leftParenthesisCount * 2;
				}
			}
			else if (leftParenthesisCount > rightParenthesisCount) {
				rightParenthesisCount = 0;
				leftParenthesisCount = 0;
			}
		}

		return maxParenthesesLength;
	}

	/// <summary>
	/// 使用栈，O(n)，O(n)
	/// </summary>
	/// <param name="s"></param>
	/// <returns></returns>
	int longestValidParentheses2(string s) {
		int strSize = s.size();
		if (strSize < 2) {
			return 0;
		}

		stack<int> strStack;
		strStack.push(-1);
		int maxSize = 0;
		for (int i = 0; i < strSize; i++)
		{
			if (s[i] == '(') {
				strStack.push(i);
			}
			else {
				strStack.pop();
				if (strStack.empty()) {
					strStack.push(i);
				}
				else {
					maxSize = max(maxSize, i - strStack.top());
				}
			}
		}
		return maxSize;
	}

	/// <summary>
	/// 使用动态规划，O(n)，O(n)
	/// </summary>
	/// <param name="s"></param>
	/// <returns></returns>
	int longestValidParentheses(string s) {
		int strSize = s.size();
		if (strSize < 2) {
			return 0;
		}

		int* dp = new int[strSize] {0};
		int preParenthesesIndex;
		int leftParenthesisIndex;
		int currentValue;
		for (int i = 1; i < strSize; i++)
		{
			if (s[i] == ')') {
				leftParenthesisIndex = i - dp[i - 1] - 1;
				if (leftParenthesisIndex >= 0 && s[leftParenthesisIndex] == '(') {
					currentValue = 2 + dp[i - 1];
					preParenthesesIndex = leftParenthesisIndex - 1;
					if (preParenthesesIndex >= 0) {
						currentValue += dp[preParenthesesIndex];
					}
					dp[i] = currentValue;
				}
			}
		}

		int maxParenthesesLength = 0;
		for (int i = 1; i < strSize; i++)
		{
			maxParenthesesLength = max(maxParenthesesLength, dp[i]);
		}
		return maxParenthesesLength;
	}
};

//int main() {
//	Solution032LongestValidParentheses solution;
//	cout << solution.longestValidParentheses("(()") << endl;
//	cout << solution.longestValidParentheses(")()())") << endl;
//	cout << solution.longestValidParentheses("") << endl;
//	cout << solution.longestValidParentheses(")))(((") << endl;
//	cout << solution.longestValidParentheses(")))((())()()())") << endl;
//	cout << solution.longestValidParentheses("()(()") << endl;
//	cout << solution.longestValidParentheses("())()") << endl;
//	cout << solution.longestValidParentheses(")())(") << endl;
//}