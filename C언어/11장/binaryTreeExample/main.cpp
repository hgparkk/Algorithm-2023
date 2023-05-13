
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "tree.h"

extern Node* makeTree();
extern void printTree(Node* root);

int main(int argc, char argv[])
{
	Node* root = makeTree();
	printTree(root);

	_getch();
}
