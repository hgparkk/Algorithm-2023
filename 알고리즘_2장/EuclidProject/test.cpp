
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

	clock_t startTime1 = clock();
	for (int i = 0; i < 1000; i++)
	{
		long long a1 = euclidRecursive(a[i], b[i]);
		printf("%lld 와 %lld의 최대공약수는 %lld 입니다. \n", a[i], b[i], a1);
		long long a2 = euclidRepeatitive(a[i], b[i]);
		printf("%lld 와 %lld의 최대공약수는 %lld 입니다. \n", a[i], b[i], a2);
	}
	clock_t finishTime1 = clock();
	double timeSec1 = (double)((finishTime1 - startTime1) / CLOCKS_PER_SEC);
	
	printf(" 실행시간은 %lf 입니다 \n", timeSec1);

	return 0;
}
