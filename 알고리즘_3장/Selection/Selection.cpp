/*
파일 이름: Selection.cpp
설명 : 선택문제 알고리즘
작성자 : 박현규
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int Selection(int* A, int left, int right, int k)
{
    //가장 왼쪽 원소의 인덱스가 가장 오른쪽 원소의 인덱스보다 작으면 다음을 단계를 실행한다.(가장 왼쪽의 원소가 가장 오른쪽의 원소보다 크거나 같으면 원소가 1개임으로 그 자체가 정렬된 것이기 때문이다.)
    if (left < right)
    {
        //A[left]와 A[right] 사이에서 피봇을 선택하고 A[left]와 피봇의 위치를 바꾼다.
        srand(time(NULL));
        int pivot = rand() % (right - left) + left;
        swap(&A[left], &A[pivot]);
        int L = left + 1;
        int R = right;
        int p = left + 1;
        //피봇보다 작은 값을 A[left]~A[p-1], 피봇보다 큰 값을 A[p]~A[right]로 옮긴다.
        while (L <= R)
        {
            L = left + 1;
            R = right;
            while (L <= right && A[L] < A[left])
            {
                L++;
            }
            while (R >= left && A[R] > A[left])
            {
                R--;
            }
            if (L < R)
                swap(&A[L], &A[R]);
        }
        //피봇을 A[p]로 옮긴다.
        while (p <= right && A[p] < A[left])
        {
            p++;
        }
        p--;
        swap(&A[left], &A[p]);
        //피봇보다 작은 그룹의 크기를 알아낸다.
        int S = (p - 1) - left + 1;
        // 피봇보다 작은 그룹의 크기보다 k가 작으면 작은 그룹을 탐색한다.
        if (k <= S)
            return Selection(A, left, p - 1, k);
        //피봇보다 작은 그룹의 크기가 k-1이라면 피봇을 반환한다.
        else if (k == S + 1)
            return A[p];
        //피봇보다 작은 그룹의 크기가 k보다 크다면 큰 그룹을 탐색한다.
        else
            return Selection(A, p + 1, right, k - S - 1);
    }
}

// 임의의 숫자들의 집합 데이터 "data.txt"를 읽는다.
int* fileRead()
{
    int size = 0;
    int i = 0;
    int* data;
    int tmp;
    FILE* fp = fopen("data.txt", "r");
    if (fp == NULL)
    {
        printf("fail to open file\n");
    }
    else
    {
        while (!feof(fp))
        {
            fscanf(fp, "%d\n", &tmp);
            size++;
        }
        data = (int*)malloc(sizeof(int) * size);
        fp = fopen("data.txt", "r");
        while (!feof(fp))
        {
            fscanf(fp, "%d\n", &data[i]);
            i++;
        }
        fclose(fp);
    }
    return data;
}

//실행된 결과를 "result.txt"에 출력한다.
void fileWrite(int k, int selection)
{
    FILE* fp = fopen("result.txt", "w");
    if (fp == NULL)
    {
        printf("fail to open file\n");
    }
    else
    {
        fprintf(fp, "%d 번째 작은 원소는 %d 입니다.\n", k, selection);
        fclose(fp);
    }
}
int main() {
    int* data = fileRead();
    int size = _msize(data) / sizeof(int);
    int k = 5;
    int selection = Selection(data, 0, size-1, k);
    fileWrite(k, selection);
}