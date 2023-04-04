
#include <stdio.h>

int euclidRepeatitive(int a, int b)
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

int euclidRecursive(int a, int b)
{
	if (b == 0)
		return a;
	else
		return euclidRecursive(b, a % b);
}