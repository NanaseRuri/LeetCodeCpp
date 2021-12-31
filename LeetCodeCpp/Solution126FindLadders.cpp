#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <limits>
#include <stack>
#include <queue>
#include <unordered_set>
#include "ListNode.h"
#include "TreeNode.h"
#include "Node.h"

using namespace std;

class Solution126FindLadders
{
	//private:
	//	int _minBfsTime = INT32_MAX;
	//
	//	/// <summary>
	//	/// 记录最后能转换成 endWord 的字符串
	//	/// </summary>
	//	vector<string> _lastString;
	//
	//	vector<vector<string>> _ladderResult;
	//	vector<string> _currentLadderResult;
	//	int _wordSize;
	//	string _endWord;
	//
	//	void Bfs(vector<string>& wordList, vector<bool>& wordUsed, string& currentWord, int currentBfsTime) {
	//		if (currentBfsTime + 3 > _minBfsTime) {
	//			return;
	//		}
	//
	//		bool findByLastString = false;
	//		// 判断是否找到
	//		for (auto iter = _lastString.begin(); iter < _lastString.end(); iter++)
	//		{
	//			int differenceCount = 0;
	//			for (int i = 0; i < _wordSize; i++)
	//			{
	//				if ((*iter)[i] != currentWord[i]) {
	//					differenceCount++;
	//				}
	//			}
	//
	//			if (differenceCount == 1) {
	//				_currentLadderResult.push_back(*iter);
	//				_currentLadderResult.push_back(_endWord);
	//				_ladderResult.push_back(vector<string>(_currentLadderResult));
	//				_currentLadderResult.pop_back();
	//				_currentLadderResult.pop_back();
	//
	//				_minBfsTime = currentBfsTime + 3;
	//				findByLastString = true;
	//			}
	//		}
	//		if (findByLastString) {
	//			return;
	//		}
	//
	//		vector<int> currentWordList;
	//		int wordListSize = wordList.size();
	//		for (int i = 0; i < wordListSize; i++)
	//		{
	//			if (!wordUsed[i]) {
	//				int sameCharacterCount = 0;
	//				for (int j = 0; j < _wordSize; j++)
	//				{
	//					if (wordList[i][j] != currentWord[j]) {
	//						sameCharacterCount++;
	//					}
	//				}
	//				if (sameCharacterCount == 1) {
	//					currentWordList.push_back(i);
	//				}
	//			}
	//		}
	//
	//		int currentWordListSize = currentWordList.size();
	//		for (int i = 0; i < currentWordListSize; i++)
	//		{
	//			wordUsed[currentWordList[i]] = true;
	//			_currentLadderResult.push_back(wordList[currentWordList[i]]);
	//			Bfs(wordList, wordUsed, wordList[currentWordList[i]], currentBfsTime + 1);
	//			_currentLadderResult.pop_back();
	//			wordUsed[currentWordList[i]] = false;
	//		}
	//	}
	//
	//public:
	//	vector<vector<string>> findLadders(string& beginWord, string& endWord, vector<string>& wordList) {
	//		_lastString.clear();
	//		_ladderResult.clear();
	//		_currentLadderResult.clear();
	//		_minBfsTime = INT32_MAX;
	//
	//		_wordSize = beginWord.size();
	//		if (_wordSize == 1) {
	//			_ladderResult.push_back({ beginWord,endWord });
	//			return _ladderResult;
	//		}
	//		else {
	//			bool findEndWord = false;
	//			int wordListSize = wordList.size();
	//
	//			int differenceCharcterCount = 0;
	//			for (int i = 0; i < _wordSize; i++)
	//			{
	//				if (beginWord[i] != endWord[i]) {
	//					differenceCharcterCount++;
	//				}
	//			}
	//			if (differenceCharcterCount == 1) {
	//				_ladderResult.push_back({ beginWord,endWord });
	//				return _ladderResult;
	//			}
	//			else {
	//
	//				vector<bool> wordUsed(wordListSize);
	//
	//				for (int i = 0; i < wordListSize; i++)
	//				{
	//					int differenceCharacterCount = 0;
	//					for (int j = 0; j < _wordSize; j++)
	//					{
	//						if (wordList[i][j] != endWord[j]) {
	//							differenceCharacterCount++;
	//						}
	//					}
	//
	//					if (differenceCharacterCount == 0) {
	//						findEndWord = true;
	//					}
	//					else if (differenceCharacterCount == 1) {
	//						_lastString.push_back(wordList[i]);
	//						wordUsed[i] = true;
	//					}
	//				}
	//
	//				if (!findEndWord || _lastString.size() == 0) {
	//					return _ladderResult;
	//				}
	//
	//				_endWord = endWord;
	//				_currentLadderResult.push_back(beginWord);
	//				Bfs(wordList, wordUsed, beginWord, 0);
	//
	//				int ladderResultSize = _ladderResult.size();
	//				stack<int> removedIndexes;
	//				for (int i = 0; i < ladderResultSize; i++)
	//				{
	//					if (_ladderResult[i].size() > _minBfsTime) {
	//						removedIndexes.push(i);
	//					}
	//				}
	//				while (!removedIndexes.empty())
	//				{
	//					int index = removedIndexes.top();
	//					removedIndexes.pop();
	//					_ladderResult.erase(_ladderResult.begin() + index);
	//				}
	//				return _ladderResult;
	//			}
	//		}
	//	}

public:
	vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
		vector<vector<string>> result;

		// 用来判断扩展出的单词是否在 WordList 中，判断 26 次，当 wordList 很大时用来节省时间
		unordered_set<string> dict{ wordList.begin(),wordList.end() };
		// 题意，wordList 找不到 endWord 则没有
		if (dict.find(endWord) == dict.end()) {
			return result;
		}
		dict.erase(beginWord);

		// 单词是第几次扩展得到的
		unordered_map<string, int> steps{ {beginWord,0} };
		// 单词从哪些单词扩展而来
		unordered_map<string, unordered_set<string>> from{ {beginWord,{}} };
		int step = 0;
		bool found = false;
		queue<string> currentWordQueue{ {beginWord} };
		int wordLength = beginWord.length();
		while (!currentWordQueue.empty())
		{
			step++;
			int queueSize = currentWordQueue.size();
			for (int i = 0; i < queueSize; i++)
			{
				string currentWord = currentWordQueue.front();
				string nextWord = currentWord;
				currentWordQueue.pop();
				// 把当前字符串的各个位进行替换，然后在字典里查找是否存在替换后的单词
				for (int j = 0; j < wordLength; j++)
				{
					char originChar = nextWord[j];
					for (char c = 'a'; c <= 'z'; c++)
					{
						nextWord[j] = c;
						// 由于找过，会在 dict 里面被除去，同时被除去后留下最短路径，因此在此判断是否同样大小的路径以判断是否需要插入图
						if (steps[nextWord] == step) {
							from[nextWord].insert(currentWord);
						}
						if (dict.find(nextWord) == dict.end()) {
							continue;
						}
						// 如果被遍历过，肯定更远，因此除去
						dict.erase(nextWord);
						currentWordQueue.push(nextWord);
						// nextWord 通过 currentWord 转换过来
						from[nextWord].insert(currentWord);
						steps[nextWord] = step;
						if (nextWord == endWord) {
							found = true;
						}
					}
					// 遍历完后复原
					nextWord[j] = originChar;
				}
			}
			if (found) {
				break;
			}
		}
		if (found) {
			vector<string> path{ endWord };
			Dfs(result, endWord, from, path);
		}
		return result;
	}

	void Dfs(vector<vector<string>>& result, const string& node, unordered_map<string, unordered_set<string>>& from, vector<string>& path) {
		if (from[node].empty()) {
			result.push_back({ path.rbegin(),path.rend() });
		}

		for (const string& parent : from[node])
		{
			path.push_back(parent);
			Dfs(result, parent, from, path);
			path.pop_back();
		}
	}
};

//int main() {
//	string beginWord1 = "hit";
//	string endWord1 = "cog";
//	vector<string> wordList1{ "hot","dot","dog","lot","log","cog" };
//
//	string beginWord2 = "hot";
//	string endWord2 = "dot";
//	vector<string> wordList2{ "hot","dot","dog" };
//
//	string beginWord3 = "a";
//	string endWord3 = "b";
//	vector<string> wordList3{ "a","b","c" };
//
//	string beginWord4 = "hot";
//	string endWord4 = "dog";
//	vector<string> wordList4{ "hot","cog","dog","tot","hog","hop","pot","dot" };
//
//	string beginWord5 = "hit";
//	string endWord5 = "cog";
//	vector<string> wordList5{ "hot", "cog", "dot", "dog", "hit", "lot", "log" };
//
//	string beginWord6 = "kiss";
//	string endWord6 = "tusk";
//	vector<string> wordList6{ "miss", "dusk", "kiss", "musk", "tusk", "diss", "disk", "sang", "ties", "muss" };
//
//	string beginWord7 = "qa";
//	string endWord7 = "sq";
//	vector<string> wordList7{ "si", "go", "se", "cm", "so", "ph", "mt", "db", "mb", "sb", "kr", "ln", "tm", "le", "av", "sm", "ar", "ci", "ca", "br", "ti", "ba", "to", "ra", "fa", "yo", "ow", "sn", "ya", "cr", "po", "fe", "ho", "ma", "re", "or", "rn", "au", "ur", "rh", "sr", "tc", "lt", "lo", "as", "fr", "nb", "yb", "if", "pb", "ge", "th", "pm", "rb", "sh", "co", "ga", "li", "ha", "hz", "no", "bi", "di", "hi", "qa", "pi", "os", "uh", "wm", "an", "me", "mo", "na", "la", "st", "er", "sc", "ne", "mn", "mi", "am", "ex", "pt", "io", "be", "fm", "ta", "tb", "ni", "mr", "pa", "he", "lr", "sq", "ye" };
//
//	Solution126FindLadders solution;
//	solution.findLadders(beginWord1, endWord1, wordList1);
//	solution.findLadders(beginWord2, endWord2, wordList2);
//	solution.findLadders(beginWord3, endWord3, wordList3);
//	solution.findLadders(beginWord4, endWord4, wordList4);
//	solution.findLadders(beginWord5, endWord5, wordList5);
//	solution.findLadders(beginWord6, endWord6, wordList6);
//	solution.findLadders(beginWord7, endWord7, wordList7);
//}