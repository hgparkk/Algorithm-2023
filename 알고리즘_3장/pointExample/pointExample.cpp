#include <stdio.h>

typedef struct point 
{
	int x;
	int y;
	int z;
}Point;

Point myPoint[10] = { {0,0,0} };
Point yourPoint[] = { {1,2,3},{1,2,3} };

Point sum(Point argPoints[], int size)
{
	Point result = { 0,0,0 };

	for (int i = 0; i < size; i++) 
	{
		result.x += argPoints[i].x;
		result.y += argPoints[i].y;
		result.z += argPoints[i].z;
	}

	return result;
}

int main(void)
{
	int size = sizeof(yourPoint) / sizeof(yourPoint[0]);
	Point s = sum(yourPoint, size);
}