#include "stdafx.h"

class Solution953IsAlienSorted
{
public:
	bool isAlienSorted(vector<string>& words, string order) {
		int* charIndex = new int[256]{};
		int orderSize = order.size();
		for (int i = 0; i < orderSize; ++i) {
			charIndex[order[i]] = i;
		}

		int wordsSize = words.size();

		for (int i = 1; i < wordsSize; i++)
		{
			if (!JudgeWord1LessThanWord2(charIndex, words[i - 1], words[i])) {
				return false;
			}
		}

		return true;
	}

	bool JudgeWord1LessThanWord2(int* charIndex, string& word1, string& word2) {
		int word1Size = word1.size();
		int word2Size = word2.size();

		for (int i = 0; i < word1Size && i < word2Size; i++)
		{
			if (charIndex[word1[i]] > charIndex[word2[i]]) {
				return false;
			}
			else if (charIndex[word1[i]] < charIndex[word2[i]]) {
				return true;
			}
		}

		return word1Size <= word2Size;
	}
};
