
#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

// ������ �� (100,200,300,400,500)�� �ڽİ��� (100�� �����ڽ��� 200, ������ �ڽ��� 300, 300�� ���� �ڽ��� 400, ������ �ڽ��� 500)�� ���� ����Ʈ���� �����Ѵ�.
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