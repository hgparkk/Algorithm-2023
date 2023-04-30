
/*
파일 이름: calCoins.cpp
설명 : 거스름돈을 최소 동전의 수로 계산하는 프로그램
작성자 : 박현규
*/

#include <stdio.h>
#include <stdlib.h>

struct Ncoins calCoins(int change);
void printChange();

int main()
{
	printChange();
}

struct Ncoins
{
	int n500;
	int n100; 
	int n50;
	int n10;
};

struct Ncoins calCoins(int change)
{
	struct Ncoins result;
	//1. 거스름돈을 500으로 나눈 몫을 n500, 나머지를 r에 저장한다.
	result.n500 = change / 500;
	int r = change % 500;
	//2. r을 100으로 나눈 몫을 n100, 나머지를 r에 저장한다.
	result.n100 = r / 100;
	r = r % 100;
	//3. 2에서 나온 나머지인 r을 50으로 나눈 몫을 n50, 나머지를 r에 저장한다.
	result.n50 = r / 50;
	r = r % 50;
	//4. 3에서 나온 나머지인 r을 10으로 나눈 몫을 n10에 저장한다.
	result.n10 = r / 10;

	//5. 구조체를 통해 n500, n100, n50, n10을 반환 받는다.
	return result;
}

void printChange()
{
	int fChange = 730;
	struct Ncoins fResult = calCoins(fChange);
	printf("거스름돈 500원 %d, 100원 %d, 50원 %d 개, 10원 %d 개 입니다\n", fResult.n500, fResult.n100,fResult.n50, fResult.n10);
}