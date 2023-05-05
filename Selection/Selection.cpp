
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 8

void printArray(int A[], int size);

void swap(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int Selection(int A[], int left, int right, int k)
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

void printArray(int A[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

int main() {
    int A[SIZE] = { 30,50,16,14,211,21,35,18 };
    int k = 5;
    int selection = Selection(A, 0, SIZE-1, k);
    printf("%d 번째 작은 원소는 %d 입니다", k, selection);
}