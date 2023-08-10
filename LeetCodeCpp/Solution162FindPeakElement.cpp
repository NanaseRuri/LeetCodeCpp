#include "stdafx.h"

using namespace std;
class Solution162FindPeakElement {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        int middle;
        while (left<right)
        {   
            middle = (left + right) / 2;
            if (nums[middle] > nums[middle + 1]) {
                right = middle;
            }
            else {
                left = middle + 1;
            }
        }
        return left;
    }
};
