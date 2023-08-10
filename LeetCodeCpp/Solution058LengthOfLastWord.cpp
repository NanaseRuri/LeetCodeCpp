#include "stdafx.h"

using namespace std;

class Solution058LengthOfLastWord {
public:
	int lengthOfLastWord(string s) {
		int lastWordLength = 0;
		int currentLength = 0;
		int sSize = s.size();
		for (int i = 0; i < sSize; i++)
		{
			if (s[i] == ' ') {
				if (currentLength > 0)
				{
					lastWordLength = currentLength;
					currentLength = 0;
				}
			}
			else {
				currentLength++;
			}
		}
		if (currentLength > 0) {
			lastWordLength = lastWordLength;
		}
		return lastWordLength;
	}
};

//int main() {
//	Solution058LengthOfLastWord solution;
//	solution.lengthOfLastWord("Today is a nice day");
//}
