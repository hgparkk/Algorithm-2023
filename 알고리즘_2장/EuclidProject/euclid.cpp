
#include <stdio.h>

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

long long euclidRecursive(long long a, long long b)
{
	if (b == 0)
		return a;
	else
		return euclidRecursive(b, a % b);
}