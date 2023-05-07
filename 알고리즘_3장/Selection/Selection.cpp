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
    if (left < right)
    {
        srand(time(NULL));
        int pivot = rand() % (right - left) + left;
        swap(&A[left], &A[pivot]);
        int L = left + 1;
        int R = right;
        int p = left + 1;
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
        while (p <= right && A[p] < A[left])
        {
            p++;
        }
        p--;
        swap(&A[left], &A[p]);
        int S = (p - 1) - left + 1;
        if (k <= S)
            return Selection(A, left, p - 1, k);
        else if (k == S + 1)
            return A[p];
        else
            return Selection(A, p + 1, right, k - S - 1);
    }
}

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