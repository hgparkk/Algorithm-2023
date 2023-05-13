#pragma once

typedef struct _Node
{
	int value;
	_Node* nodeL;
	_Node* nodeR;
}Node;

extern Node* makeTree();
extern void printTree(Node* root);