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

class MyQueue {
public:
	stack<int> _stackIndeed;
	stack<int> _stackTool;

	MyQueue() {
	}

	void push(int x) {
		while (!_stackIndeed.empty())
		{
			_stackTool.push(_stackIndeed.top());
			_stackIndeed.pop();
		}

		_stackIndeed.push(x);
		while (!_stackTool.empty()) {
			_stackIndeed.push(_stackTool.top());
			_stackTool.pop();
		}
	}

	int pop() {
		int result = _stackIndeed.top();
		_stackIndeed.pop();
		return result;
	}

	int peek() {
		return _stackIndeed.top();
	}

	bool empty() {
		return _stackIndeed.empty();
	}
};

class MyQueue1 {
public:
	stack<int> _stackIndeed;
	stack<int> _stackTool;

	MyQueue1() {
	}

	void push(int x) {
		_stackTool.push(x);
	}

	int pop() {
		if (_stackIndeed.empty()) {
			while (!_stackTool.empty())
			{
				_stackIndeed.push(_stackTool.top());
				_stackTool.pop();
			}
		}

		int result = _stackIndeed.top();
		_stackIndeed.pop();
		return result;
	}

	int peek() {
		if (_stackIndeed.empty()) {
			while (!_stackTool.empty())
			{
				_stackIndeed.push(_stackTool.top());
				_stackTool.pop();
			}
		}
		return _stackIndeed.top();
	}

	bool empty() {
		return _stackIndeed.empty() && _stackTool.empty();
	}
};