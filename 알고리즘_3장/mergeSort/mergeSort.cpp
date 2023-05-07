
#include <stdio.h>
#include <stdlib.h>

//분할된 배열을 정렬하며 합병한다.
void merge(int* A, int p,int k, int q) 
{
    int size = _msize(A) / sizeof(int);
    int* C = (int*)malloc(sizeof(int)*size);
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

//배열을 분할한다.
void mergeSort(int* A, int p, int q)
{
    // 정렬할 부분의 원소의 수가 2개 이상힐 때 다음 단계를 수행한다. (원소 수가 1개라면 그 자체로 정렬된 것이기 때문)
    if(p<q)
    {
        //정렬할 부분의 원소들을 1/2로 나누기 위해 k를 계산한다. (원소의 수가 홀수인 경우, k는 소수점 이하를 버린 정수이다.)
        int k = (p + q) / 2;
        //k의 앞부분을 순환 호출한다.
        mergeSort(A, p, k);
        //k의 뒷부분을 순환 호출한다.
        mergeSort(A, k + 1, q);
        //3,4에서 각각 정렬된 부분을 합병한다.
        merge(A, p, k, q);
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
    int size = _msize(data)/sizeof(int);
    mergeSort(data, 0, size - 1);
    fileWrite(data);
}