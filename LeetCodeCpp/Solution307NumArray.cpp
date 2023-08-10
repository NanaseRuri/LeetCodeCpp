#include "stdafx.h"

class NumArray {
private:
	vector<int> _segmentTree;
	int _currentSize;

	void Build(int node, int left, int right, vector<int>& nums) {
		if (left == right) {
			_segmentTree[node] = nums[left];
			return;
		}
		int middle = (left + right) / 2;
		Build(node * 2 + 1, left, middle, nums);
		Build(node * 2 + 2, middle + 1, right, nums);
		_segmentTree[node] = _segmentTree[node * 2 + 1] + _segmentTree[node * 2 + 2];
	}

	void Change(int index, int value, int node, int left, int right) {
		if (left == right) {
			_segmentTree[node] = value;
			return;
		}
		int middle = (left + right) / 2;
		if (index <= middle) {
			Change(index, value, node * 2 + 1, left, middle);
		}
		else {
			Change(index, value, node * 2 + 2, middle + 1, right);
		}
		_segmentTree[node] = _segmentTree[node * 2 + 1] + _segmentTree[node * 2 + 2];
	}

	int Range(int left, int right, int node, int s, int e) {
		if (left == s && right == e) {
			return _segmentTree[node];
		}
		int middle = (s + e) / 2;
		if (right <= middle) {
			return Range(left, right, node * 2 + 1, s, middle);
		}
		else if (left > middle) {
			return Range(left, right, node * 2 + 2, middle + 1, e);
		}
		else {
			return Range(left, middle, node * 2 + 1, s, middle) + Range(middle + 1, right, node * 2 + 2, middle + 1, e);
		}
	}
public:
	NumArray(vector<int>& nums) :_currentSize(nums.size()), _segmentTree(nums.size() * 4) {
		Build(0, 0, _currentSize - 1, nums);
	}

	void update(int index, int val) {
		Change(index, val, 0, 0, _currentSize - 1);
	}

	int sumRange(int left, int right) {
		return Range(left, right, 0, 0, _currentSize - 1);
	}
};

//int main() {
//	vector<int> nums{ 1,3,5,7 };
//	
//	vector<int> nums1{ -28, -39, 53, 65, 11, -56, -65, -39, -43, 97 };
//
//	NumArray numberArray(nums);
//	numberArray.sumRange(0, 2);
//	numberArray.update(1, 2);
//	numberArray.sumRange(1, 2);
//	numberArray.sumRange(0, 2);
//
//	NumArray numberArray1(nums1);
//	numberArray.sumRange(5, 6);
//	numberArray.update(9, 27);
//	numberArray.sumRange(2, 3);
//	numberArray.sumRange(6, 7);
//	numberArray.update(1, -82);
//	numberArray.update(3, -72);
//	numberArray.sumRange(3, 7);
//	numberArray.sumRange(1, 8);
//	numberArray.update(5, 13);
//	numberArray.update(4, -67);
//}
