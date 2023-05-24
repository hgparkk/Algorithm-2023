
#include <stdio.h>
#include <stdlib.h>
#define alph_num 26

// 임의의 숫자들의 집합 데이터 "input.txt"를 읽는다.
char* fileRead()
{
    int size = 0;
    int i = 0;
    char* data;
    char tmp;
    FILE* fp = fopen("input.txt", "r");
    if (fp == NULL)
    {
        printf("fail to open file\n");
    }
    else
    {
        while (!feof(fp))
        {
            tmp = fgetc(fp);
            size++;
        }
        data = (char*)malloc(sizeof(char) * size);
        fp = fopen("input.txt", "r");
        while (!feof(fp))
        {
            tmp = fgetc(fp);
            if (tmp >= 'a' && tmp <= 'z')
            {
                tmp = tmp - 'a' + 'A';
                data[i++] = tmp;
            }
            else if (tmp >= 'A' && tmp <= 'Z')
            {
                data[i++] = tmp;
            }
        }
        fclose(fp);
    }
    return data;
}

//데이터를 "stats.txt"에 복사한다.
void fileWrite(char* record, int* fre)
{
    int size = _msize(record) / sizeof(char);
    FILE* fp = fopen("stats.txt", "w");
    if (fp == NULL)
    {
        printf("fail to open file\n");
    }
    else
    {
        for (int i = 0; i < size; i++)
        {
            fprintf(fp, "%c\t%d\n", record[i],fre[i]);
        }
        fclose(fp);
    }
}

int* countfre(char* arr)
{
    int i = 0;
    int* fre=(int*)malloc(sizeof(int)*alph_num);
    while (arr[i] != NULL)
    {
        //빈도수 구하기
        fre[arr[i] - 'A']++;
        printf("%d\n", arr[i] - 'A');
        i++;
    }
    return fre;
}

int main()
{
    char* fp = fileRead();
    char record[alph_num];
    for (int i = 0, a = 'A'; i < alph_num; i++)
    {
        record[i] = a++;
    }
    int* fre= countfre(fp);
    printf("%c, %d", record[1], fre[1]);
    //fileWrite(record, fre);

}
