#include "stdafx.h"

using namespace std;

class MinStack
{
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

	int getMin() {
		return _minValue;
	}
};

//int main() {
//	MinStack minStack;
//	minStack.push(2147483646);
//	minStack.push(2147483646);
//	minStack.push(2147483647);
//	cout<<minStack.top()<<endl;
//	minStack.pop();
//	cout<<minStack.getMin()<<endl;;
//	minStack.pop();
//	cout<<minStack.getMin()<<endl;;
//	minStack.pop();
//	minStack.push(2147483647);
//	cout<<minStack.top()<<endl;
//	cout<<minStack.getMin()<<endl;;
//	minStack.push(-2147483648);
//	cout<<minStack.top()<<endl;
//	cout<<minStack.getMin()<<endl;;
//	minStack.pop();
//	cout<<minStack.getMin()<<endl;;
//}
