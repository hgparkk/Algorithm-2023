
#include <stdio.h>
#define SIZE 8
int tmp[SIZE];

void merge(int A[], int p, int q) 
{
    int C[SIZE];
    int k = (p + q) / 2;
    int ai = p;
    int bi = k+1;
    int ci = 0;
    while (ci <= (q - p + 1))
    {
        if (A[ai] < A[bi])
            C[ci++] = A[ai++];
        else
            C[ci++] = A[bi++];
    }
    ci = 0;
    ai = p;
    while (ai <= (q - p + 1))
        A[ai++] = C[ci++];
}

void mergeSort(int A[], int p, int q)
{
    if 
        (p == q) return;
    else
    {
        int k = (p + q) / 2;
        mergeSort(A, p, k);
        mergeSort(A, k + 1, q);
        merge(A, p, q);
    }
}

void printArray(int A[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", A[i]);
}

int main() {
    int A[SIZE] = { 37,10,22,30,35,13,25,24 };
    mergeSort(A, 0, SIZE - 1);
    printArray(A, SIZE);
}