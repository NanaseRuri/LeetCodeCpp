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

class Solution190ReverseBits
{
public:
	uint32_t reverseBits(uint32_t n) {
		uint32_t result = 0;
		if (n == 0) {
			return result;
		}

		for (int i = 0; i < 32; ++i) {
			result |= (n & 1) << (31 - i);
			n >>= 1;
		}
		return result;
	}

	const uint32_t M1 = 0x55555555;
	const uint32_t M2 = 0x33333333;
	const uint32_t M4 = 0x0F0F0F0F;
	const uint32_t M8 = 0x00FF00FF;
	uint32_t reverseBits1(uint32_t n) {
		n = ((n >> 1) & M1) | ((n & M1) << 1);
		n = ((n >> 2) & M2) | ((n & M2) << 2);
		n = ((n >> 4) & M4) | ((n & M4) << 4);
		n = ((n >> 8) & M8) | ((n & M8) << 8);
		return n >> 16 | n << 16;
	}
};

//int main() {
//	Solution190ReverseBits solution;
//	solution.reverseBits(964176192);
//	solution.reverseBits(3221225471);
//}