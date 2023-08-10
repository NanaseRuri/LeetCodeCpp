#include "stdafx.h"

using namespace std;

class Solution2038WinnerOfGame
{
public:
	bool winnerOfGame(string colors) {
		int freq[2] = { 0,0 };
		char cur = 'C';
		int count = 0;
		for (char& c : colors)
		{
			if (c != cur) {
				cur = c;
				count = 1;
			}
			else {
				++count;
				if (count >= 3) {
					++freq[cur - 'A'];
				}
			}
		}

		return freq[0] > freq[1];
	}
};
