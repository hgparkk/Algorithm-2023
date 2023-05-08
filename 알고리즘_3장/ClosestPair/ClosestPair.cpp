/*
파일 이름: ClosestPair.cpp
설명 : 최근점 점의 쌍 찾기 알고리즘
작성자 : 박현규
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//점의 좌표를 구조체로 구현
typedef struct
{
	int x;
	int y;
} coord;

coord* minPairs = NULL;
double min = -1;

double minNum(double a, double b)
{
	if (a < b)
		return a;
	else
		return b;
}

//두 점 사이의 거리를 구하고 더 작은 값이 나온 점의 쌍을 임의로 저장하는 함수
double measureDistance(coord* a, coord* b)
{
	double distance;

	distance = sqrt(pow(a->x - b->x, 2) + pow(a->y - b->y, 2));
	if (min == -1 || distance < min)
	{
		*minPairs = *a;
		*(minPairs + 1) = *b;
		min = distance;
	}
	return distance;
}

double ClosestPair(coord* pairs, int left, int right, int size)
{
	// 점이 두개 일 때, 두 점의 길이를 반환한다.
	if (size == 2)
	{
		return measureDistance(pairs + left, pairs + right);
	}
	// 점이 세개일 때, 세 점 사이의 거리를 각각 계산하여 가장 짧은 값을 반환한다.
	else if (size == 3)
	{
		double distance1, distance2, distance3, min;
		distance1 = measureDistance(pairs, pairs + 1);
		distance2 = measureDistance(pairs + 1, pairs + 2);
		distance3 = measureDistance(pairs + 2, pairs);

		min = minNum(distance1, distance2);
		min = minNum(distance3, min);
		return min;
	}
	else
	{
		int mid = (left + right) / 2;
		double distanceRange;
		double CPright, CPleft;

		//점이 3개 이상일 때 점의 개수가 같게 되도록 점들을 나눈다 (홀수일 경우 오른쪽에 하나를 더 둔다)
		CPleft = ClosestPair(pairs, left, mid, mid - left + 1);
		CPright = ClosestPair(pairs, mid + 1, right, right - mid);
		//두 점 사이의 거리 중 더 짧은 값을 distanceRange로 두고 중간 영역을 설정한다.
		distanceRange = minNum(CPleft, CPright);

		coord* pairsTmp = (coord*)malloc(sizeof(coord)*size);
		int cnt = 0;

		double minSub = -1;

		//중간 영역에서 가장 짧은 거리를 가진 점의 쌍을 찾고 distanceRange와 비교하여 더 짧은 값을 distanceRange로 두고 반환한다.
		for (int i = left; i <= right; i++)
		{
			if (abs((pairs + i)->x - (pairs + mid)->x) < distanceRange)
			{
				(pairsTmp + cnt)->x = (pairs + i)->x;
				(pairsTmp + cnt)->y = (pairs + i)->y;
				cnt++;
			}
		}
		for (int i = 0; i < cnt; i++)
		{
			for (int j = i + 1; j < cnt; j++)
			{
				minSub = minNum(distanceRange, measureDistance(pairsTmp + i, pairsTmp + j));

				if (minSub < distanceRange)
				{
					distanceRange = minSub;
					if (minSub < min)
					{
						*minPairs = *(pairsTmp + i);
						*(minPairs + 1) = *(pairsTmp + j);
					}
				}
			}
		}
		free(pairsTmp);
		return distanceRange;
	}
}

int coordCompare(const void* a, const void* b)
{
	const coord* m, * n;
	m = (const coord*)a;
	n = (const coord*)b;
	if (m->x > n->x)
	{
		return 1;
	}
	else if (m->x == n->x)
	{
		return 0;
	}
	else
	{
		return -1;
	}
}

// 임의의 점들의 집합 데이터 "data.txt"를 읽는다.
coord* fileRead()
{
	int size = 0;
	int i = 0;
	coord* data;
	coord tmp;
	FILE* fp = fopen("data.txt", "r");
	if (fp == NULL)
	{
		printf("fail to open file\n");
	}
	else
	{
		while (!feof(fp))
		{
			fscanf(fp, "%d %d\n", &tmp.x, &tmp.y);
			size++;
		}
		data = (coord*)malloc(sizeof(coord) * size);
		fp = fopen("data.txt", "r");
		while (!feof(fp))
		{
			fscanf(fp, "%d %d\n", &data[i].x, &data[i].y);
			i++;
		}
		fclose(fp);
	}
	return data;
}

// 결과를 "result.txt"에 출력한다.
void fileWrite(int x1, int y1, int x2, int y2, double cp)
{
	FILE* fp = fopen("result.txt", "w");
	if (fp == NULL)
	{
		printf("fail to open file\n");
	}
	else
	{
		fprintf(fp, "최근점 점의 쌍은 %d,%d 와 %d,%d 이고 거리는 %lf 입니다.\n",x1,y1,x2,y2,cp);
		fclose(fp);
	}
}

int main()
{
	coord* data = fileRead();
	int size = _msize(data) / sizeof(coord);
	minPairs = (coord*)malloc(sizeof(coord) * 2);
	qsort(data, (size_t)size, sizeof(coord), coordCompare);
	double cp = ClosestPair(data, 0, size - 1, size);
	int x1 = (minPairs+0)->x;
	int y1 = (minPairs + 0)->y;
	int x2 = (minPairs + 1)->x;
	int y2 = (minPairs + 1)->y;
	fileWrite(x1, y1, x2, y2, cp);
}