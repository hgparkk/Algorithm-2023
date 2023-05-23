/*
파일 이름: tree.cpp
설명 : 이진트리 예제
작성자 : 박현규
*/

#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

// 임의의 값(value)를 가진 노드를 생성한다. 초기 왼쪽자식노드와 오른쪽자식노드는 NULL이다.
Node* createNode(int value)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->value = value;
	node->left = NULL;
	node->right = NULL;

	return node;
}

// 노드들의 부모 자식 관계를 설정한다.
Node* connectChild(Node* parent, Node* left, Node* right)
{
	if (parent == NULL) return NULL;

	parent->left = left;
	parent->right = right;

	return parent;
}

// findNode() 함수는 이진트리에서 구현할 수 없음

// 임의의 노드(*where)의 왼쪽자식노드를 해당노드(*new_node)로 한다.
Node* insertLeftNode(Node* where, Node* new_node)
{
	if (where == NULL) return NULL;
	else
	{
		where->left = new_node;
		return where;
	}
}

// 임의의 노드(*where)의 오른쪽자식노드를 해당노드(*new_node)로 한다.
Node* insertRightNode(Node* where, Node* new_node)
{
	if (where == NULL) return NULL;
	else
	{
		where->right = new_node;
		return where;
	}
}

// 트리를 출력한다. (출력은 루트 > 왼쪽자식 > 오른쪽자식 노드 순으로 출력한다.)
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