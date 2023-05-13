
#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

Node* makeTree()
{
	Node* root = createNode(100);
	Node* nodeL = createNode(200);
	Node* nodeR = createNode(300);

	connectChild(root, nodeL, nodeR);

	return root;
}