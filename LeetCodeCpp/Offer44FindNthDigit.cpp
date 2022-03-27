#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include "Node.h"

using namespace std;
class Offer44FindNthDigit {
public:
    int missingNumber(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int middle = (left + right) / 2;
            if (nums[middle] == middle) {
                left = middle + 1;
            }
            else {
                right = middle - 1;
            }
        }

        return left;
    }
};