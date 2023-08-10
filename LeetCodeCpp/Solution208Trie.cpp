#include "stdafx.h"


using namespace std;
class Trie {
private:
	vector<Trie*> _children;
	bool _isEnd;

	Trie* SearchPrefix(string prefix) {
		Trie* node = this;
		for (auto c : prefix)
		{
			c -= 'a';
			if (node->_children[c] == nullptr) {
				return nullptr;
			}
			node = node->_children[c];
		}
		return node;
	}

public:
	Trie() :_children(26), _isEnd(false) {
	}

	void insert(string word) {
		Trie* node = this;
		for (auto c : word)
		{
			c -= 'a';
			if (node->_children[c] == nullptr) {
				node->_children[c] = new Trie();
			}
			node = node->_children[c];
		}
		node->_isEnd = true;
	}

	bool search(string word) {
		Trie* result = SearchPrefix(word);

		return result != nullptr && result->_isEnd;
	}

	bool startsWith(string prefix) {
		return SearchPrefix(prefix) != nullptr;
	}
};
