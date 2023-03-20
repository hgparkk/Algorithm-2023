
#include <stdio.h>

int Euclid(int a, int b) 
{
	if (a < b)
		return 0;
	int basv;
	while (b != 0) 
	{
		basv = b;
		b = a % b;
		a = basv;
	}
	return a;
}

int main()
{
	int a = Euclid(48, 34);
	printf("%d\n", a);
	return 0;
}