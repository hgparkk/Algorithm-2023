#include <stdio.h>

int Euclid(int a, int b)
{
	if (b == 0)
		return a;
	else
		return Euclid(b, a % b);
}

int test1_euclid()
{
	int a = Euclid(48, 34);
	printf("%d\n", a);
	return 0;
}

int main()
{
	test1_euclid();
}