
#include <stdio.h>
#include <stdlib.h>

// fileRead 함수를 통해 반환받을 구조체
typedef struct _items
{
	int* value;
	int* weight;
	int size;
}items;

// 배낭 문제를 해결하기 위한 2차원 배열을 구하는 함수
int** knapsack(int n, int C, int w[], int v[])
{
	int** K = (int**)malloc(sizeof(int*) * n);
	for (int i = 0; i < n; i++) {
		K[i] = (int*)malloc(sizeof(int) * C);
	}
	for (int i = 0; i < n; i++)
	{
		K[i][0] = 0;
	}
	for (int j = 0; j < C; j++)
	{
		K[0][j] = 0;
	}
	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < C; j++)
		{
			if (w[i] > j)
			{
				K[i][j] = K[i - 1][j];
			}
			else
			{
				if (K[i - 1][j] > K[i - 1][j - w[i]] + v[i])
					K[i][j] = K[i - 1][j];
				else
					K[i][j] = K[i - 1][j - w[i]] + v[i];
			}
		}
	}
	return K;
}

// 2차원 배열을 출력하기 위한 함수
void print_array(int** K, int k, int l)
{
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < l; j++)
		{
			printf("%d ", K[i][j]);
		}
		printf("\n");
	}
}

// 파일을 읽어 구조체로 저장하는 함수
items fileRead(char *str)
{
	int size = 1;
	items data;
	int* value;
	int* weight;
	int num;
	int tmp1;
	int tmp2;
	FILE* fp = fopen(str, "r");
	if (fp == NULL)
	{
		printf("fail to open file\n");
	}
	else
	{
		while (!feof(fp))
		{
			fscanf(fp, "%d %d %d\n", &num, &tmp1, &tmp2);
			size++;
		}
		value = (int*)malloc(sizeof(int) * size);
		weight = (int*)malloc(sizeof(int) * size);
		fp = fopen(str, "r");
		value[0] = 0;
		weight[0] = 0;
		while (!feof(fp))
		{
			fscanf(fp, "%d", &num);
			fscanf(fp, "%d %d", &weight[num], &value[num]);
		}
		fclose(fp);
		data.value = value;
		data.weight = weight;
		data.size = size;
	}
	return data;
}

//배낭 문제를 해결하기위한 함수
void test_Knapsack()
{
	int C;
	printf("배낭의 용량은? ");
	scanf("%d", &C);
	printf("\n");
	C++;
	char fname[] = "items.txt";
	items itemStruct = fileRead(fname);
	int n = itemStruct.size;
	int* w = itemStruct.weight;
	int* v = itemStruct.value;
	int** K = knapsack(n, C, w, v);
	print_array(K, n, C);
	printf("\n");
	printf("용량이 %d kg일 때, 담을 수 있는 최대 가치는 %d 이다.",C-1,K[n-1][C-1]);
}

int main()
{
	test_Knapsack();
}
