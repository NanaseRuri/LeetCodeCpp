#include "stdafx.h"

class MyHashMap {
public:
	vector<list<pair<int, int>>> _mapImpl;
	static const int Base = 769;

	MyHashMap() :_mapImpl(Base) {

	}

	void put(int key, int value) {
		int hashKey = key % Base;
		auto& keyPairList = _mapImpl[hashKey];
		for (auto& keyPair : keyPairList)
		{
			if (keyPair.first == key) {
				keyPair.second = value;
				return;
			}
		}

		keyPairList.emplace_back(make_pair(key, value));
	}

	int get(int key) {
		int hashKey = key % Base;
		auto& keyPairList = _mapImpl[hashKey];
		for (auto& keyPair : keyPairList)
		{
			if (keyPair.first == key) {
				return keyPair.second;
			}
		}

		return -1;
	}

	void remove(int key) {
		int hashKey = key % Base;
		auto& keyPairList = _mapImpl[hashKey];
		for (auto it = keyPairList.begin(); it != keyPairList.end(); ++it)
		{
			if (it->first == key)
			{
				keyPairList.erase(it);
				return;
			}
		}
	}
};
