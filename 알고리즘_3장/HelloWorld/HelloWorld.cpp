
#include <stdio.h>
#include <conio.h>

int main(int argc, char * argv[])
{
    printf("Hello, World!\n");

    for (int i = 0; i < argc; i++)
        printf("%s ", argv[i]);
    _getch();
    return 0;
}