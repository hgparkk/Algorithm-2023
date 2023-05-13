
#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

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