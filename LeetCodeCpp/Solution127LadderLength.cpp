#include "stdafx.h"

using namespace std;

class Solution127LadderLength
{
public:
	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		unordered_set<string> wordListSet{ wordList.begin(),wordList.end() };
		if (wordListSet.find(endWord) == wordListSet.end()) {
			return 0;
		}

		wordListSet.erase(beginWord);
		int wordLength = beginWord.length();
		int wordListSize = wordList.size();
		int step = 1;
		queue<string> wordQueue{ {beginWord } };
		unordered_map<string, int> steps{ {beginWord,0 } };
		bool found = false;

		while (!wordQueue.empty())
		{
			step++;
			int queueSize = wordQueue.size();
			for (int i = 0; i < queueSize; i++)
			{
				string currentWord = wordQueue.front();
				string wordReplace = currentWord;
				wordQueue.pop();
				for (int j = 0; j < wordLength; j++)
				{
					char replaceChar = wordReplace[j];
					for (char c = 'a'; c <= 'z'; c++)
					{
						wordReplace[j] = c;
						if (wordListSet.find(wordReplace) == wordListSet.end()) {
							continue;
						}
						wordListSet.erase(wordReplace);
						steps[wordReplace] = step;
						wordQueue.push(wordReplace);
						if (wordReplace == endWord) {
							found = true;
						}
					}
					wordReplace[j] = replaceChar;
				}
			}
			if (found) {
				break;
			}
		}

		return steps[endWord];
	}
};

//int main() {
//		string beginWord1 = "hit";
//		string endWord1 = "cog";
//		vector<string> wordList1{ "hot","dot","dog","lot","log","cog" };
//	
//		string beginWord2 = "hot";
//		string endWord2 = "dot";
//		vector<string> wordList2{ "hot","dot","dog" };
//	
//		string beginWord3 = "a";
//		string endWord3 = "b";
//		vector<string> wordList3{ "a","b","c" };
//	
//		string beginWord4 = "hot";
//		string endWord4 = "dog";
//		vector<string> wordList4{ "hot","cog","dog","tot","hog","hop","pot","dot" };
//	
//		string beginWord5 = "hit";
//		string endWord5 = "cog";
//		vector<string> wordList5{ "hot", "cog", "dot", "dog", "hit", "lot", "log" };
//	
//		string beginWord6 = "kiss";
//		string endWord6 = "tusk";
//		vector<string> wordList6{ "miss", "dusk", "kiss", "musk", "tusk", "diss", "disk", "sang", "ties", "muss" };
//	
//		string beginWord7 = "qa";
//		string endWord7 = "sq";
//		vector<string> wordList7{ "si", "go", "se", "cm", "so", "ph", "mt", "db", "mb", "sb", "kr", "ln", "tm", "le", "av", "sm", "ar", "ci", "ca", "br", "ti", "ba", "to", "ra", "fa", "yo", "ow", "sn", "ya", "cr", "po", "fe", "ho", "ma", "re", "or", "rn", "au", "ur", "rh", "sr", "tc", "lt", "lo", "as", "fr", "nb", "yb", "if", "pb", "ge", "th", "pm", "rb", "sh", "co", "ga", "li", "ha", "hz", "no", "bi", "di", "hi", "qa", "pi", "os", "uh", "wm", "an", "me", "mo", "na", "la", "st", "er", "sc", "ne", "mn", "mi", "am", "ex", "pt", "io", "be", "fm", "ta", "tb", "ni", "mr", "pa", "he", "lr", "sq", "ye" };
//	
//		Solution127LadderLength solution;
//		solution.ladderLength(beginWord1, endWord1, wordList1);
//		solution.ladderLength(beginWord2, endWord2, wordList2);
//		solution.ladderLength(beginWord3, endWord3, wordList3);
//		solution.ladderLength(beginWord4, endWord4, wordList4);
//		solution.ladderLength(beginWord5, endWord5, wordList5);
//		solution.ladderLength(beginWord6, endWord6, wordList6);
//		solution.ladderLength(beginWord7, endWord7, wordList7);
//}
