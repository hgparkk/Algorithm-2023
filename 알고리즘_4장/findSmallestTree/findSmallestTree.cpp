
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INFN (9203920249)

typedef struct _NodeInfo
{
	int id;
	char name[20];
} Node;

typedef struct _Bnode {
	int id;
	Bnode* left;
	Bnode* right;
}Bnode;

// const char* nodeName[4] = { "n0","n1","n2","n3" };
Node nodeSet[4] = { {2331,"n0"},{9993,"n1"},{332,"n2"},{234,"n3"} };

int G[4][4] =
{
	{0,3,INFN,INFN},
	{INFN,0,4,INFN},
	{INFN,INFN,0,5},
	{INFN,INFN,2,0}
};

Bnode* initTree()
{
	Bnode* b0 = (Bnode*)malloc(sizeof(Bnode));
	Bnode* b1 = (Bnode*)malloc(sizeof(Bnode));
	Bnode* b2 = (Bnode*)malloc(sizeof(Bnode));
	Bnode* b3 = (Bnode*)malloc(sizeof(Bnode));
	Bnode* b4 = (Bnode*)malloc(sizeof(Bnode));

	b0->left = b1;
	b1->right = b2;
	b2->left = b3;
	b2->right = b4;

	return b0;
}

int main()
{
	for (int i = 0; i < 4; i++)
	{
		printf("%s\n", nodeSet[i].name);
	}
}