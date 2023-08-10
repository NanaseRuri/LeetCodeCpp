#include "stdafx.h"

using namespace std;

class Solution504ConvertToBase7
{
public:
    string convertToBase7(int num) {
        if (num == 0) {
            return "0";
        }

        string result;
        int absNum = abs(num);
        while (absNum > 0) {
            result.push_back(absNum % 7 + '0');
            absNum /= 7;
        }

        if (num < 0) {
            result.push_back('-');
        }
        reverse(result.begin(), result.end());

        return result;
    }
};

//int main() {
//	Solution509Fib solution;
//	solution.fib1(4);
//}
