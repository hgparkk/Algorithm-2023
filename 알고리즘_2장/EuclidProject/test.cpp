
/*
파일 이름: test.cpp
설명 : 재귀함수를 이용한 유클리드 알고리즘과 반복문을 이용한 유클리드 알고리즘의 결과 비교와 실행시간 비교 프로그램
작성자 : 박현규
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "euclid.h"

int testEuclid()
{
	//1. 1000 쌍의 수를 짝짓기 위해 두 배열을 선언한다.
	long long a[1000];
	long long b[1000];

	//2. 랜덤한 변수를 배열에 저장한다. (큰 수를 만들기 위해 랜덤한 수를 세번 곱한다, a>=b>=0 조건이 있으므로 b가 더 크면 a와 b를 바꾼다.
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

	//3. 재귀함수를 이용한 유클리드 알고리즘을 이용하여 1000쌍의 최대 공약수를 구하고, 구한 값을 배열에 저장한다. 동시에 실행시간을 체크한다.
	long long a1array[1000];
	clock_t startTime1 = clock();
	for (int i = 0; i < 1000; i++)
	{
		long long a1 = euclidRecursive(a[i], b[i]);
		a1array[i] = a1;
		printf("%lld 와 %lld의 최대공약수는 %lld 입니다. \n", a[i], b[i], a1);
	}
	clock_t finishTime1 = clock();

	//4. 반복문을 이용한 유클리드 알고리즘을 이용하여 1000쌍의 최대 공약수를 구하고, 구한 값을 배열에 저장한다. 동시에 실행시간을 체크한다.
	long long a2array[1000];
	clock_t startTime2 = clock();
	for(int i = 0; i < 1000; i++)
	{
		long long a2 = euclidRepeatitive(a[i], b[i]);
		a2array[i] = a2;
		printf("%lld 와 %lld의 최대공약수는 %lld 입니다. \n", a[i], b[i], a2);
	}
	clock_t finishTime2 = clock();

	//5. 두 방법을 이용한 최대 공약수에 차이가 있는지 알린다.
	for (int i = 0; i < 1000; i++)
	{
		if (a1array[i] != a2array[i])
			printf("계산한 수에 차이가 있습니다");
	}

	//6. 두 방법의 실행시간을 계산한다.
	double timeSec1 = (double)((finishTime1 - startTime1) / CLOCKS_PER_SEC);
	double timeSec2 = (double)((finishTime2 - startTime2) / CLOCKS_PER_SEC);
	
	//7. 두 방법의 실행시간을 알린다.
	printf("두 함수의 실행시간은 각각 %lf초, %lf초 입니다 \n", timeSec1, timeSec2);

	return 0;
}
