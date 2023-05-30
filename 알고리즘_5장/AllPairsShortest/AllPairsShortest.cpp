
#include <stdio.h>
#define INFN 99999

void allPairsShortest(int distance[5][5], int n)
{
	for (int k = 0; k < n; k++)
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
		{0,4,2,5,INFN},
		{INFN,0,1,INFN,4},
		{1,3,0,1,2},
		{-2,INFN,INFN,0,2},
		{INFN,-3,3,1,0}
	};
	allPairsShortest(graph, 5);
	printArray(graph,5);

}

int main()
{
	testAllPair();
}