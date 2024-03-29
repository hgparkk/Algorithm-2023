﻿#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
	int lower_case_count = 0;
	int upper_case_count = 0;
	int digit_count = 0;
	char pass[100];
	int len;
	printf("패스워드를 입력하시오: ");
	gets_s(pass, sizeof(pass));
		len = strlen(pass);
	if (len < 7) 
	{
		printf("유효한 암호가 아닙니다. \n");
		exit(1);
	}
	for (int i = 0; i < len; i++) 
	{
		if (islower(pass[i])) ++lower_case_count;
		if (isupper(pass[i])) ++upper_case_count;
		if (isdigit(pass[i])) ++digit_count;
	}
	if (lower_case_count > 0 && upper_case_count > 0 && digit_count > 0)
		printf("강한 암호입니다. \n");
	else
		printf("유효한 암호가 아닙니다\n");
	return 0;
}