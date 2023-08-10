#include "stdafx.h"

using namespace std;

class Solution1523CountOdds
{
public:
    int countOdds(int low, int high) {
        return (high - low) / 2 + ((high % 2) || (low % 2));
    }
};
