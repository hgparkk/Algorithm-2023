
#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int main(int argc, char argv[])
{
	Node* root = makeTree();
	insertLeftNode(root->right, createNode(400));
	insertRightNode(root->right, createNode(500));
	printTree(root);
}
