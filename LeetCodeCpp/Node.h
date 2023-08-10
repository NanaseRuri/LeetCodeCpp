#pragma once
#include "stdafx.h"
using namespace std;

class Node
{
public:
	int val;
	Node* left;
	Node* right;
	Node* next;
	Node* random;
	vector<Node*> neighbors;
	vector<Node*> children;

	Node();

	Node(int val);

	Node(int _val, Node* _left, Node* _right, Node* _next);

	Node(int _val, vector<Node*> _neighbors);
};

Node* BuildNode(vector<int>values);