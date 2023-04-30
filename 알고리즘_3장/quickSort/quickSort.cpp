
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 8

void printArray(int A[],int size);

void quickSort(int A[], int left, int right)
{
    printArray(A, SIZE);
    int low = left + 1;
    int high = right;
    long seed = time(NULL);
    srand(seed);
    int pivot = rand() % (right - left)+left;
    int p = A[pivot];
    int zero = A[left];
    A[left] = p;
    A[pivot] = zero;
    if (left < right)
    {
        while (low <= high)
        {
            while (low <= right && A[low] <= p)
            {
                low++;
            }
            while (high > left && A[high] >= p)
            {
                high--;
            }
            printf("%d, %d\n", low, high);
            if (low > high)
            {
                int tmp = A[high];
                A[high] = A[low];
                A[low] = tmp;
            }
            else
            {
                int tmp = A[low];
                A[low] = A[high];
                A[high] = tmp;
            }
            printArray(A, SIZE);
        }
        printArray(A, SIZE);
        printf("%d\n", pivot);
        quickSort(A, left, pivot - 1);
        quickSort(A, pivot + 1, right);
    }
    else return;
}

void printArray(int A[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

int main() {
    int A[SIZE] = { 37,10,22,30,35,13,25,24 };
    quickSort(A, 0, SIZE);
    printArray(A, SIZE);
}