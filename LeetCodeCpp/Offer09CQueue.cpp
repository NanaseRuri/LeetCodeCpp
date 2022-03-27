#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>

using namespace std;
class CQueue {
public:
    stack<int> _stackBuffer;
    stack<int> _stackImpl;
    CQueue() : _stackBuffer(), _stackImpl() {

    }

    void appendTail(int value) {
        _stackBuffer.push(value);
    }

    int deleteHead() {
        if (_stackImpl.empty()) {
            while (!_stackBuffer.empty()) {
                _stackImpl.push(_stackBuffer.top());
                _stackBuffer.pop();
            }
        }

        if (_stackImpl.empty()) {
            return -1;
        }
        else {
            int result = _stackImpl.top();
            _stackImpl.pop();
            return result;
        }
    }
};