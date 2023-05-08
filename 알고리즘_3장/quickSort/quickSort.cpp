/*
파일 이름: quickSort.cpp
설명 : 퀵정렬 알고리즘
작성자 : 박현규
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b) 
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void quickSort(int* A, int left, int right)
{
    //가장 왼쪽 원소의 인덱스가 가장 오른쪽 원소의 인덱스보다 작으면 다음을 단계를 실행한다.(가장 왼쪽의 원소가 가장 오른쪽의 원소보다 크거나 같으면 원소가 1개임으로 그 자체가 정렬된 것이기 때문이다.)
    if (left < right) 
    {
        //A[left]와 A[right] 사이에서 피봇을 선택하고 A[left]와 피봇의 위치를 바꾼다
        srand(time(NULL));
        int pivot = rand() % (right - left)+left;
        swap(&A[left], &A[pivot]);
        int L = left + 1;
        int R = right;
        int p = left + 1;
        //피봇보다 작은 값을 A[left]~A[p-1], 피봇보다 큰 값을 A[p]~A[right]로 옮긴다.
        while (L<=R)
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
            if (L<R)
                swap(&A[L], &A[R]);
        }
        //피봇을 A[p]로 옮긴다.
        while (p<=right && A[p] < A[left])
        {
            p++;
        }
        p--;
        swap(&A[left], &A[p]);
        //피봇보다 작은 숫자들을 퀵정렬한다.
        quickSort(A, left, p - 1);
        //피봇보다 큰 숫자들을 퀵정렬한다.
        quickSort(A, p + 1, right);
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

//데이터를 "result.txt"에 복사한다.
void fileWrite(int* data)
{
    int size = _msize(data) / sizeof(int);
    FILE* fp = fopen("result.txt", "w");
    if (fp == NULL)
    {
        printf("fail to open file\n");
    }
    else
    {
        for (int i = 0; i < size; i++)
        {
            fprintf(fp, "%d\n", data[i]);
        }
        fclose(fp);
    }
}

int main() {
    int* data = fileRead();
    int size = _msize(data) / sizeof(int);
    quickSort(data, 0, size-1);
    fileWrite(data);
}