
/*
파일 이름: euclid.cpp
설명 : 재귀함수를 사용한 유클리드 알고리즘과 반복문을 사용한 유클리드 알고리즘의 결과와 실행시간 비교 프로그램
작성자 : 박현규
*/

#include <stdio.h>

//1. 재귀함수와 반복문을 이용한 유클리드 알고리즘을 각각 구현한다.

// 재귀함수를 이용한 유클리드 알고리즘
long long euclidRecursive(long long a, long long b)
{
	if (b == 0)
		return a;
	else
		return euclidRecursive(b, a % b);
}

// 반복문을 이용한 유클리드 알고리즘
long long euclidRepeatitive(long long a, long long b)
{
	if (a < b)
		return 0;
	long long basv;
	while (b != 0)
	{
		basv = b;
		b = a % b;
		a = basv;
	}
	return a;
}