
#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int main(int argc, char argv[])
{
	Node* root = makeTree();
	printTree(root);
}
