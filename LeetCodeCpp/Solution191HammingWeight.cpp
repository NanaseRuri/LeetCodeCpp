#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <limits>
#include <stack>
#include <queue>
#include <unordered_set>
#include "ListNode.h"
#include "TreeNode.h"
#include "Node.h"
#include <set>


using namespace std;

class Solution191HammingWeight
{
public:
	int hammingWeight(uint32_t n) {
		int result = 0;
		while (n > 0)
		{
			result += n & 1;
			n >>= 1;
		}
		return result;
	}

	int hammingWeight1(uint32_t n) {
		int result = 0;
		while (n > 0)
		{
			n &= n - 1;
			result++;
		}
		return result;
	}

	const uint32_t M1 = 0x55555555;
	const uint32_t M2 = 0x33333333;
	const uint32_t M4 = 0x0F0F0F0F;
	const uint32_t M8 = 0x00FF00FF;
	const uint32_t M16 = 0x0000FFFF;
	int hammingWeight2(uint32_t n) {
		n = (n & M1) + ((n >> 1) & M1);
		n = (n & M2) + ((n >> 2) & M2);
		n = (n & M4) + ((n >> 4) & M4);
		n = (n & M8) + ((n >> 8) & M8);
		n = (n & M16) + ((n >> 16) & M16);
		return n;
	}
};
