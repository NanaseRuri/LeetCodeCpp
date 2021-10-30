#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <limits>
#include <stack>

using namespace std;

class Solution020IsValid {
private:
	int _map[256]{};
public:
	Solution020IsValid() {
		_map['('] = ')';
		_map['{'] = '}';
		_map['['] = ']';
	}

	bool isValid(string s) {
		stack<char> stack;

		int strLength = s.size();
		for (size_t i = 0; i < strLength; i++)
		{
			if (_map[s[i]] != 0) {
				stack.push(s[i]);
			}
			else {
				if (stack.size() == 0) {
					return false;
				}
				else {
					if (s[i] != _map[stack.top()]) {
						return false;
					}
					stack.pop();
				}
			}
		}
		return stack.size() == 0;
	}
};

int main() {
	Solution020IsValid solution;
	cout << solution.isValid("()") << endl;
	cout << solution.isValid("()[]{}") << endl;
	cout << solution.isValid("(]") << endl;
	cout << solution.isValid("([)]") << endl;
	cout << solution.isValid("{[]}") << endl;
}