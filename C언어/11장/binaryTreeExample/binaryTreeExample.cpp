/*
파일 이름: binaryTreeExample.cpp
설명 : 이진트리 예제
작성자 : 박현규
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct _Node
{
	int value;
	_Node* nodeL;
	_Node* nodeR;
}Node;

Node* root;

static Node* createNode(int value)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->value = value;
	node->nodeL = NULL;
	node->nodeR = NULL;

	return node;
}

static Node* connectChild(Node* parent, Node* left, Node* right)
{
	if (parent == NULL) return NULL;

	parent->nodeL = left;
	parent->nodeR = right;

	return parent;
}

Node* makeTree()
{
	Node* root = createNode(100);
	Node* nodeL = createNode(200);
	Node* nodeR = createNode(300);

	connectChild(root, nodeL, nodeR);

	connectChild(nodeR,createNode(400),createNode(500));

	return root;
}

void printTree(Node* root)
{
	if (root == NULL) return;
	else
	{
		printf("Node: %d,", root->value);
		printTree(root->nodeL);
		printTree(root->nodeR);
	}
}