
#include <stdio.h>
#define SIZE 12

void merge(int A[], int p,int k, int q) 
{
    int C[SIZE];
    int ai = p;
    int bi = k+1;
    int ci = 0;
    while (ai <= k && bi <= q)
    {
        if (A[ai] <= A[bi])
            C[ci++] = A[ai++];
        else
            C[ci++] = A[bi++];
    }
    while (ai <= k)
        C[ci++] = A[ai++];
    while (bi <= q)
        C[ci++] = A[bi++];
    ci--;

    while (ci >= 0)
    {
        A[p + ci] = C[ci];
        ci--;
    }
}

void mergeSort(int A[], int p, int q)
{
    if(p<q)
    {
        int k = (p + q) / 2;
        printf("%d, %d\n", A[p], A[q]);
        mergeSort(A, p, k);
        mergeSort(A, k + 1, q);
        merge(A, p, k, q);
    }
}

void printArray(int A[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", A[i]);
}

int main() {
    int A[SIZE] = { 6,3,11,9,12,2,8,15,18,10,7,14 };
    mergeSort(A, 0, SIZE - 1);
    printArray(A, SIZE);
}