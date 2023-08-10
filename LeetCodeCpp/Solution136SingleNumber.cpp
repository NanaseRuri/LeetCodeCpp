#include "stdafx.h"

using namespace std;

class Solution136SingleNumber
{
public:
    int singleNumber(vector<int>& nums) {
        int numsSize = nums.size();
        int result = 0;
        for (int i = 0; i < numsSize; i++)
        {
            result ^= nums[i];
        }
        return result;
    }
};
