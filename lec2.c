#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    // check the number of processes created.
    fork();
    fork();
    fork();
    fork();

    printf("Hello world!!\n");

    return 0;
}