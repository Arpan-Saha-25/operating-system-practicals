#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *args[])
{

    char str1[100] = "ls -l ";
    char str2[50];

    strcpy(str2, args[1]);
    strcat(str1, str2);
    puts(str1);

    system(str1);

    return 0;
}
