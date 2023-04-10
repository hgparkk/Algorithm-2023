
/*
���� �̸�: test.cpp
���� : ����Լ��� �̿��� ��Ŭ���� �˰���� �ݺ����� �̿��� ��Ŭ���� �˰����� ����� ����ð� �� ���α׷�
�ۼ��� : ������
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "euclid.h"

int testEuclid()
{
	//2. 1000���� ���� ���� �����ϱ� ���� �� �迭�� �����Ѵ�.
	long long a[1000];
	long long b[1000];

	//3. ������ ������ �迭�� �����Ѵ�. (ū ���� ����� ���� ������ ���� ���� ���Ѵ�, �˰����� �����ϱ� ���� a>=b>=0 ������ �����Ƿ� b�� �� ũ�� a�� b�� �ٲ۴�.
	long seed = time(NULL);
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

	//4. ����Լ��� �̿��� ��Ŭ���� �˰����� �̿��Ͽ� 1000���� �ִ� ������� ���ϰ�, ���� ���� �迭�� �����Ѵ�. ���ÿ� ����ð��� üũ�Ѵ�.
	long long a1array[1000];
	clock_t startTime1 = clock();
	for (int i = 0; i < 1000; i++)
	{
		long long a1 = euclidRecursive(a[i], b[i]);
		a1array[i] = a1;
		printf("%lld �� %lld�� �ִ������� %lld �Դϴ�. \n", a[i], b[i], a1);
	}
	clock_t finishTime1 = clock();

	//5. �ݺ����� �̿��� ��Ŭ���� �˰����� �̿��Ͽ� 1000���� �ִ� ������� ���ϰ�, ���� ���� �迭�� �����Ѵ�. ���ÿ� ����ð��� üũ�Ѵ�.
	long long a2array[1000];
	clock_t startTime2 = clock();
	for(int i = 0; i < 1000; i++)
	{
		long long a2 = euclidRepeatitive(a[i], b[i]);
		a2array[i] = a2;
		printf("%lld �� %lld�� �ִ������� %lld �Դϴ�. \n", a[i], b[i], a2);
	}
	clock_t finishTime2 = clock();

	//6. �� ����� �̿��� �ִ� ������� ���̰� ���� Ƚ���� üũ�ϰ� �� Ƚ���� �˸���.
	int count = 0;
	for (int i = 0; i < 1000; i++)
	{
		if (a1array[i] != a2array[i])
			count++;
	}
	printf("�� �Լ��� ������ �ٸ� ���� %d �� �Դϴ� \n", count);

	//7. �� ����� ����ð��� ����ϰ� ���Ѵ�.
	double timeSec1 = (double)((finishTime1 - startTime1) / CLOCKS_PER_SEC);
	double timeSec2 = (double)((finishTime2 - startTime2) / CLOCKS_PER_SEC);
	printf("�� �Լ��� ����ð��� ���� %lf��, %lf�� �Դϴ� \n", timeSec1, timeSec2);

	return 0;
}
