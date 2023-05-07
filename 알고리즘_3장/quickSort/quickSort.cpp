
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
    if (left < right) 
    {
        srand(time(NULL));
        int pivot = rand() % (right - left)+left;
        swap(&A[left], &A[pivot]);
        int L = left + 1;
        int R = right;
        int p = left + 1;
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
        while (p<=right && A[p] < A[left])
        {
            p++;
        }
        p--;
        swap(&A[left], &A[p]);
        quickSort(A, left, p - 1);
        quickSort(A, p + 1, right);
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