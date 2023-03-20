#include <stdio.h>
#include <stdlib.h>

int searchK(int K);
void testSearchK();

int main()
{
	testSearchK();
}

int searchK(int K)
{
	int A[10] = { 5,7,3,0,80,95,42,31,23,15 };
	int ret = -1;

	for (int i = 0; i < 10; i++)
	{
		if (A[i] == K)
		{
			ret = K;
			break;
		}
	}

	return ret;
}

void testSearchK()
{
	int fval = 15;
	int xret = -2;

	xret = searchK(fval);
	if (xret == fval) {
		printf("%d 값을 찾았습니다. %d\n", fval, xret);
	}
	else {
		printf("%d 값을 찾지 못하였습니다. %d\n", fval, xret);
	}
}