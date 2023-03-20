#include <stdio.h>
#include <stdlib.h>

int searchK(int NumArray[], int count, int K);
void testSearchK();

int main()
{
	testSearchK();
}

int searchK(int NumArray[],int count, int K)
{
	//1. result 에 초기 값 -1을 저장 한다
	int result = -1;

	//2. 첫 번째 숫자를 읽어 찾고자 하는 숫자 K와 비교하여 같으면 result를 그 숫자로 갱신한다.
	//3. 남은 숫자에 대해 2를 반복한다.
	for (int i = 0; i < count; i++)
	{
		if (NumArray[i] == K)
		{
			result = K;
			break;
		}
	}

	//4. 찾고자 하는 수 result를 반환한다.
	return result;
}

void testSearchK()
{
	int A[] = { 45, 20, 60, 35, 10, 55, 90, 85, 75, 25 };
	int fvalue = 85;
	int xresult = -1;

	xresult = searchK(A, sizeof(A) / sizeof(int),fvalue);
	if (xresult == fvalue) {
		printf("%d 값을 찾았습니다. %d\n", fvalue, xresult);
	}
	else {
		printf("%d 값을 찾지 못하였습니다. %d\n", fvalue, xresult);
	}
}