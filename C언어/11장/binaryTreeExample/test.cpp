
#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

// 임의의 값 (100,200,300,400,500)과 자식관계 (100의 왼쪽자식은 200, 오른쪽 자식은 300, 300의 왼쪽 자식은 400, 오른쪽 자식은 500)를 가진 이진트리를 구현한다.
Node* makeTree()
{
	Node* root = createNode(100);
	Node* nodeL = createNode(200);
	Node* nodeR = createNode(300);

	connectChild(root, nodeL, nodeR);

	insertLeftNode(root->right, createNode(400));
	insertRightNode(root->right, createNode(500));

	return root;
}