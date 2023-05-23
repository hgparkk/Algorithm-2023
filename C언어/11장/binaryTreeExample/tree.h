#pragma once

typedef struct _Node
{
	int value;
	struct _Node* left;
	struct _Node* right;
}Node;

extern Node* createNode(int value);
extern Node* connectChild(Node* parent, Node* left, Node* right);
extern Node* insertLeftNode(Node* where, Node* new_node);
extern Node* insertRightNode(Node* where, Node* new_node);
extern Node* makeTree();
extern void printTree(Node* root);