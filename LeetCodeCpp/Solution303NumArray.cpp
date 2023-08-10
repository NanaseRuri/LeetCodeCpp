#include "stdafx.h"

class NumArray {
public:
    vector<int> _preSums;

    NumArray(vector<int>& nums) {
        int numsSize = nums.size();
        _preSums.resize(numsSize + 1);
        for (int i = 0; i < numsSize; i++) {
            _preSums[i + 1] = _preSums[i] + nums[i];
        }
    }

    int sumRange(int left, int right) {
        return _preSums[right + 1] - _preSums[left];
    }
};
