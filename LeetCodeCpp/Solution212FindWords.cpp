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
#include <set>

using namespace std;
class Trie {
public:
	Trie() :Children(26), Word() {
	}
	vector<Trie*> Children;
	string Word;

	void insert(string& word) {
		Trie* node = this;
		for (auto c : word)
		{
			c -= 'a';
			if (node->Children[c] == nullptr) {
				node->Children[c] = new Trie();
			}
			node = node->Children[c];
		}
		node->Word = word;
	}
};

class Solution212FindWords {
private:
	Trie* _trie;
	vector<string> _result;
	int _totalRow;
	int _totalCol;

	void Dfs(vector<vector<char>>& board, Trie* currentTrie, int row, int col) {
		char currentChar = board[row][col];
		if (currentChar == '#') {
			return;
		}

		int childIndex = currentChar - 'a';
		Trie* nextTrie = currentTrie->Children[childIndex];
		if (nextTrie == nullptr) {
			return;
		}

		board[row][col] = '#';

		if (!nextTrie->Word.empty())
		{
			_result.push_back(nextTrie->Word);
			nextTrie->Word = "";
		}

		if (row > 0) {
			Dfs(board, nextTrie, row - 1, col);
		}
		if (row < _totalRow - 1) {
			Dfs(board, nextTrie, row + 1, col);
		}
		if (col > 0) {
			Dfs(board, nextTrie, row, col - 1);
		}
		if (col < _totalCol - 1) {
			Dfs(board, nextTrie, row, col + 1);
		}

		board[row][col] = currentChar;

		for (int i = 0; i < 26; i++)
		{
			if (nextTrie->Children[i] != nullptr) {
				return;
			}
		}

		delete nextTrie;
		currentTrie->Children[childIndex] = nullptr;
	}

public:
	vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
		_totalRow = board.size();
		_totalCol = board[0].size();
		_trie = new Trie();
		_result.clear();
		for (auto& word : words)
		{
			_trie->insert(word);
		}

		for (int i = 0; i < _totalRow; i++)
		{
			for (int j = 0; j < _totalCol; j++)
			{
				Dfs(board, _trie, i, j);
			}
		}

		return _result;
	}
};

//int main() {
//	Solution212FindWords solution;
//
//	vector<vector<char>> boards1{
//		{'o','a','a','n'} ,
//		{'e','t','a','e'},
//		{'i','h','k','r'},
//		{'i','f','l','v'}
//	};
//	vector<string> words1{
//		"oath","pea","eat","rain"
//	};
//	vector<vector<char>> boards2{
//		{'a','b'} ,
//		{'c','d'}
//	};
//	vector<string> words2{
//		"abcb"
//	};
//	vector<vector<char>> boards3{
//		{'a','b','e'} ,
//		{'a','b','d'}
//	};
//	vector<string> words3{
//		"aba",
//		"abd"
//	};
//	solution.findWords(boards1, words1);
//	solution.findWords(boards2, words2);
//	solution.findWords(boards3, words3);
//}