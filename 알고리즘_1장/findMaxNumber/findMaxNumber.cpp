
/*
파일 이름: findMaxNumber.cpp
설명 : 가장 큰 수를 반환하는 프로그램
작성자 : 박현규
*/

#include <stdio.h>

int findMaxNumber(int NumArray[], int count)
{
	int max = -1;

	//1. 처음 숫자를 읽어 최대값 변수 max 에 저장한다.
	max = NumArray[0];

	//2. 다음 숫자를 읽어 max와 비교하여 더 큰 숫자면 max를 갱신한다.
	//3. 남은 숫자에 대해 2를 반복한다.
	for (int i = 1; i < count; i++)
	{
		if (NumArray[i] > max) 
			max = NumArray[i];
	}

	//4. 가장 큰 수 max를 반환한다.
	return max;
}

int test_findMaxNumber()
{
	int Array[] = { 45,20,35,60,55,10,90,85,75,25 };
	int maxNum = -1;

	maxNum = findMaxNumber(Array, sizeof(Array) / sizeof(int));
	printf("최댓값은 %d 입니다.\n", maxNum);
	return 0;
}

int main(void)
{
	test_findMaxNumber();
}