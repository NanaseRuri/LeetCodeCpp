#include "stdafx.h"

using namespace std;

//class MedianFinder {
//public:
//	priority_queue<int, vector<int>, less<int>> _minQueue;
//	priority_queue<int, vector<int>, greater<int>> _maxQueue;
//
//	MedianFinder() {
//	}
//
//	void addNum(int num) {
//		if (_minQueue.empty() || num <= _minQueue.top()) {
//			_minQueue.push(num);
//			if (_maxQueue.size() + 1 < _minQueue.size()) {
//				_maxQueue.push(_minQueue.top());
//				_minQueue.pop();
//			}
//		}
//		else {
//			_maxQueue.push(num);
//			if (_maxQueue.size() > _minQueue.size()) {
//				_minQueue.push(_maxQueue.top());
//				_maxQueue.pop();
//			}
//		}
//	}
//
//	double findMedian() {
//		if (_minQueue.size() > _maxQueue.size()) {
//			return _minQueue.top();
//		}
//		else {
//			return (_minQueue.top() + _maxQueue.top()) / 2.0;
//		}
//	}
//};

class MedianFinder {
public:
	multiset<int> nums;
	multiset<int>::iterator left;
	multiset<int>::iterator right;

	MedianFinder() :left(nums.end()), right(nums.end()) {
	}

	void addNum(int num) {
		const size_t n = nums.size();
		nums.insert(num);
		if (!n) {
			left = right = nums.begin();
		}
		else if (n & 1) {
			if (num < *left) {
				left--;
			}
			else {
				right++;
			}
		}
		else {
			if (num > *left && num < *right) {
				left++;
				right--;
			}
			else if (num >= *right) {
				left++;
			}
			else {
				right--;
				left = right;
			}
		}
	}

	double findMedian() {
		return (*left + *right) / 2.0;
	}
};

//int main() {
//	MedianFinder finder;
//
//	finder.addNum(1);
//	finder.addNum(2);
//	finder.findMedian();
//	finder.addNum(3);
//	finder.findMedian();
//}
