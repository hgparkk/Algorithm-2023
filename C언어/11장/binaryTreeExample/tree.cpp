/*
파일 이름: binaryTreeExample.cpp
설명 : 이진트리 예제
작성자 : 박현규
*/

#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

Node* createNode(int value)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->value = value;
	node->left = NULL;
	node->right = NULL;

	return node;
}

Node* connectChild(Node* parent, Node* left, Node* right)
{
	if (parent == NULL) return NULL;

	parent->left = left;
	parent->right = right;

	return parent;
}

// findNode() 함수는 이진트리에서 구현할 수 없음

Node* insertLeftNode(Node* where, Node* new_node)
{
	if (where == NULL) return NULL;
	else
	{
		where->left = new_node;
		return where;
	}
}

Node* insertRightNode(Node* where, Node* new_node)
{
	if (where == NULL) return NULL;
	else
	{
		where->right = new_node;
		return where;
	}
}

void printTree(Node* root)
{
	if (root == NULL) return;
	else
	{
		printf("Node: %d, ", root->value);
		printTree(root->left);
		printTree(root->right);
	}
}