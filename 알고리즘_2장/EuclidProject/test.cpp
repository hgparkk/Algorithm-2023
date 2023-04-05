
#include <stdio.h>
#include <time.h>
#include "euclid.h"

int testEuclid()
{
	clock_t startTime1 = clock();
	int a = euclidRecursive(48, 34);
	clock_t finishTime1 = clock();
	double timeSec1 = (double)((finishTime1 - startTime1) / CLOCKS_PER_SEC);
	printf("%d 와 %d의 최대공약수는 %d 입니다. 실행시간 %lf 초\n", 48, 34, a, timeSec1);

	clock_t startTime2 = clock();
	int a = euclidRepeatitive(48, 34);
	clock_t finishTime2 = clock();
	double timeSec2 = (double)((finishTime2 - startTime2) / CLOCKS_PER_SEC);
	printf("%d 와 %d의 최대공약수는 %d 입니다. 실행시간 %lf 초\n", 48, 34, a, timeSec2);
	return 0;
}
