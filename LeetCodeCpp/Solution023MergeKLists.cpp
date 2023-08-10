#include "stdafx.h"

using namespace std;

struct MinHeap {
private:
	int _size;
	vector<ListNode*> _heap;

	void InitalizeHeap() {
		for (int i = _size / 2; i > 0; i--) {
			if (2 * i == _size) {
				if (_heap[i]->val > _heap[2 * i]->val) {
					auto temp = _heap[2 * i];
					_heap[2 * i] = _heap[i];
					_heap[i] = temp;
				}
			}
			else {
				Adjust(i);
			}
		}
	}

	void Adjust(int parentIndex) {
		if (2 * parentIndex == _size) {
			if (_heap[parentIndex]->val > _heap[2 * parentIndex]->val) {
				auto temp = _heap[2 * parentIndex];
				_heap[2 * parentIndex] = _heap[parentIndex];
				_heap[parentIndex] = temp;
			}
		}
		else {
			if (_heap[parentIndex]->val > _heap[2 * parentIndex]->val && _heap[2 * parentIndex]->val <= _heap[2 * parentIndex + 1]->val) {
				auto leftChild = _heap[2 * parentIndex];
				_heap[2 * parentIndex] = _heap[parentIndex];
				_heap[parentIndex] = leftChild;

				if (4 * parentIndex <= _size) {
					Adjust(2 * parentIndex);
				}
			}
			else if (_heap[parentIndex]->val > _heap[2 * parentIndex + 1]->val && _heap[2 * parentIndex + 1]->val <= _heap[2 * parentIndex]->val) {
				auto rightChild = _heap[2 * parentIndex + 1];
				_heap[2 * parentIndex + 1] = _heap[parentIndex];
				_heap[parentIndex] = rightChild;

				if (4 * parentIndex + 2 <= _size) {
					Adjust(2 * parentIndex + 1);
				}
			}
		}
	}

public:
	int Size() {
		return _size;
	}

	MinHeap(vector<ListNode*>& firstNodes) {
		_size = firstNodes.size() - 1;
		_heap = firstNodes;

		InitalizeHeap();
	}

	/// <summary>
	/// �����ǰ���ؽڵ���ӽڵ㲻Ϊ�գ�����Ϊ�ӽڵ㣬�������һ��Ԫ�ط�������ͬʱ����-1�������е���
	/// </summary>
	/// <returns></returns>
	ListNode* GetMinListNode() {
		ListNode* result = _heap[1];
		if (_heap[1]->next != nullptr) {
			_heap[1] = _heap[1]->next;
		}
		else {
			_heap[1] = _heap[_size];
			_heap[_size] = nullptr;
			_size--;
		}
		if (_size > 1) {
			Adjust(1);
		}
		return result;
	}
};

class Solution023MergeKLists {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		vector<ListNode*> notNullList;
		notNullList.push_back(new ListNode(INT32_MAX));
		int listSize = lists.size();
		for (int i = 0; i < listSize; i++)
		{
			if (lists[i] != nullptr) {
				notNullList.push_back(lists[i]);
			}
		}

		if (notNullList.size() == 1) {
			return nullptr;
		}

		ListNode* guard = new ListNode();
		ListNode* dump = guard;
		MinHeap heap(notNullList);
		while (heap.Size() > 0) {
			dump->next = heap.GetMinListNode();
			dump = dump->next;
		}

		return guard->next;
	}
};

//int main() {
//	vector<ListNode*> listNodes;
//	ListNode* node1 = GetListNode({ -8, 2, 4 });
//	ListNode* node2 = GetListNode({ -9, -9, -9, -9, -8, -5, -3, -2, 1 });
//	ListNode* node3 = GetListNode({ -9, -7, -5, -3, -3, -1, 0, 3, 4 });
//	ListNode* node4 = GetListNode({ -9, -7, -6, -4, -2, -1, 3, 4 });
//	ListNode* node5 = GetListNode({ -10, -3, 0 });
//	ListNode* node6 = GetListNode({ -9, 0, 4 });
//	ListNode* node7 = GetListNode({ -8, -8 });
//
//	listNodes.push_back(node1);
//	listNodes.push_back(node2);
//	listNodes.push_back(node3);
//	listNodes.push_back(node4);
//	listNodes.push_back(node5);
//	listNodes.push_back(node6);
//	listNodes.push_back(node7);
//
//	Solution023MergeKLists solution;
//	auto result = solution.mergeKLists(listNodes);
//	while (result != nullptr)
//	{
//		cout << result->val << '\t' << endl;
//		result = result->next;
//	}
//}
