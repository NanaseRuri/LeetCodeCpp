#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <limits>
#include <stack>

using namespace std;

class Solution022GenerateParenthesis {
private:
	vector<string> _result;
public:
	Solution022GenerateParenthesis() :_result{} {
	}

	vector<string> generateParenthesis(int n) {
		_result.clear();
		RecursionGenerateString("", n, n);
		return _result;
	}

	void RecursionGenerateString(string s, int left, int right) {
		if (left == 0 && right == 0) {
			_result.push_back(s);
			return;
		}

		if (left < right) {
			RecursionGenerateString(s + ")", left, right - 1);
		}
		if (left > 0) {
			RecursionGenerateString(s + "(", left - 1, right);
		}
	}
};
//
//int main() {
//	Solution021MergeTwoLists solution;
//	auto result = solution.generateParenthesis(3);
//
//	for (int i = 0; i < result.size(); i++) {
//		cout << result[i] << endl;
//	}
//}