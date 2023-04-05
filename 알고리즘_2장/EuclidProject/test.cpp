
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "euclid.h"

int testEuclid()
{
	long long a[1000];
	long long b[1000];
	long long seed = time(NULL);
	srand(seed);

	for (int i=0; i<1000; i++)
	{
		long long num1 = rand();
		a[i] = num1 * num1 * num1;
		long long num2 = rand();
		b[i] = num2 * num2 * num2;
		if (a[i] < b[i])
		{
			long long temp = a[i];
			a[i] = b[i];
			b[i] = temp;
		}
	}

	long long a1array[1000];
	clock_t startTime1 = clock();
	for (int i = 0; i < 1000; i++)
	{
		long long a1 = euclidRecursive(a[i], b[i]);
		a1array[i] = a1;
		printf("%lld 와 %lld의 최대공약수는 %lld 입니다. \n", a[i], b[i], a1);
	}
	clock_t finishTime1 = clock();

	long long a2array[1000];
	clock_t startTime2 = clock();
	for(int i = 0; i < 1000; i++)
	{
		long long a2 = euclidRepeatitive(a[i], b[i]);
		a2array[i] = a2;
		printf("%lld 와 %lld의 최대공약수는 %lld 입니다. \n", a[i], b[i], a2);
	}
	clock_t finishTime2 = clock();

	for (int i = 0; i < 1000; i++)
	{
		if (a1array[i] != a2array[i])
			printf("계산 오류");
	}

	double timeSec1 = (double)((finishTime1 - startTime1) / CLOCKS_PER_SEC);
	double timeSec2 = (double)((finishTime2 - startTime2) / CLOCKS_PER_SEC);
	
	printf("두 함수의 실행시간은 각각 %lf초, %lf초 입니다 \n", timeSec1, timeSec2);

	return 0;
}
