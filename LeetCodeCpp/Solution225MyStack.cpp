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

class MyStack {
public:
    queue<int> _toolQueue;
    queue<int> _queueIndeed;

    MyStack() {
    }

    void push(int x) {
        _toolQueue.push(x);
        while (!_queueIndeed.empty())
        {
            _toolQueue.push(_queueIndeed.front());
            _queueIndeed.pop();
        }
        swap(_toolQueue, _queueIndeed);
    }

    int pop() {
        int result = _queueIndeed.front();
        _queueIndeed.pop();
        return result;
    }

    int top() {
        return _queueIndeed.front();
    }

    bool empty() {
        return _queueIndeed.empty();
    }
};

class MyStack1 {
public:
    queue<int> _queueIndeed;

    MyStack1() {
    }

    void push(int x) {
        int currentSize = _queueIndeed.size();
        _queueIndeed.push(x);
        for (int i = 0; i < currentSize; i++)
        {
            _queueIndeed.push(_queueIndeed.front());
            _queueIndeed.pop();
        }
    }

    int pop() {
        int result = _queueIndeed.front();
        _queueIndeed.pop();
        return result;
    }

    int top() {
        return _queueIndeed.front();
    }

    bool empty() {
        return _queueIndeed.empty();
    }
};
