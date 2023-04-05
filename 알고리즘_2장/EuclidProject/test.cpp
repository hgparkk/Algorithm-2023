
/*
파일 이름: test.cpp
설명 : 재귀함수를 이용한 유클리드 알고리즘과 반복문을 이용한 유클리드 알고리즘의 결과와 실행시간 비교 프로그램
작성자 : 박현규
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "euclid.h"

int testEuclid()
{
	//2. 1000개의 숫자 쌍을 저장하기 위한 두 배열을 선언한다.
	long long a[1000];
	long long b[1000];

	//3. 랜덤한 변수를 배열에 저장한다. (큰 수를 만들기 위해 랜덤한 수를 세번 곱한다, 알고리즘을 실행하기 위한 a>=b>=0 조건이 있으므로 b가 더 크면 a와 b를 바꾼다.
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

	//4. 재귀함수를 이용한 유클리드 알고리즘을 이용하여 1000쌍의 최대 공약수를 구하고, 구한 값을 배열에 저장한다. 동시에 실행시간을 체크한다.
	long long a1array[1000];
	clock_t startTime1 = clock();
	for (int i = 0; i < 1000; i++)
	{
		long long a1 = euclidRecursive(a[i], b[i]);
		a1array[i] = a1;
		printf("%lld 와 %lld의 최대공약수는 %lld 입니다. \n", a[i], b[i], a1);
	}
	clock_t finishTime1 = clock();

	//5. 반복문을 이용한 유클리드 알고리즘을 이용하여 1000쌍의 최대 공약수를 구하고, 구한 값을 배열에 저장한다. 동시에 실행시간을 체크한다.
	long long a2array[1000];
	clock_t startTime2 = clock();
	for(int i = 0; i < 1000; i++)
	{
		long long a2 = euclidRepeatitive(a[i], b[i]);
		a2array[i] = a2;
		printf("%lld 와 %lld의 최대공약수는 %lld 입니다. \n", a[i], b[i], a2);
	}
	clock_t finishTime2 = clock();

	//6. 두 방법을 이용한 최대 공약수에 차이가 생긴 횟수를 체크하고 그 횟수를 알린다.
	int count = 0;
	for (int i = 0; i < 1000; i++)
	{
		if (a1array[i] != a2array[i])
			count++;
	}
	printf("두 함수의 실행결과 다른 경우는 %d 번 입니다 \n", count);

	//7. 두 방법의 실행시간을 계산하고 비교한다.
	double timeSec1 = (double)((finishTime1 - startTime1) / CLOCKS_PER_SEC);
	double timeSec2 = (double)((finishTime2 - startTime2) / CLOCKS_PER_SEC);
	printf("두 함수의 실행시간은 각각 %lf초, %lf초 입니다 \n", timeSec1, timeSec2);

	return 0;
}
