
#include <stdio.h>
#include "euclid.h"


int testEuclid()
{
	int a = euclidRecursive(48, 34);
	printf("%d 와 %d의 최대공약수는 %d입니다.\n", 48, 34, a);
	return 0;
}
