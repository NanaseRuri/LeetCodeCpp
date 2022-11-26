#include "stdafx.h"

class Solution754ReachNumber {
public:
    int reachNumber(int target) {
        if (target == 0) {
            return 0;
        }

        target = abs(target);
        int step = 0;
        while (target != 0) {
            step++;
            if (target >= step) {
                target -= step;
            }
            else {
                target += step;
            }
        }

        return step;
    }
};