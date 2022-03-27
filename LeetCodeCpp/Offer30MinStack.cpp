#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>

using namespace std;
class MinStack {
public:
	stack<long long> _minStackImpl;
	long long _minValue = INT32_MAX;

	MinStack() {
	}

	void push(int val) {
		if (_minStackImpl.empty()) {
			_minStackImpl.push(0);
			_minValue = val;
		}
		else {
			long long difference = val - _minValue;
			_minStackImpl.push(difference);
			if (difference < 0) {
				_minValue = val;
			}
		}
	}

	void pop() {
		long long difference = _minStackImpl.top();
		if (difference < 0) {
			_minValue -= difference;
		}
		_minStackImpl.pop();
	}

	int top() {
		if (_minStackImpl.top() < 0) {
			return _minValue;
		}
		else {
			return _minStackImpl.top() + _minValue;
		}
	}

	int min() {
		return _minValue;
	}
};