#include "stdafx.h"

using namespace std;

class Solution096NumTrees
{
private:
	unordered_map<int, int> _numTreeNumsMap{ {0,1},{1,1} };

public:
	int numTrees(int n) {
		if (_numTreeNumsMap.find(n) != _numTreeNumsMap.end()) {
			return _numTreeNumsMap[n];
		}
		else {
			int sum = 0;
			for (int i = 0; i < n; i++)
			{
				sum += numTrees(i) * numTrees(n - i - 1);
			}
			_numTreeNumsMap.insert({ n,sum });
			return sum;
		}
	}
};

//int main() {
//	Solution096NumTrees solution;
//	solution.numTrees(1);
//	solution.numTrees(2);
//	solution.numTrees(3);
//	solution.numTrees(4);
//}
