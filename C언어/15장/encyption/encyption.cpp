﻿
#include <stdio.h>
#include <stdlib.h>
#define SIZE 10000

char* key = "0123456789";

int main(void)
{
	char name[256], name1[256];
	char p[SIZE];
	printf("입력 파일 이름: ");
	scanf("%s", name);
	printf("출력 파일 이름: ");
	scanf("%s", name1);
	FILE* f1 = fopen(name, "r+b");
	FILE* f2 = fopen(name1, "w+b");

	int length = fread(p, sizeof(char), 10000, f1);
	for (unsigned long i = 0; i < length; i++) 
	{
		p[i] ^= key[i % 10];
	}
	fwrite(p, sizeof(char), length, f2);
	fclose(f1);
	fclose(f2);
	return 0;
}