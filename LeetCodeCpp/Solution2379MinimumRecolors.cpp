#include "stdafx.h"

using namespace std;
class Solution2379MinimumRecolors
{
public:
	int minimumRecolors(string blocks, int k) {
		int result = 0;

		for (int i = 0; i < k; i++) {
			if (blocks[i] == 'W') {
				result++;
			}
		}

		int currentResult = result;

		for (int i = k; i < blocks.size(); i++) {
			currentResult -= blocks[i - k] == 'W';
			currentResult += blocks[i] == 'W';
			result = min(currentResult, result);
		}
		return result;
	}
};
