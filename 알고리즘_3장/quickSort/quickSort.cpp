
#include <stdio.h>
#define SIZE 8

void quickSort(int A[], int left, int right)
{
    int pivot;
    int low = left;
    int high = right + 1;
    pivot = A[left];
}

void printArray(int A[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", A[i]);
}

int main() {
    int A[SIZE] = { 37,10,22,30,35,13,25,24 };
    printArray(A, SIZE);
}