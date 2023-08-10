#include "stdafx.h"

using namespace std;

class WordDictionary
{
private:
	vector<WordDictionary*> _nextDics;
	bool _isEnd;

public:
	WordDictionary() :_nextDics(26), _isEnd(false) {
	}

	void addWord(string word) {
		WordDictionary* node = this;
		for (auto& c : word)
		{
			c -= 'a';
			if (node->_nextDics[c] == nullptr) {
				node->_nextDics[c] = new WordDictionary();
			}
			node = node->_nextDics[c];
		}
		node->_isEnd = true;
	}

	bool search(string word) {
		return SearchImpl(word, 0, word.length() - 1);
	}

	bool SearchImpl(string& word, int index, int wordMaxIndex) {
		if (word[index] == '.') {
			for (int i = 0; i < 26; i++)
			{
				if (_nextDics[i] != nullptr) {
					if (index == wordMaxIndex) {
						if (_nextDics[i]->_isEnd) {
							return true;
						}
					}
					else if (_nextDics[i]->SearchImpl(word, index + 1, wordMaxIndex)) {
						return true;
					}
				}
			}
		}
		else {
			char c = word[index];
			c -= 'a';
			if (_nextDics[c] != nullptr) {
				if (index == wordMaxIndex) {
					if (_nextDics[c]->_isEnd) {
						return true;
					}
				}
				else {
					return _nextDics[c]->SearchImpl(word, index + 1, wordMaxIndex);
				}
			}
		}
		return false;
	}
};
//
//int main() {
//	WordDictionary wordDictionary;
//	wordDictionary.addWord("bad");
//	wordDictionary.addWord("dad");
//	wordDictionary.addWord("mad");
//	cout << wordDictionary.search("pad") << endl; // return False
//	cout << wordDictionary.search("bad") << endl; // return True
//	cout << wordDictionary.search(".ad") << endl; // return True
//	cout << wordDictionary.search("b..") << endl; // return True
//}
