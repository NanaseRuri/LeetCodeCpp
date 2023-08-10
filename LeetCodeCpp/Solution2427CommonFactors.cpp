#include "stdafx.h"

using namespace std;
class Solution2427CommonFactors
{
public:
    int commonFactors(int a, int b) {
        int result = 1;
        for (int i = 2; i <= gcd(a, b); i++) {
            if (a % i == 0 && b % i == 0) {
                result++;
            }
        }
        return result;
    }
};
