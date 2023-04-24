
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 8

void quickSort(int A[], int left, int right)
{
    int pivot;
    int low = left;
    int high = right;
    long seed = time(NULL);
    srand(seed);
    pivot = rand() % (right - left);
    int p = A[pivot];
    int zero = A[left];
    A[left] = p;
    A[pivot] = zero;

    for (int i = 1; i < right - left; i++)
    {
        int tmp = A[i];
        if (tmp < p)
        {

            A[i] = tmp;
        }
        else if (tmp > p)
        {
            A[p + 1] = tmp;
        }
    }
}

void printArray(int A[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", A[i]);
}

int main() {
    int A[SIZE] = { 37,10,22,30,35,13,25,24 };
    printArray(A, SIZE);
}