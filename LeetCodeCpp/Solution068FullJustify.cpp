#include "stdafx.h"

using namespace std;

class Solution068FullJustify
{
public:
	vector<string> fullJustify(vector<string>& words, int maxWidth) {
		vector<string> result;

		string currentResult;
		// ��ŵ�ǰ����������ʵ�λ�ã����ڵ���֮����Ҫ�пո��������� maxWidth / 2 ������
		int* indexes = new int[maxWidth] {};
		int currentWordsCount = 0;
		int currentRemainingLength = maxWidth;
		int wordsLength = words.size();

		int wordsIndex = 0;

		while (wordsIndex < wordsLength) {
			if (currentRemainingLength == maxWidth || (wordsIndex != wordsLength - 1 && currentRemainingLength > words[wordsIndex].size()) ||
				(wordsIndex == wordsLength - 1 && currentRemainingLength > words[wordsIndex].size())) {
				if (currentWordsCount > 0) {
					currentResult.push_back(' ');
					--currentRemainingLength;
				}
				currentResult += words[wordsIndex];
				indexes[currentWordsCount] = maxWidth - currentRemainingLength;
				currentRemainingLength -= words[wordsIndex].size();
				currentWordsCount++;
				wordsIndex++;
			}
			else {
				// ֻ��һ�����ʻ����һ�е����
				if (currentWordsCount == 1 || wordsIndex == wordsLength) {
					currentResult.insert(currentResult.end(), currentRemainingLength, ' ');
				}
				else {
					// ���ʼ��пո�����
					for (int i = currentWordsCount - 1; i > 0; --i)
					{
						if (currentRemainingLength >= i) {
							string spacing(currentRemainingLength / i, ' ');
							currentRemainingLength -= currentRemainingLength / i;
							currentResult.insert(indexes[i], spacing);
						}
					}
				}

				result.push_back(currentResult);
				currentWordsCount = 0;
				currentRemainingLength = maxWidth;
				currentResult = "";
			}
		}

		// ���һ��Ϊ�����
		if (currentRemainingLength != maxWidth) {
			if (currentRemainingLength > 0) {
				currentResult.insert(currentResult.end(), currentRemainingLength, ' ');
			}

			result.push_back(currentResult);
			currentWordsCount = 0;
			currentRemainingLength = maxWidth;
			currentResult = "";
		}

		return result;
	}
};

//int main() {
//	vector<string> words{ "This", "is", "an", "example", "of", "text", "justification." };
//	vector<string> words1{ "What","must","be","acknowledgment","shall","be" };
//	vector<string> words2{ "Science","is","what","we","understand","well","enough","to","explain",
//		 "to","a","computer.","Art","is","everything","else","we","do" };
//	vector<string> words3{ "ask", "not", "what", "your", "country", "can", "do", "for", "you", "ask", "what", "you", "can", "do", "for", "your", "country" };
//	vector<string> words4{ "Listen","to","many,","speak","to","a","few." };
//	vector<string> words5{ "a" };
//	Solution068FullJustify solution;
//	solution.fullJustify(words, 16);
//	solution.fullJustify(words1, 16);
//	solution.fullJustify(words2, 20);
//	solution.fullJustify(words3, 16);
//	solution.fullJustify(words4, 6);
//	solution.fullJustify(words5, 6);
//}
