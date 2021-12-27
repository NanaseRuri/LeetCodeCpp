#pragma once

class Node
{
public:
	int val;
	Node* left;
	Node* right;
	Node* next;

	Node();

	Node(int val);

	Node(int _val, Node* _left, Node* _right, Node* _next);
};

#include <vector>
#include <queue>
using namespace std;
Node* BuildNode(vector<int>values);