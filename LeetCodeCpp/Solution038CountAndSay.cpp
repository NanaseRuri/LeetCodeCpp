#include "stdafx.h"

using namespace std;

class Solution038CountAndSay {
private:
	string Iteration(string input) {
		int inputSize = input.size();

		string result;
		char lastChar = ' ';
		int sameCount = 1;
		for (int i = 0; i < inputSize; i++)
		{
			if (input[i] != lastChar) {
				if (lastChar != ' ') {
					result.push_back(sameCount + '0');
					result.push_back(lastChar);
				}
				lastChar = input[i];
				sameCount = 1;
			}
			else {
				sameCount++;
			}
		}
		result.push_back(sameCount + '0');
		result.push_back(lastChar);
		return result;
	}
public:
	string countAndSay(int n) {
		string lastResult = "1";
		for (int i = 1; i < n; i++)
		{
			lastResult = Iteration(lastResult);
		}

		return lastResult;
	}
};

//int main() {
//	Solution038CountAndSay solution;
//
//	cout << solution.countAndSay(1) << endl;
//	cout << solution.countAndSay(2) << endl;
//	cout << solution.countAndSay(3) << endl;
//	cout << solution.countAndSay(4) << endl;
//	cout << solution.countAndSay(5) << endl;
//}
