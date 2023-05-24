
#include <stdio.h>
#define INFN 99999

void allPairsShortest(int** distance, int n)
{
	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (distance[i][j] < distance[i][k] + distance[k][i])
					distance[i][j] = distance[i][k] + distance[k][i];
}

int main()
{
}