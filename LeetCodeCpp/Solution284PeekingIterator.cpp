#include "stdafx.h"

using namespace std;

class Iterator {
	struct Data;
	Data* data;
public:
	Iterator(const vector<int>& nums) {};
	Iterator(const Iterator& iter) {};

	// Returns the next element in the iteration.
	int next();

	// Returns true if the iteration has more elements.
	bool hasNext() const;
};

class PeekingIterator : public Iterator
{
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
		_flag = Iterator::hasNext();
		if (_flag) {
			_nextElement = Iterator::next();
		}
	}

	int peek() {
		return _nextElement;
	}

	int next() {
		int ret = _nextElement;
		_flag = Iterator::hasNext();
		if (_flag) {
			_nextElement = Iterator::next();
		}
		return ret;
	}

	bool hasNext() const {
		return _flag;
	}
private:
	int _nextElement;
	bool _flag;
};
