#include<stdio.h> 
#include<conio.h>
#include<Windows.h> 
void gotoxy(int x, int y);
int main(void)
{
	system("cls");
	gotoxy(4, 4);
	putchar('A');
	gotoxy(2, 2);
	printf("□");
	_getch();
	return 0;
}
void gotoxy(int x, int y)
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}