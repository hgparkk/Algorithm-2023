/*
프로그램 내용 : 랜덤하게 생성된 값을 배열에 넣고 최댓값을 찾는 프로그램
실습일 : 2023.03.07
실습자 : 박현규
학번 : 202111678
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ELEMENTS 50000

int find_max_score(int score[], int n) {
    int i, tmp;
    tmp = score[0];
    for (i = 1; i < n; i++) {
        if (score[i] > tmp) {
            tmp = score[i];
        }
    }
    return tmp;
}

int main(void)
{
    int score[MAX_ELEMENTS] = { 100,23,300 };
    int i, res;
    long seed;

    seed = time(NULL);
    srand(seed);
    for (i = 0; i < MAX_ELEMENTS; i++) {
        score[i] = rand();
    }
    res = find_max_score(score, MAX_ELEMENTS);
    printf("Max number = %d \n", res);
    return 0;
}