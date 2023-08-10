#include "stdafx.h"

using namespace std;

class Solution060GetPermutation {
private:
	bool _getResult;
	string _result;
	int _currentCount;

	void Iteration(bool* currentArrayUsed, int maxNumCount, int targetIndex, int* currentResult, int addNumCount) {
		if (addNumCount == maxNumCount) {
			_currentCount++;
			if (_currentCount == targetIndex) {
				_getResult = true;
				for (int i = 0; i < maxNumCount; i++)
				{
					_result.push_back(currentResult[i] + '0');
				}
			}
			return;
		}

		for (int i = 0; i < maxNumCount; ++i)
		{
			if (_getResult) {
				return;
			}
			if (!currentArrayUsed[i]) {
				currentArrayUsed[i] = true;
				currentResult[addNumCount] = i + 1;
				++addNumCount;
				Iteration(currentArrayUsed, maxNumCount, targetIndex, currentResult, addNumCount);

				if (_getResult) {
					return;
				}

				currentArrayUsed[i] = false;
				--addNumCount;
			}
		}
	}

public:
	string getPermutation(int n, int k) {
		_getResult = false;
		_result = "";
		_currentCount = 0;

		bool* currentArrayUsed = new bool[n] {};
		int* currentResult = new int[n] {};

		Iteration(currentArrayUsed, n, k, currentResult, 0);

		return _result;
	}

	string getPermutation1(int n, int k) {
		vector<int> permutationOriginArray;
		for (size_t i = 0; i < n; i++)
		{
			permutationOriginArray.push_back(i + 1);
		}

		k = k - 1;
		int currentFactorial = 1;
		for (int i = n - 1; i > 0; i--)
		{
			currentFactorial *= i;
		}

		string result;
		for (int i = n - 1; i > 0; i--)
		{
			int quotient = k / currentFactorial;
			result.push_back(permutationOriginArray[quotient] + '0');
			permutationOriginArray.erase(permutationOriginArray.begin() + quotient);
			k %= currentFactorial;
			currentFactorial /= i;
		}
		result.push_back(permutationOriginArray[0] + '0');
		return result;
	}
};

//int main() {
//	Solution060GetPermutation solution;
//	cout << solution.getPermutation(3, 3) << endl;
//	cout << solution.getPermutation(3, 6) << endl;
//	cout << solution.getPermutation(4, 9) << endl;
//	cout << solution.getPermutation(3, 1) << endl;
//	cout << solution.getPermutation(1, 1) << endl;
//
//
//	cout << solution.getPermutation1(3, 3) << endl;
//	cout << solution.getPermutation1(3, 6) << endl;
//	cout << solution.getPermutation1(4, 9) << endl;
//	cout << solution.getPermutation1(3, 1) << endl;
//	cout << solution.getPermutation1(1, 1) << endl;
//}
