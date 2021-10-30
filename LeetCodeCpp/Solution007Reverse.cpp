#include <limits>

class Solution007Reverse {
public:
	int reverse(int x) {
		int result = 0;
		int bitsCount = 0;
		while (x != 0) {
			if (bitsCount == 9 && (result < INT_MIN / 10 || result > INT_MAX / 10))
			{
				return 0;
			}
			if (bitsCount == 9 && (result == INT_MIN / 10 || result == INT_MAX / 10)) {
				if (x > 7) {
					return 0;
				}
			}
			int digit = x % 10;
			x /= 10;
			result = result * 10 + digit;
			bitsCount++;
		}
		return result;
	}
};

//int main() {
//	Solution007Reverse reverse;
//	reverse.reverse(1534236469);
//}