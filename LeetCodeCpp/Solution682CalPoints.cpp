#include "stdafx.h"

class Solution682CalPoints {
public:
	int calPoints(vector<string>& ops) {
		stack<int> nums;
		for (auto& op : ops)
		{
			if (op == "+") {
				int temp = nums.top();
				nums.pop();
				int plusValue = nums.top() + temp;
				nums.push(temp);
				nums.push(plusValue);
			}
			else if (op == "D") {
				nums.push(nums.top() * 2);
			}
			else if (op == "C") {
				nums.pop();
			}
			else {
				nums.push(stoi(op));
			}
		}

		int result = 0;
		while (!nums.empty()) {
			result += nums.top();
			nums.pop();
		}

		return result;
	}
};


//int main() {
//	Solution682CalPoints solution;
//	vector<string> ops1{ "5","-2","4","C","D","9","+","+" };
//	solution.calPoints(ops1);
//}
