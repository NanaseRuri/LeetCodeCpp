#include "stdafx.h"

using namespace std;
class Solution2413SmallestEvenMultiple
{
public:
    int smallestEvenMultiple(int n) {
        if (n & 1) {
            return n << 1;
        }
        else {
            return n;
        }
    }
};
