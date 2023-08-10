#include "stdafx.h"

using namespace std;
class Solution172TrailingZeroes {
public:
    int trailingZeroes(int n) {
        int result = 0;
        long currentMultiple = 5;
        while (n>= currentMultiple)
        {
            result += (n / currentMultiple);
            currentMultiple *= 5;
        }
        return result;
    }
};
