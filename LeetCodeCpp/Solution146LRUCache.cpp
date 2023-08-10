#include "stdafx.h"

using namespace std;

class LRUCache
{
public:
	struct LinkedListNode
	{
		int Key;
		int Value;
		LinkedListNode* Pre;
		LinkedListNode* Next;
		LinkedListNode(int key, int value) :Key(key), Value(value), Pre(nullptr), Next(nullptr)
		{
		};
	};

	unordered_map<int, LinkedListNode*> _cacheMap;
	LinkedListNode* _linkedListNodeHead;
	LinkedListNode* _linkedListNodeTail;

	int _capacity;
	int _currentSize;
	LRUCache(int capacity) :_capacity(capacity), _currentSize(0) {
		_linkedListNodeHead = new LinkedListNode(0, 0);
		_linkedListNodeTail = new LinkedListNode(0, 0);
		_linkedListNodeHead->Next = _linkedListNodeTail;
		_linkedListNodeTail->Pre = _linkedListNodeHead;
	}

	int get(int key) {
		if (_cacheMap.find(key) != _cacheMap.end()) {
			LinkedListNode* currentListNode = _cacheMap[key];
			MoveNodeToHead(currentListNode);
			return _cacheMap[key]->Value;
		}
		else {
			return -1;
		}
	}

	void put(int key, int value) {
		if (_cacheMap.find(key) != _cacheMap.end()) {
			_cacheMap[key]->Value = value;
			MoveNodeToHead(_cacheMap[key]);
		}
		else {
			if (_currentSize != _capacity) {
				_currentSize++;
			}
			else {
				LinkedListNode* leastUsedNode = _linkedListNodeTail->Pre;
				leastUsedNode->Pre->Next = _linkedListNodeTail;
				_linkedListNodeTail->Pre = leastUsedNode->Pre;
				_cacheMap.erase(leastUsedNode->Key);
				delete leastUsedNode;
			}
			LinkedListNode* newListNode = new LinkedListNode(key, value);
			InsertNodeToHead(newListNode);
			_cacheMap.insert({ key,newListNode });
		}
	}

	void InsertNodeToHead(LinkedListNode* node) {
		node->Next = _linkedListNodeHead->Next;
		node->Pre = _linkedListNodeHead;
		_linkedListNodeHead->Next->Pre = node;
		_linkedListNodeHead->Next = node;
	}

	void MoveNodeToHead(LinkedListNode* node) {
		node->Pre->Next = node->Next;
		node->Next->Pre = node->Pre;
		InsertNodeToHead(node);
	}
};

//int main() {
//	LRUCache lruCache(2);
//	lruCache.put(2, 1);
//	lruCache.put(1, 1);
//	lruCache.put(2, 3);
//	lruCache.put(4, 1);
//	cout << lruCache.get(1) << endl;
//	cout << lruCache.get(2) << endl;
//}
