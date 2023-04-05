
#include <stdio.h>
#include <time.h>
#include "euclid.h"

int testEuclid()
{
	clock_t startTime1 = clock();
	int a = euclidRecursive(48, 34);
	clock_t finishTime1 = clock();
	double timeSec1 = (double)((finishTime1 - startTime1) / CLOCKS_PER_SEC);
	printf("%d �� %d�� �ִ������� %d �Դϴ�. ����ð� %lf ��\n", 48, 34, a, timeSec1);

	clock_t startTime2 = clock();
	int a = euclidRepeatitive(48, 34);
	clock_t finishTime2 = clock();
	double timeSec2 = (double)((finishTime2 - startTime2) / CLOCKS_PER_SEC);
	printf("%d �� %d�� �ִ������� %d �Դϴ�. ����ð� %lf ��\n", 48, 34, a, timeSec2);
	return 0;
}
