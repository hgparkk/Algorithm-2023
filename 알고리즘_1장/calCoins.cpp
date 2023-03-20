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
	int n10;
};

struct Ncoins calCoins(int change)
{
	struct Ncoins result;
	result.n500 = change / 500;
	int r = change % 500;
	result.n100 = r / 100;
	r = r % 100;
	result.n10 = r / 10;

	return result;
}

void printChange()
{
	int fChange = 730;
	struct Ncoins fResult = calCoins(fChange);
	fResult = calCoins(fChange);
	printf("거스름돈 500원 %d, 100원 %d, 10원 %d 개 입니다\n", fResult.n500, fResult.n100, fResult.n10);
}