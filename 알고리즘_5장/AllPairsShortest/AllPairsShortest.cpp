
#include <stdio.h>
#define INFN 99999

void printArray(int array[5][5], int n);

void allPairsShortest(int distance[5][5], int n)
{
	for (int k = 0; k < n; k++)
	{
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (distance[i][j] > distance[i][k] + distance[k][i])
					distance[i][j] = distance[i][k] + distance[k][i];
}

void printArray(int array[5][5], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d ", array[i][j]);
		}
		printf("\n");
	}
}

void testAllPair()
{
	int graph[5][5] =
	{
		{0,180,60,120,INFN},
		{INFN,0,60,INFN,60},
		{INFN,60,0,30,300},
		{180,INFN,INFN,0,360},
		{INFN,60,300,420,0}
	};
	allPairsShortest(graph, 5);
	printArray(graph,5);

}

int main()
{
	testAllPair();
}