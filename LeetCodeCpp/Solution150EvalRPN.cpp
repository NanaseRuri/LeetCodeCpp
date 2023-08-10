#include "stdafx.h"

using namespace std;

class Solution150EvalRPN
{
public:
	int evalRPN(vector<string>& tokens) {
		stack<int> nums;

		for (auto token : tokens)
		{
			if (token == "+" || token == "-" || token == "*" || token == "/") {
				int right = nums.top();
				nums.pop();
				int left = nums.top();
				nums.pop();
				if (token == "+") {
					left += right;
				}
				else if (token == "-") {
					left -= right;
				}
				else if (token == "*") {
					left *= right;
				}
				else {
					left /= right;
				}
				nums.push(left);
			}
			else {
				nums.push(Atoi(token));
			}
		}

		return nums.top();
	}

	int Atoi(string& s) {
		int num = 0;
		int positive;

		int startIndex = 0;
		if (s[startIndex] == '+') {
			positive = 1;
			startIndex++;
		}
		else if (s[startIndex] == '-') {
			positive = -1;
			startIndex++;
		}
		else {
			positive = 1;
		}

		int sLength = s.length();
		while (startIndex < sLength)
		{
			num *= 10;
			num += s[startIndex] - '0';
			startIndex++;
		}
		return num * positive;
	}
};

//int main() {
//	vector<string> tokens1{ "2","1","+","3","*" };
//	vector<string> tokens2{ "4","13","5","/","+" };
//	vector<string> tokens3{ "10","6","9","3","+","-11","*","/","*","17","+","5","+" };
//
//	Solution150EvalRPN solution;
//	cout << solution.evalRPN(tokens1) << endl;
//	cout << solution.evalRPN(tokens2) << endl;
//	cout << solution.evalRPN(tokens3) << endl;
//}
