
#include <stdio.h>

int Euclid(int a, int b)
{
	if (b == 0)
		return a;
	else
		return Euclid(b, a % b);
}

int main()
{
	int a = Euclid(24, 14);
	printf("%d\n", a);
	return 0;
}